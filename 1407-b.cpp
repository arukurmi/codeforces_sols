// Approach:
// 1. Start with the largest element as b1 (maximizes first GCD value).
// 2. Repeatedly pick the element from remaining numbers that gives the largest GCD with the current gcd_so_far.
// 3. Continue until all numbers are used — ensures lexicographically maximal GCD sequence.

// Time Complexity: O(n^2 * log(max(a[i])))
// Space Complexity: O(n)

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

        vector<int> b;
        vector<bool> used(n, false);
        int max_val = *max_element(a.begin(), a.end());
        int gcd_now = max_val;

        // Add the largest element first
        int idx = max_element(a.begin(), a.end()) - a.begin();
        b.push_back(a[idx]);
        used[idx] = true;

        // Build sequence
        for (int step = 1; step < n; ++step) {
            int best_gcd = 0, best_idx = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    int g = gcd(gcd_now, a[i]);
                    if (g > best_gcd) {
                        best_gcd = g;
                        best_idx = i;
                    }
                }
            }
            gcd_now = best_gcd;
            used[best_idx] = true;
            b.push_back(a[best_idx]);
        }

        for (int i = 0; i < n; ++i) {
            cout << b[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
