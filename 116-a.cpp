// Approach:
// - We simulate each stop of the tram.
// - Keep track of how many passengers are currently inside.
// - At each stop:
//    1. Subtract those who exit (ai).
//    2. Add those who enter (bi).
// - After every stop, track the maximum number of passengers inside.
// - The maximum value observed is the minimum required tram capacity.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;  // number of stops

    int current = 0;   // current number of passengers inside tram
    int capacity = 0;  // maximum passengers at any moment

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;       // a = exiting, b = entering
        current -= a;        // first, people exit
        current += b;        // then, new passengers enter
        capacity = max(capacity, current); // track max load
    }

    cout << capacity;
    return 0;
}
