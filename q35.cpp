#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[105][10005];  // increased sizes for safety

int fbu(vector<int> &wts, vector<int> &val, int W) {
    int n = wts.size();
    memset(dp, 0, sizeof(dp));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int j = 0; j <= W; j++) {
            int ans = dp[idx + 1][j];  // not pick
            if (wts[idx] <= j) {
                ans = max(ans, val[idx] + dp[idx + 1][j - wts[idx]]);
            }
            dp[idx][j] = ans;
        }
    }
    return dp[0][W];
}

int main() {
    int n, W;
    cin >> n;
    vector<int> wts(n), val(n);
    for (int i = 0; i < n; i++) cin >> wts[i];
    for (int i = 0; i < n; i++) cin >> val[i];
    cin >> W;

    int maxValue = fbu(wts, val, W);
    cout << "Value = " << maxValue << "\n";

    // Traceback to find selected items
    vector<int> selectedWeights, selectedValues;
    int capacity = W;
    for (int i = 0; i < n; i++) {
        // If picking this item improves value
        if (dp[i][capacity] != dp[i + 1][capacity]) {
            selectedWeights.push_back(wts[i]);
            selectedValues.push_back(val[i]);
            capacity -= wts[i];
        }
    }

    cout << "Weights selected : ";
    for (int w : selectedWeights) cout << w << " ";
    cout << "\nValues of selected weights : ";
    for (int v : selectedValues) cout << v << " ";
    cout << endl;

    return 0;
}
