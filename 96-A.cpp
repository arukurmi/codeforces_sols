// Approach: Check if the input string contains "0000000" or "1111111" as a substring.
// If yes → dangerous (YES), else → not dangerous (NO).
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (s.find("0000000") != string::npos || s.find("1111111") != string::npos)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
