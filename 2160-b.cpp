#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(n + 1);
        b[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        
        vector<int> a(n + 1);
        map<int, int> pos_to_val; // maps position to value assigned
        int next_val = 1;
        
        for (int i = 1; i <= n; ++i) {
            long long diff = b[i] - b[i - 1];
            int last_pos = i - diff;
            
            if (last_pos == 0) {
                // New distinct element
                a[i] = next_val++;
            } else {
                // Reuse element from last_pos
                a[i] = a[last_pos];
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            cout << a[i];
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}