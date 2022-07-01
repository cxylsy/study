/*
241. 为运算表达式设计优先级
给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。

输入：expression = "2-1-1"
输出：[0,2]
解释：
((2-1)-1) = 0 
(2-(1-1)) = 2

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/different-ways-to-add-parentheses
著作权归力扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

方法dfs爆搜每一种情况，以运算符为界限，分别计算左右两块数字之和有多少种可能，再将两边得每一种可能进行运算，比如样例 “2 - 1 - 1”，先以第一个“ - ”分割
“2” 和 “1 - 1”，左边值为【2】， 右边继续进行分割最后分割为“1”和“1”， 进行运算得到值为“0”，再返回到第一个“-”时，左边可能为【2】右边和得可能为【0】进行运
算得到第一个答案【2】，再继续循环到第二个“-”时，又进行一次分割，这次分割为“2 - 1” 和 “1”，右边值为【1】， 左边继续分割为“2” 和 “1",得到值【2】和【1】
进行第一个运算符得运算得到值为【1】，所以第二个运算符左右两边得值得可能为【1】和【1】，进行运算得到值为【0】，放入ans中得到ans为【2，0】，没有第三个
运算符，返回ans值。
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dfs(int l, int r, string s) {
        vector<int> ans;
        for(int i = l; i <= r; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                continue;
            }
            vector<int> ll = dfs(l, i - 1, s);
            vector<int> rr = dfs(i + 1, r, s);
            for(auto a: ll) {
                for(auto b: rr) {
                    int cnt;
                    if(s[i] == '-') {
                        cnt = a - b;
                    } else if(s[i] == '+') {
                        cnt = a + b;
                    } else {
                        cnt = a * b;
                    }
                    ans.push_back(cnt);
                }
            }
        }
        if(ans.empty()) {
            int cnt = 0;
            for(int i = l; i <= r; i++) {
                cnt = cnt * 10 + s[i] - '0';
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return dfs(0, expression.length() - 1, expression);
    }
};

int main() {
    Solution solution;
    string s = "2-1-1";
    vector<int> ans = solution.diffWaysToCompute(s);
    for(auto cnt : ans) {
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}