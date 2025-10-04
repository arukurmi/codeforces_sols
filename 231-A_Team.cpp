// Approach: Count how many problems have at least two friends sure (sum of 3 inputs ≥ 2).
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

int32_t main() {
    fastio;

    int n; 
    cin >> n;

    int count = 0; // number of problems they will implement

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b + c >= 2) // at least two sure
            count++;
    }

    cout << count << "\n";
    return 0;
}
