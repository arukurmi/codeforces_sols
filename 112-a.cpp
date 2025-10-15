// Approach: Convert both strings to lowercase and compare lexicographically.
// Return -1 if s1 < s2, 1 if s1 > s2, else 0.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    for (auto &ch : a) ch = tolower(ch);
    for (auto &ch : b) ch = tolower(ch);

    if (a < b) cout << -1;
    else if (a > b) cout << 1;
    else cout << 0;

    cout << '\n';
    return 0;
}
