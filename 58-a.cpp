// Approach:
// - Check if we can form the word "hello" as a subsequence of the given string.
// - Iterate through input, and try to match each character of "hello" in order.
// - If all letters matched, print YES; otherwise, NO.
// Time Complexity: O(n) where n is length of input string
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    string target = "hello";
    int j = 0; // index for target

    for (char c : s) {
        if (c == target[j]) j++;
        if (j == 5) break; // all letters of "hello" matched
    }

    cout << (j == 5 ? "YES" : "NO");
    return 0;
}
