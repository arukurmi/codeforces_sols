// Approach: Find position (i, j) of '1' in the 5x5 matrix. 
// The target position is (3, 3). The minimum moves = |3 - i| + |3 - j|.  
// This is simply the Manhattan distance to the center.

// Time Complexity: O(1)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            int val;
            cin >> val;
            if (val == 1) {
                x = i;
                y = j;
            }
        }
    }
    cout << abs(3 - x) + abs(3 - y) << '\n';
    return 0;
}
