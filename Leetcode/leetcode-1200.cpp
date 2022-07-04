/*
1200. 最小绝对差
给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]

思路：先进行排序，使用cnt记录当前的最小绝对差，如果当前的两个元素差值小于cnt，清空ans队列，将当前的两个元素作为一组数据push进ans，如果当前差值
等于cnt，则将当前的两个元素作为一组push进ans，大于cnt 则继续循环，循环完毕，返回ans
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int cnt = arr[1] - arr[0];
        for(int i = 1; i < arr.size(); i++) {
            int tmp = arr[i] - arr[i -  1];
            if(tmp < cnt) {
                cnt = tmp;
                ans.clear();
                ans.emplace_back(initializer_list<int>{arr[i - 1], arr[i]});
            } else if(tmp == cnt) {
                ans.emplace_back(initializer_list<int>{arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> tmp;
    tmp.push_back(3);
    tmp.push_back(31);
    tmp.push_back(6);
    tmp.push_back(9);
    tmp.push_back(15);
    tmp.push_back(18);
    tmp.push_back(57);
    vector<vector<int>> ans = solution.minimumAbsDifference(tmp);
    for(int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "]" << endl;
    }
    return 0;
}