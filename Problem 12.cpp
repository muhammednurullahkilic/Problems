#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    for (int i = 1; i <= m; ++i)
        dp[1][i] = 1;

    
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            
            for (int k = 1; k <= j / 2; ++k) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    
    int total = 0;
    for (int i = 1; i <= m; ++i)
        total += dp[n][i];

    return total;
}
