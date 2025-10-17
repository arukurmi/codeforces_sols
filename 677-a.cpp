// Approach:
// - Each friend with height <= h takes width 1.
// - Each friend with height > h must bend, taking width 2.
// - Sum up widths accordingly.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;  // n = number of friends, h = height of fence

    int width = 0;  // total required width of the road

    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;           // height of i-th friend
        if (ai > h) width += 2;  // friend bends
        else width += 1;         // friend walks normally
    }

    cout << width;
    return 0;
}
