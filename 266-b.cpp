// Approach:
// - Simulate the queue for t seconds.
// - In each second, scan the queue from left to right.
//   If 'B' is immediately followed by 'G', swap them.
// - Repeat for t seconds to get the final arrangement.
// Time Complexity: O(n * t)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    while (t--) {
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++; // skip next index to avoid double swap
            }
        }
    }

    cout << s;
    return 0;
}
