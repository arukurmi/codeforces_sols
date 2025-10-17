// Approach: Sum all x, y, z components; if all sums == 0, body is in equilibrium.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int xSum = 0, ySum = 0, zSum = 0;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        xSum += x;
        ySum += y;
        zSum += z;
    }

    if (xSum == 0 && ySum == 0 && zSum == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
