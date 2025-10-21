// Approach:
// - We only care about the absolute difference |a - b|.
// - Use the largest possible button presses first: 5, then 2, then 1.
// - Greedy works perfectly since all buttons are multiples of each other.

// Time Complexity: O(1) per test case
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long diff = abs(a - b);
        long long presses = 0;

        presses += diff / 5;  // use ±5 buttons
        diff %= 5;
        presses += diff / 2;  // use ±2 buttons
        diff %= 2;
        presses += diff;      // use ±1 buttons

        cout << presses << '\n';
    }
    return 0;
}
