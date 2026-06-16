#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

static vector<int> shut;
static long long mark = 0;

bool contiguous(const vector<int>& v) {
    mark++;
    int prev = -1;
    for (int x : v) {
        if (x != prev) {
            if (shut[x] == mark) return false;
            if (prev != -1) shut[prev] = mark;
            prev = x;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int,int> label;
        for (auto &x : a) {
            int raw;
            cin >> raw;
            auto it = label.find(raw);
            if (it == label.end()) {
                int next = label.size();
                label[raw] = next;
                x = next;
            } else {
                x = it->second;
            }
        }
        int distinct = label.size();
        if ((int)shut.size() < distinct) shut.resize(distinct, 0);

        vector<int> runVal, runL, runR;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            runVal.push_back(a[i]);
            runL.push_back(i);
            runR.push_back(j - 1);
            i = j;
        }
        int blocks = runVal.size();
        vector<int> freq(distinct, 0);
        for (int v : runVal) freq[v]++;
        int extra = blocks - distinct;

        bool ok;
        if (extra == 0) {
            ok = true;
        } else if (extra > 4) {
            ok = false;
        } else {
            vector<int> spots;
            for (int r = 0; r < blocks; r++) {
                if (freq[runVal[r]] >= 2) {
                    int s = runL[r], e = runR[r];
                    for (int p : {s - 1, s, e, e + 1})
                        if (p >= 0 && p < n) spots.push_back(p);
                }
            }
            sort(spots.begin(), spots.end());
            spots.erase(unique(spots.begin(), spots.end()), spots.end());
            ok = false;
            for (size_t x = 0; x < spots.size() && !ok; x++) {
                for (size_t y = x + 1; y < spots.size() && !ok; y++) {
                    int i = spots[x], j = spots[y];
                    if (a[i] == a[j]) continue;
                    swap(a[i], a[j]);
                    if (contiguous(a)) ok = true;
                    swap(a[i], a[j]);
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
