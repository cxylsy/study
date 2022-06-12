/*
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组

思路：滑动窗口，使用队列存贮nums[i]值，使用sum 作为当前乘积值，当sum * num[i] < k 时，cnt++ 继续循环，当sum * num[i] > k 时，ans 加上cnt的值
表示q.front()到当前满足的数目，然后sum /= q.front(),q.pop(),cnt--，继续nums[i] * sum 是否大于k的判断，大于表示当前q.front()到当前i值也不满足
cnt--,ans += cnt, 小于表示满足条件继续push(num[i])，当循环结束，cnt不等于，再从1到n，循环加上，对应从nums.size() - cnt 已每个下标到结束能够符合
条件的数目
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        queue<int> q;
        int ans = 0;
        int sum = 1;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum * nums[i] < k) {
                cnt++;
                q.push(nums[i]);
                sum *= nums[i];
            } else {
                if(cnt == 0) {
                    continue;
                }
                ans += cnt;
                int number = cnt;
                while(1) {
                    int x = q.front();
                    q.pop();
                    if(sum / x * nums[i] < k) {
                        q.push(nums[i]);
                        sum = sum / x * nums[i];
                        break;
                    } else {
                        sum = sum / x;
                        cnt--;
                        ans += cnt;
                        
                    }
                    if(cnt == 0) {
                        if(nums[i] < k) {
                            cnt++;
                            q.push(nums[i]);
                            sum *= nums[i];
                            break;
                        } else {
                            break;
                        }
                    }
                        
                }
            }
        }
        for(int i = 1; i <= cnt; i++) {
            ans += i;
        }
        return ans;
    }
};

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    Solution s;
    int ans = s.numSubarrayProductLessThanK(v, 100);
    cout << ans << endl;
    return 0;
}