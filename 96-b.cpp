// Approach:
// 1. A "super lucky" number contains only digits {4,7} and has equal count of 4s and 7s.
// 2. Generate all such numbers up to 10 digits (since n ≤ 1e9 → max 10 digits).
// 3. Collect them, sort ascending, and find the smallest number ≥ n using lower_bound.

// Time Complexity: O(2^10) ≈ constant (~1024 combinations)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<long long> superLucky;

// Recursive generation of lucky numbers with equal 4s and 7s
void generate(string cur, int fours, int sevens, int len) {
    if ((int)cur.size() == len) {
        if (fours == sevens) superLucky.push_back(stoll(cur));
        return;
    }
    generate(cur + '4', fours + 1, sevens, len);
    generate(cur + '7', fours, sevens + 1, len);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Pre-generate all super lucky numbers up to 10 digits
    for (int len = 2; len <= 10; ++len) {
        if (len % 2 == 0) generate("", 0, 0, len);
    }

    sort(superLucky.begin(), superLucky.end());

    long long n;
    cin >> n;

    // Find the smallest super lucky number ≥ n
    for (long long x : superLucky) {
        if (x >= n) {
            cout << x << '\n';
            return 0;
        }
    }

    // If not found within limit (rare edge case)
    cout << 4444477777LL << '\n';
    return 0;
}
