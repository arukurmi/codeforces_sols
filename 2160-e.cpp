#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        // For each row pair, store sorted column pairs
        map<pair<int,int>, vector<pair<int,int>>> row_pair_cols;
        
        for (int u = 0; u < n; u++) {
            for (int d = u + 1; d < n; d++) {
                vector<int> cols;
                for (int c = 0; c < m; c++) {
                    if (grid[u][c] == '1' && grid[d][c] == '1') {
                        cols.push_back(c);
                    }
                }
                
                if (cols.size() >= 2) {
                    for (int i = 0; i < (int)cols.size(); i++) {
                        for (int j = i + 1; j < (int)cols.size(); j++) {
                            row_pair_cols[{u, d}].push_back({cols[i], cols[j]});
                        }
                    }
                    // Sort by width (r - l) for early termination
                    sort(row_pair_cols[{u, d}].begin(), row_pair_cols[{u, d}].end(),
                         [](auto& a, auto& b) {
                             return (a.second - a.first) < (b.second - b.first);
                         });
                }
            }
        }
        
        // For each cell, find minimum area
        vector<vector<int>> result(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int min_area = INT_MAX;
                
                for (auto& [key, col_pairs] : row_pair_cols) {
                    int u = key.first;
                    int d = key.second;
                    
                    if (u <= i && i <= d) {
                        int height = d - u + 1;
                        
                        // Since col_pairs are sorted by width, find minimum valid
                        for (auto& [l, r] : col_pairs) {
                            if (l <= j && j <= r) {
                                int width = r - l + 1;
                                int area = height * width;
                                min_area = min(min_area, area);
                                break; // Found minimum width for this height
                            }
                        }
                    }
                }
                
                if (min_area != INT_MAX) {
                    result[i][j] = min_area;
                }
            }
        }
        
        // Output
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << result[i][j];
                if (j < m - 1) cout << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}