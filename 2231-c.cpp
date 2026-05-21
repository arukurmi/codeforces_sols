#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<long long, long long> total_costs;
    map<long long, int> contributors;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        long long cost = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                total_costs[x] += cost;
                contributors[x]++;
                x /= 2;
                cost++;
            } else {
                x++;
                cost++;
            }
        }
        total_costs[1] += cost;
        contributors[1]++;
    }

    long long ans = LLONG_MAX;
    for (auto& [val, cost] : total_costs) {
        if (contributors[val] == n)
            ans = min(ans, cost);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}