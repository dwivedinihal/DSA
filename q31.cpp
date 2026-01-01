#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // Input matrix dimensions and construct the dimension array
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (i == 0) v[0] = a; 
        v[i + 1] = b;         
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + v[i] * v[k] * v[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << dp[0][n] << endl; // final answer
    return 0;
}








