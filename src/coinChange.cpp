#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChangeTopDown(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int ret = coinChangeRecurse(coins, amount, dp);
        return ret;
    }

    int coinChangeRecurse(vector<int>& coins, int remain, vector<int>& dp) {
        if (remain < 0) {
            return -1;
        }
        if (dp[remain] != INT_MAX) {
            return dp[remain];
        }
        int min_coin = INT_MAX;
        for(int coin : coins) {
            int pre = coinChangeRecurse(coins, remain - coin, dp);
            if(pre != -1) {
                min_coin = min(min_coin, pre + 1);
            }
        }
        dp[remain] = min_coin;
        return dp[remain];
    }

    int coinChangeDownTop(vector<int>& coins, int amount) {
        int n = coins.size();
        int MAX = amount + 1;
        vector<vector<int>> dp(n, vector<int>(amount+1, MAX));
        for(int i=0; i < n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 1; i <= amount; i++) {
            dp[0][i] = i%coins[0] == 0 ? i/coins[0] : dp[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= amount; j++) {
                dp[i][j] = j-coins[i] < 0 ? dp[i-1][j] : min(dp[i-1][j], dp[i][j-coins[i]] + 1);
            }
        }
        return dp.back().back() > amount ? -1 : dp.back().back();
    }

    int coinChangeDownTopCompression(vector<int>& coins, int amount) {
        int n = coins.size();
        int MAX = amount + 1;
        vector<int> dp(amount+1, MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            dp[i] = i%coins[0] == 0 ? i/coins[0] : dp[i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= amount; j++) {
                if (j-coins[i] >= 0) {
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
                }
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }
};

int main() {
    vector<int> coins = {2, 5, 10,1};
    Solution *s = new Solution();
    cout << s->coinChangeTopDown(coins, 27) << endl;
    cout << s->coinChangeDownTop(coins, 27) << endl;
    cout << s->coinChangeDownTopCompression(coins, 27) << endl;
}