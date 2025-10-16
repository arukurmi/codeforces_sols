// Approach: Reverse the first string `s` and compare it with the second string `t`.
// If they are equal → print "YES", else → print "NO".
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    reverse(s.begin(), s.end());  // Reverse string s

    if (s == t)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
