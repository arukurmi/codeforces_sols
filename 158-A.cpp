#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int cutoff = a[k - 1];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= cutoff && a[i] > 0)
            count++;
    }

    cout << count << '\n';
    return 0;
}
