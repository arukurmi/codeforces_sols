#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int sum = accumulate(a.begin(), a.end(), 0);

        // Case 1: all zeros → impossible
        if (sum == 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // Case 2: total sum > 0 → sort descending
        // Case 3: total sum < 0 → sort ascending
        if (sum > 0)
            sort(a.rbegin(), a.rend());
        else
            sort(a.begin(), a.end());

        for (int x : a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
