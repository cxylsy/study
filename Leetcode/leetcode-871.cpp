/*
871. 最低加油次数
汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。

沿途有加油站，每个 station[i] 代表一个加油站，它位于出发位置东面 station[i][0] 英里处，并且有 station[i][1] 升汽油。

假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。

当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。

为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。

注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。

示例1：
输入：target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
输出：2
解释：
我们出发时有 10 升燃料。
我们开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
然后，我们从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
并将汽油从 10 升加到 50 升。然后我们开车抵达目的地。
我们沿途在1两个加油站停靠，所以返回 2 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-number-of-refueling-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：当前得startFuel值为自己能跑的最远距离，在这个距离内的加油站，我们都可以加油，要求最少的加油次数，我们只需要当当前得startFuel用完时，选择
之前所跑路程中加油最多得加油站，再继续跑，直到跑到target位置。如何选择当前加油最多得加油站，使用优先队列存贮路过得加油站得加油大小，每次需要加油时
选择top,在pop掉，直到到达target或者队列为空。

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int cnt  = 0;
        priority_queue<int> q;
        int n = stations.size();
        int count = 0, idx = 0, remain = startFuel;
        while(count < target) {
            if(remain == 0) {
                if(!q.empty()) {
                    remain += q.top();
                    cnt++;
                    q.pop();
                } else {
                    return -1;
                }
            }
            count += remain;
            remain = 0;
            while(idx < n && stations[idx][0] <= count) {
                q.push(stations[idx][1]);
                idx++;
            }
        }
        return cnt;
    }   
};

int main() {
    Solution so;
    vector<vector<int>> temp;
    vector<int> ans;
    ans.push_back(50);
    ans.push_back(50);
    temp.push_back(ans);
    int cnt = so.minRefuelStops(100, 50, temp);
    cout << cnt;
    return 0;
}