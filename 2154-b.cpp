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
        for (int i = 0; i < n; i += 2) {
            long long lim;
            if (i == 0) {
                lim = (n >= 2 ? pref[1] - 1 : (long long)4e18); // n>=2 per constraints
            } else if (i == n - 1) {
                lim = pref[n - 2] - 1;
            } else {
                lim = min(pref[i - 1], pref[i + 1]) - 1;
            }
            if (a[i] > lim) ans += (a[i] - lim);
        }
        cout << ans << '\n';
    }
    return 0;
}
