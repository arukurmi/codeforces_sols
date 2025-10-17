// Approach: Count uppercase and lowercase letters; convert entire word to lowercase if lowercase >= uppercase, else to uppercase.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int upper = 0, lower = 0;
    for (char c : s) {
        if (isupper(c)) upper++;
        else lower++;
    }

    if (lower >= upper) {
        for (char &c : s) c = tolower(c);
    } else {
        for (char &c : s) c = toupper(c);
    }

    cout << s;
    return 0;
}
