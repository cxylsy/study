/*
556. 下一个更大元素 III
给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。

注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 

示例 1：
输入：n = 12
输出：21

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/next-greater-element-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：将n得每一位数字存入数组中（最低位为数组起始位），然后寻找第一个降序得下标，作为第一个交换位置得下标，然后再从[0, idx)中找到第一个大于idx得位置
作为交换得第二个位置，然后进行交换，此时因为与idx交换后，当前得值已经满足大于n得条件，再把[0,idx)内的值从小到大，进行翻转，得到答案。

*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
       vector<int> nums;
       int k = n;
       while(k) {
           int temp = k % 10;
           k /= 10;
           nums.push_back(temp);
       }
       int idx = -1;
       for(int i = 0; i < nums.size() - 1; i++) {
           if(nums[i] > nums[i + 1]) {
               idx = i + 1;
               break;
           }
       }
       if(idx == -1) {
           return -1;
       }
       for(int i = 0; i < idx; i++) {
           if(nums[i] > nums[idx]) {
               swap(nums[i], nums[idx]);
               break;
           }
       }
       for(int  l = 0, r = idx - 1; l < r; l++, r--) {
           swap(nums[l], nums[r]);
       }
       long int ans = 0;
       for(int i = nums.size() - 1; i >= 0; i--) ans = ans * 10 + nums[i];
       return ans > INT_MAX ? -1 : (int)ans;
    }
};

int main() {
    Solution solution;
    int ans = solution.nextGreaterElement(276183);
    cout << ans << endl;
    return 0;
}