#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    // If sum is odd, cannot partition equally
    if (sum % 2 != 0) {
        cout << "no" << endl;
        return 0;
    }

    int target = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    // Base case: sum 0 is always possible with empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][target])
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}

