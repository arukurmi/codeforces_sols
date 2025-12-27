// Approach: Start x = 0; for each statement, increment if it has "++", else decrement.
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

    int x = 0;
    while (n--) {
        string s;
        cin >> s;

        // Check if statement contains "++"
        if (s.find("++") != string::npos) 
            ++x;
        else 
            --x;
    }

    cout << x << "\n";
    return 0;
}
