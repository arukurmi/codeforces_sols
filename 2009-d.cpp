#include <bits/stdc++.h>
using namespace std;

// Approach:
// 1. Separate points into two groups by y (0 or 1).
// 2. For each x appearing in both y=0 and y=1 (vertical alignment),
//    count triangles = (count_y0 - 1) * (count_y1 - 1).
// 3. Sum this over all such x.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x0, x1;
        unordered_set<int> s0, s1;

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (y == 0) {
                x0.push_back(x);
                s0.insert(x);
            } else {
                x1.push_back(x);
                s1.insert(x);
            }
        }

        long long ans = 0;
        for (int x : s0) {
            if (s1.count(x)) {
                ans += (long long)(s0.size() - 1) * (s1.size() - 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
