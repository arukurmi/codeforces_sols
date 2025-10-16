// Approach:
// - Count the number of rooms where available space >= 2.
// - Iterate through each room's current occupancy and capacity.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2) count++; // room can fit both George and Alex
    }

    cout << count;
    return 0;
}
