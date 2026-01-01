#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minComputationCost(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int size : files) {
        pq.push(size);
    }

    int cost = 0;
    while (pq.size() > 1) {
        int top1 = pq.top(); pq.pop();
        int top2 = pq.top(); pq.pop();

        int mergeCost = top1 + top2;
        cost += mergeCost;

        pq.push(mergeCost);
    }

    return cost;
}

int main() {
    int n;
    cin >> n;
    vector<int> files(n);
    for (int i = 0; i < n; i++) cin >> files[i];

    int result = minComputationCost(files);
    cout << result << endl;

    return 0;
}
