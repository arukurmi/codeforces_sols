// Approach: For each word, if its length > 10, abbreviate as first_char + (len-2) + last_char; else print as is.
// Time Complexity: O(n * L) where L is max word length (<=100)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

int32_t main() {
    fastio;

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if ((int)s.size() > 10) {
            cout << s.front() << s.size() - 2 << s.back() << "\n";
        } else {
            cout << s << "\n";
        }
    }

    return 0;
}
