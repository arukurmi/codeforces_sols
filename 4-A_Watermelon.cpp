// Approach: If w is even and greater than 2, it can be split into two even parts; otherwise, not possible.
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

int32_t main() {
    fastio;

    int w;
    cin >> w;

    // Check if the weight is even and greater than 2 (smallest even > 2 is 4, i.e., 2+2)
    if (w % 2 == 0 && w > 2) 
        cout << "YES\n";
    else 
        cout << "NO\n";

    return 0;
}
