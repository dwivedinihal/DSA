#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string seq1, seq2;
    getline(cin, seq1);
    getline(cin, seq2);

    int m = seq1.size();
    int n = seq2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct LCS string from dp table
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            lcs = seq1[i - 1] + lcs; // prepend current char
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "length = " << dp[m][n] << endl;
    return 0;
}


