// Approach:
// - We start from the next year (y + 1).
// - For each year, check if all digits are distinct.
// - The first such year we find is the answer.
//
// Time Complexity: O(1) — since year range is small (max 9000)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

// Helper function to check if all digits in a year are unique
bool hasDistinctDigits(int year) {
    string s = to_string(year);
    set<char> digits(s.begin(), s.end());  // removes duplicates automatically
    return digits.size() == s.size();      // if sizes match → all digits distinct
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y;
    cin >> y;  // input year

    // Increment year until we find one with unique digits
    while (true) {
        y++;
        if (hasDistinctDigits(y)) {
            cout << y;
            break;
        }
    }

    return 0;
}
