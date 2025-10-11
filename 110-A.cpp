// Approach: Count digits '4' and '7' in n. If this count itself is a lucky number (contains only 4 and 7), print YES, else NO.
// Time Complexity: O(d) where d = number of digits in n
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    int luckyCount = 0;
    for (char c : n)
        if (c == '4' || c == '7')
            luckyCount++;

    if (luckyCount == 0) {
        cout << "NO";
        return 0;
    }

    bool isLucky = true;
    for (char c : to_string(luckyCount)) {
        if (c != '4' && c != '7') {
            isLucky = false;
            break;
        }
    }

    cout << (isLucky ? "YES" : "NO");
    return 0;
}
