#include <bits/stdc++.h>
using namespace std;

int query(vector<int>& indices) {
    cout << "? " << indices.size();
    for (int idx : indices) {
        cout << " " << idx;
    }
    cout << endl;
    cout.flush();
    
    int result;
    cin >> result;
    return result;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> result(2 * n + 1, 0);
    vector<bool> used(2 * n + 1, false);
    
    // For each value v from n down to 1
    for (int v = n; v >= 1; v--) {
        vector<int> unknown;
        for (int i = 1; i <= 2 * n; i++) {
            if (!used[i]) {
                unknown.push_back(i);
            }
        }
        
        if (unknown.size() == 2) {
            result[unknown[0]] = v;
            result[unknown[1]] = v;
            used[unknown[0]] = true;
            used[unknown[1]] = true;
            continue;
        }
        
        // Binary search for first position of v
        int left = 0, right = unknown.size() - 1;
        int first_idx = -1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            // Query positions [0...mid]
            vector<int> query_set;
            for (int i = 0; i <= mid; i++) {
                query_set.push_back(unknown[i]);
            }
            
            int mad = query(query_set);
            
            if (mad >= v) {
                // v appears at least twice in [0...mid]
                right = mid;
            } else {
                // v appears at most once in [0...mid], so both must be in [mid+1...end]
                left = mid + 1;
            }
        }
        
        first_idx = left;
        int first_pos = unknown[first_idx];
        result[first_pos] = v;
        used[first_pos] = true;
        
        // Remove first position and rebuild unknown list
        unknown.erase(unknown.begin() + first_idx);
        
        if (unknown.size() == 1) {
            result[unknown[0]] = v;
            used[unknown[0]] = true;
            continue;
        }
        
        // Binary search for second position
        left = 0;
        right = unknown.size() - 1;
        int second_idx = -1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            // Query first_pos + positions [0...mid]
            vector<int> query_set = {first_pos};
            for (int i = 0; i <= mid; i++) {
                query_set.push_back(unknown[i]);
            }
            
            int mad = query(query_set);
            
            if (mad >= v) {
                // v appears in [0...mid]
                right = mid;
            } else {
                // v must be in [mid+1...end]
                left = mid + 1;
            }
        }
        
        second_idx = left;
        int second_pos = unknown[second_idx];
        result[second_pos] = v;
        used[second_pos] = true;
    }
    
    cout << "!";
    for (int i = 1; i <= 2 * n; i++) {
        cout << " " << result[i];
    }
    cout << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}