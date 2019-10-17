### 最小路径和

[Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

这个题目输入是一个n*m的二维数组nums
+ 解法1：使用二维dp（n*m）数组进行动态规划
+ 解法2：使用一维dp（n或m）数组进行动态规划，空间复杂度O(nim(n,m))
+ 解法3：在nums中记录动态规划过程，空间复杂度O(1)

时间复杂度为O(n*m)。将二维dp数组压缩到一维dp数组是动态规划优化的常用方法。

### 零钱兑换（最少零钱张数）
[Coin Change](https://leetcode.com/problems/coin-change/)

输入 coins数组，长度为n。目标钱数S

#### 解法一：TopDown
自顶向下，递归求解。使用dp数组记录已经计算过的情况，防止重复递归
coinChange.cpp/Solution::coinChangeTopDown

时间复杂度：O(S*n)
空间复杂度：O(S)

#### 解法二：DownTop
自低向上，迭代求解。使用n*S的二维dp数组记录动态规划过程
coinChange.cpp/Solution::coinChangeDownTop

时间复杂度：O(S*n)
空间复杂度：O(S*n)

#### 解法三：DownTop + 空间压缩
使用空间压缩法，将二维dp数组降低为一维dp数组
coinChange.cpp/Solution::coinChangeDownTopCompression

时间复杂度：O(S*n)
空间复杂度：O(S)

#### 解法四：TODO
解法三 leetcode排名50%

### 零钱兑换（换零方法数）
[Coin Change 2](https://leetcode.com/problems/coin-change-2/)

这是零钱兑换（最少零钱张数）的变种,对推公式改变。
coinChange2.cpp/Solution::change


### 最长递增子序列
[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

#### 解法一：DownTop动态规划 + 空间压缩
一维动态规划表dp中dp[i]表示长度为i的数组中的最长递增子序列。递推公式为:
    
    dp[i] = max(x(0), x(1), ..., x(i-1)), 其中x(j) = nums[i] > nums[j] ? dp[j]+1 : dp[j])

