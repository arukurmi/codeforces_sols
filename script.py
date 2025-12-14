import time
from playwright.sync_api import sync_playwright

URL = "https://help.furlenco.com/views/add-ticket.php"

TICKETS = [
    {
        "cust_name": "Aryansh Kurmi",
        "email": "arukurmi22@gmail.com",
        "service_type_label": "Order Related",
        "issue_type_label": "Delivery Delay",
        "subject": "No response from support – order issue",
        "description": (
            "I have tried calling customer support multiple times but no one is responding. "
            "Raising this ticket again as there has been no callback."
        ),
        "contact": "6377080740",
    },
    {
        "cust_name": "Aryansh Kurmi",
        "email": "arukurmi22@gmail.com",
        "service_type_label": "Order Related",
        "issue_type_label": "Customer Support",
        "subject": "Repeated follow-up – no response from Furlenco",
        "description": (
            "This is a follow-up ticket. No response on calls or previous ticket. "
            "Please contact urgently."
        ),
        "contact": "6377080740",
    },
]

def run():
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=False)  # keep false for visibility
        context = browser.new_context()
        page = context.new_page()

        page.goto(URL, wait_until="networkidle")

        # The form is inside an iframe
        iframe = page.frame_locator("iframe")

        for idx, t in enumerate(TICKETS, start=1):
            print(f"Submitting ticket #{idx}")

            iframe.locator("#cust_name").fill(t["cust_name"])
            iframe.locator("#email").fill(t["email"])

            iframe.locator('select[name="service_type"]').select_option(
                label=t["service_type_label"]
            )
            iframe.locator('select[name="issue_type"]').select_option(
                label=t["issue_type_label"]
            )

            iframe.locator("#subject").fill(t["subject"])
            iframe.locator("#description").fill(t["description"])
            iframe.locator("#contact").fill(t["contact"])

            iframe.locator("#submit").click()

            # wait after submit (adjust if success message appears)
            time.sleep(5)

            # reload page for next ticket
            page.reload(wait_until="networkidle")
            time.sleep(4)

        browser.close()


if __name__ == "__main__":
    run()
