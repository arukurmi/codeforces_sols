#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        int cnt = 0;
        int last_one = -k;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i - last_one >= k) {
                    cnt++;
                }
                last_one = i;
            }
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}