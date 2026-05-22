#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> states;
    states.reserve(n * 35);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int cost = 0;

        while (true) {
            states.push_back({x, cost});

            if (x == 1) {
                states.push_back({2, cost + 1});
                break;
            }

            if (x == 2) {
                states.push_back({1, cost + 1});
                break;
            }

            if (x % 2 == 0) {
                x /= 2;
            } else {
                x += 1;
            }

            cost++;
        }
    }

    sort(states.begin(), states.end());

    long long ans = LLONG_MAX;

    int i = 0;
    while (i < (int)states.size()) {
        int value = states[i].first;
        long long totalCost = 0;
        int contributors = 0;

        while (i < (int)states.size() && states[i].first == value) {
            totalCost += states[i].second;
            contributors++;
            i++;
        }

        if (contributors == n) {
            ans = min(ans, totalCost);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}