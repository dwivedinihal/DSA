#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
// Comparison function for sorting by value/weight ratio
bool cmp(pair<double, pair<int, int>> &a, pair<double, pair<int, int>> &b) {
    return a.first > b.first; // sort by descending value/weight
}
int main() {
    int n;
    cin >> n;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    for (int i = 0; i < n; i++) cin >> values[i];
    int W;
    cin >> W;
    // Store: ratio, (index, weight and value)
    vector<pair<double, pair<int, int>>> items;
    for (int i = 0; i < n; i++) {
        double ratio = (double)values[i] / weights[i];
        items.push_back({ratio, {i + 1, weights[i]}});
    }
    // Sort by value/weight ratio in descending order
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;
    vector<pair<int, double>> selected; // {item index, weight taken}
    for (int i = 0; i < n && W > 0; i++) {
        int idx = items[i].second.first;
        int wt = items[i].second.second;
        double ratio = items[i].first;
        int originalVal = ratio * wt;
        if (wt <= W) {
            totalValue += originalVal;
            selected.push_back({idx, (double)wt});
            W -= wt;
        } else {
            totalValue += ratio * W;
            selected.push_back({idx, (double)W});
            W = 0;
        }
    }
    cout << fixed << setprecision(2);
    cout << "Maximum value : " << totalValue << endl;
    cout << "item-weight" << endl;
    for (auto it : selected) {
        cout << it.first << "-" << it.second << endl;
    }
    return 0;
}
