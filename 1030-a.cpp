// Approach: Check if any input is '1'; if found, print "HARD", else "EASY".
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Fast I/O
    cin.tie(nullptr);

    int n;
    cin >> n;
    bool hard = false;

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x == 1) hard = true;
    }

    cout << (hard ? "HARD" : "EASY");
    return 0;
}
