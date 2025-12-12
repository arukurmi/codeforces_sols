import time
from playwright.sync_api import sync_playwright

URL = "https://help.furlenco.com/views/add-ticket.php"

TICKETS = [
    {
        "cust_name": "Aryansh Kurmi",
        "email": "arukurmi22@gmail.com",
        "subject": "No response from support – urgent help needed",
        "description": "Tried calling multiple times but no response. Please contact ASAP.",
        "contact": "6377080740",
    },
    # Add more dicts here for more tickets
]

def wait_dropdown_has_options(frame_locator, selector: str, min_options: int = 2, timeout_ms: int = 15000):
    """
    Wait until <select> has at least `min_options` options.
    min_options=2 means: placeholder + at least 1 real option.
    """
    start = time.time()
    while True:
        count = frame_locator.locator(f"{selector} option").count()
        if count >= min_options:
            return
        if (time.time() - start) * 1000 > timeout_ms:
            raise TimeoutError(f"Timeout waiting for options in {selector}. Current option count: {count}")
        time.sleep(0.25)

def select_first_real_option(frame_locator, selector: str):
    """
    Select the first non-empty option value.
    """
    # Get all option values
    options = frame_locator.locator(f"{selector} option")
    n = options.count()

    chosen_value = None
    for i in range(n):
        val = options.nth(i).get_attribute("value") or ""
        val = val.strip()
        if val:  # skip placeholder with empty value
            chosen_value = val
            break

    if not chosen_value:
        raise RuntimeError(f"No selectable option found for {selector}")

    frame_locator.locator(selector).select_option(value=chosen_value)
    return chosen_value

def run():
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=False)
        context = browser.new_context()
        page = context.new_page()

        page.goto(URL, wait_until="networkidle")

        # Form is inside iframe#scrl
        frame = page.frame_locator("iframe#scrl")

        for idx, t in enumerate(TICKETS, start=1):
            print(f"Submitting ticket #{idx}")

            # Fill text inputs
            frame.locator("#cust_name").fill(t["cust_name"])
            frame.locator("#email").fill(t["email"])

            # Service type options load dynamically
            wait_dropdown_has_options(frame, "#service_type", min_options=2)
            service_val = select_first_real_option(frame, "#service_type")
            print(f"Selected service_type value: {service_val}")

            # Issue type depends on service type
            wait_dropdown_has_options(frame, "#issue_type", min_options=2)
            issue_val = select_first_real_option(frame, "#issue_type")
            print(f"Selected issue_type value: {issue_val}")

            frame.locator("#subject").fill(t["subject"])
            frame.locator("#description").fill(t["description"])
            frame.locator("#contact").fill(t["contact"])

            # Submit
            frame.locator("#submit").click()

            # Wait a bit for submit to process
            time.sleep(6)

            # Reload for next ticket (optional)
            if idx < len(TICKETS):
                page.reload(wait_until="networkidle")
                time.sleep(2)

        browser.close()
        print("Done.")

if __name__ == "__main__":
    run()
