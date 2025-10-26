// Approach:
// 1. For each monster, compute how many hits hero needs to kill it: ceil(bi / A).
// 2. Each hit from that monster deals ai damage to hero, so total damage = ai * hits_needed.
// 3. Sum total damage from all monsters = total_damage.
// 4. However, hero can choose the order. Optimal strategy: fight the monster with the largest attack last,
//    because when hero kills it, its last hit won't be applied if hero dies exactly after that kill.
// 5. Therefore, if B > total_damage - max_ai, hero can kill all monsters (even if he dies right after).
//
// Time Complexity: O(n) per test case
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll A, B;
        int n;
        cin >> A >> B >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        ll total_damage = 0;
        ll max_attack = 0;

        for (int i = 0; i < n; ++i) {
            ll hits = (b[i] + A - 1) / A;  // ceil(bi / A)
            total_damage += a[i] * hits;
            max_attack = max(max_attack, a[i]);
        }

        // Hero survives if his health is > total damage - strongest monster attack
        cout << (B > total_damage - max_attack ? "YES\n" : "NO\n");
    }
    return 0;
}
