// Approach:
// - You can merge equal powers of two, effectively summing all numbers ≤ 2048.
// - If the total sum of all numbers ≤ 2048 is at least 2048, print "YES", else "NO".

// Time Complexity: O(n) per query
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            if (x <= 2048) sum += x;
        }
        cout << (sum >= 2048 ? "YES" : "NO") << '\n';
    }
    return 0;
}
