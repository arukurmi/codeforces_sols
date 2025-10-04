// Approach: Compute how many flagstones fit along length and width using ceiling division: ceil(n/a) * ceil(m/a).
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

int32_t main() {
    fastio;

    long long n, m, a;
    cin >> n >> m >> a;

    // Ceiling division for each dimension
    long long tiles_length = (n + a - 1) / a;
    long long tiles_width  = (m + a - 1) / a;

    cout << tiles_length * tiles_width << "\n";
    return 0;
}
