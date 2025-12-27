// Approach:
// 1. For every position i mod k, all characters in s[i], s[i+k], s[i+2k], ... must be identical
//    (either all 0s or all 1s). Otherwise, no valid k-balanced string can exist.
// 2. Propagate known 0s/1s across these positions to fill '?' accordingly.
// 3. After propagation, check the first k characters: count number of 0s and 1s.
//    -> if count(0) > k/2 or count(1) > k/2 → impossible (since each window must have equal 0s and 1s).
// 4. If both counts ≤ k/2, print YES (possible), else NO.

// Time Complexity: O(n) per test case
// Space Complexity: O(k)

#include <bits/stdc++.h>
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

        vector<char> mod(k, '?');
        bool ok = true;

        // Step 1: Propagate fixed bits within each modulo group
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') continue;
            int pos = i % k;
            if (mod[pos] == '?') mod[pos] = s[i];
            else if (mod[pos] != s[i]) ok = false;
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        // Step 2: Count 0s and 1s in the k-pattern
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < k; ++i) {
            if (mod[i] == '0') cnt0++;
            else if (mod[i] == '1') cnt1++;
        }

        // Step 3: Check balance constraint
        if (cnt0 > k / 2 || cnt1 > k / 2) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
