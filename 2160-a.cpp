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
        vector<int> freq(101, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            freq[x]++;
        }
        
        // Find the minimum MEX achievable
        int ans = 0;
        for (int i = 0; i <= 100; ++i) {
            if (freq[i] == 0) {
                ans = i;
                break;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}