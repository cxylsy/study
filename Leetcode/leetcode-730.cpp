/*
给定一个字符串 s，返回 s 中不同的非空「回文子序列」个数 。

通过从 s 中删除 0 个或多个字符来获得子序列。

如果一个字符序列与它反转后的字符序列一致，那么它是「回文字符序列」。

如果有某个 i , 满足 ai != bi ，则两个序列 a1, a2, ... 和 b1, b2, ... 不同。

注意：

结果可能很大，你需要对 109 + 7 取模 。

提示：

1 <= s.length <= 1000
s[i] 仅包含 'a', 'b', 'c' 或 'd' 

方法动态规划：
对于字符串s 区间为[i,j]有以下几种情况：
    1.如果当前的s[i] == char && s[j] == char 的话，那么当前的回文串数量就会是2+s[i + 1, j - 1]; 2是因为多了 char， 和 char char 两个回文串
      而对于s[i+1, j - 1]来说，就等于s[i + 1] = 'a'、'b'、'c'、'd'为头的4种情况。
    2.s[i] == char && s[j] != char, 那么当前的数量就等于s[i, j - 1];
    3.s[i] != char && s[j] == char, 数量就等于s[i + 1, j];
    4.s[i] != char && s[j] != char, 数量就等于s[i + 1, j - 1];

    而对于边界条件，当字符串长度为0时，肯定为0，当长度为1时，那么初始值为1.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
        for(int i = 0; i < n; i++) {
            dp[s[i] - 'a'][i][i] = 1;
        }

        for(int len = 2; len <= n; ++len) { // 确定一个回文串的长度
            for(int i = 0, j = len - 1; j < n; i++, j++) { // 计算所有该长度回文串的个数
                for(char ch = 'a', k = 0; ch <= 'd'; ++ch, ++k) { //按边界条件计算回文串个数
                    if(s[i] == ch && s[j] == ch) {
                        dp[k][i][j] = (2LL + dp[0][i + 1][j - 1] + dp[1][i + 1][j - 1] + dp[2][i + 1][j - 1] + dp[3][i + 1][j - 1]) % MOD;
                    } else if (s[i] == ch) {
                        dp[k][i][j] = dp[k][i][j - 1];
                    } else if (s[j] == ch) {
                        dp[k][i][j] = dp[k][i + 1][j];
                    } else {
                        dp[k][i][j] = dp[k][i + 1][j - 1];
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 4; ++i) {
            ans = (ans + dp[i][0][n - 1]) % MOD;
        }
        return ans;
    }
};
int main() {
    Solution solution;
    string s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    int ans = solution.countPalindromicSubsequences(s);
    cout << ans << endl;
}