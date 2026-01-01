#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // number of coin types
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int N; // target sum
    cin >> N;

    vector<vector<int>> dp(n + 1, vector<int>(N + 1, 0));

    // Base case: one way to make sum 0 (no coins)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill dp table
    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= N; sum++) {
            if (coins[i - 1] <= sum) {
                dp[i][sum] = dp[i - 1][sum] + dp[i][sum - coins[i - 1]];
            } else {
                dp[i][sum] = dp[i - 1][sum];
            }
        }
    }

    cout << dp[n][N] << endl;
    return 0;
}



