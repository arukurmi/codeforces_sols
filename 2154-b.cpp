#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<long long> a(n), pref(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pref[i] = (i ? max(pref[i-1], a[i]) : a[i]);
        }

        long long ans = 0;
        // odd 1-based positions => 0-based even indices: 0,2,4,...
        for (int i = 0; i < n; i += 2) {
            long long lim;
            if (i == 0) {
                // must have a[0] < peak at 1 (can raise a[1] to pref[1])
                lim = (n >= 2 ? pref[1] - 1 : (long long)4e18); // n>=2 per constraints
            } else if (i == n - 1) {
                // last odd position (only when n is odd): a[n-1] < peak at n-2
                lim = pref[n - 2] - 1;
            } else {
                // internal valley: below both neighbors' achievable peaks
                lim = min(pref[i - 1], pref[i + 1]) - 1;
            }
            if (a[i] > lim) ans += (a[i] - lim);
        }
        cout << ans << '\n';
    }
    return 0;
}
