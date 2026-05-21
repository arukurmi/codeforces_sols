#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        
        vector<int> g(n, -1);
        bool bad = false;
        
        // Force assignments: at descent i, must have g[i]=0, g[i+1]=1
        for(int i = 0; i < n-1 && !bad; i++){
            if(a[i] > a[i+1]){
                if(g[i] == 1 || g[i+1] == 0) bad = true;
                else { g[i] = 0; g[i+1] = 1; }
            }
        }
        
        if(bad){ cout << "NO\n"; continue; }
        
        // Fill unforced gaps
        for(int i = 0; i < n; ){
            if(g[i] != -1){ i++; continue; }
            int j = i;
            while(j < n && g[j] == -1) j++;
            j--;
            
            int lg = (i > 0) ? g[i-1] : 0;
            int rg = (j+1 < n) ? g[j+1] : -1;
            
            if(lg == 1 && rg == 0){
                // Maximize the T->S khi contribution: find best split
                int best = i-1;
                for(int k = i; k <= j; k++)
                    if(a[k+1] - a[k] > a[best+1] - a[best]) best = k;
                for(int k = i; k <= j; k++) g[k] = (k <= best) ? 1 : 0;
            } else {
                for(int k = i; k <= j; k++) g[k] = (lg == 1) ? 1 : 0;
            }
            i = j + 1;
        }
        
        // Validate and compute k range
        ll klo = 1, khi = 2000000000000000000LL;
        for(int i = 0; i < n-1 && !bad; i++){
            if(g[i] == g[i+1]){
                if(a[i] > a[i+1]) bad = true;
            } else if(g[i] == 0){
                klo = max(klo, a[i] - a[i+1]);
            } else {
                khi = min(khi, a[i+1] - a[i]);
            }
        }
        
        cout << (!bad && klo <= khi ? "YES" : "NO") << "\n";
    }
    return 0;
}