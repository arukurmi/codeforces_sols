#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int bal = 0, low = 0, cut = 0;
        for (int i = 0; i < n; i++) {
            bal += s[i] == '(' ? 1 : -1;
            if (bal <= low) {
                low = bal;
                cut = i + 1;
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if ((i < cut && s[i] == '(') || (i >= cut && s[i] == ')'))
                total++;
        }

        int budget = min(k, total);
        string res(n, '0');
        int used = 0;
        for (int i = 0; i < n && used < budget; i++) {
            if ((i < cut && s[i] == '(') || (i >= cut && s[i] == ')')) {
                res[i] = '1';
                used++;
            }
        }

        cout << res << '\n';
    }
    return 0;
}
