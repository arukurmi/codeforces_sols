// Approach:
// 1. For maximum revenue: always sell from the plane with the most seats left (use max-heap).
// 2. For minimum revenue: always sell from the plane with the least seats left (use min-heap).
// 3. For each passenger, sell a ticket, add seat count to revenue, then reduce seat count by 1 and reinsert if > 0.

// Time Complexity: O(n log m)
// Space Complexity: O(m)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &x : a) cin >> x;

    // Max revenue: use max-heap
    priority_queue<int> maxHeap(a.begin(), a.end());
    int maxRev = 0;
    int passengers = n;
    while (passengers--) {
        int top = maxHeap.top(); maxHeap.pop();
        maxRev += top;
        if (top > 1) maxHeap.push(top - 1);
    }

    // Min revenue: use min-heap (remove planes with 0 seats)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int x : a) minHeap.push(x);
    int minRev = 0;
    passengers = n;
    while (passengers--) {
        int top = minHeap.top(); minHeap.pop();
        minRev += top;
        if (top > 1) minHeap.push(top - 1);
    }

    cout << maxRev << " " << minRev << '\n';
    return 0;
}
