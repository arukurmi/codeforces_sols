#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        if (n == 0) {
            cout << "YES\n";
            continue;
        }
        
        // Check if n is a power of 2
        if ((n & (n - 1)) == 0) {
            cout << "NO\n";
            continue;
        }
        
        // Find the highest bit position
        int high_bit = 63 - __builtin_clzll(n);
        
        // Check if n has the form 2^k + (2^(k-1) - 1) where k >= 3
        // This gives patterns like 1011, 10111, 101111, etc.
        long long power = 1LL << high_bit;
        long long expected = power + (power / 2 - 1);
        
        if (high_bit >= 3 && n == expected) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}