/*
写一个 RecentCounter 类来计算特定时间范围内最近的请求。

请你实现 RecentCounter 类：

RecentCounter() 初始化计数器，请求数为 0 。
int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
保证 每次对 ping 的调用都使用比之前更大的 t 值。

输入：
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
输出：
[null, 1, 2, 3, 3]

解释：
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3

思路：因为输入的时间只会比前一个大，切只计数[t - 3000, t]的个数，可以使用queue来存贮t，没输入一个新的t，用来与当前队列的最前端进行比较，差值大于
3000，进行pop操作，小于3000进行push操作，当队列pop为空后，把当前tpush进队列，最后返回q.size()即是[t - 3000, t]内ping的次数。
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
       
    }
    
    int ping(int t) {
        if(q.size() == 0) {
            q.push(t);
        } else {
            while(!q.empty()) {
                int x = q.front();
                if(t - x > 3000) {
                    q.pop();
                } else {
                    q.push(t);
                    break;
                }
            }
            if(q.size() == 0) {
                q.push(t);
            }
        }
        return q.size();
    }
};

int main() {
    RecentCounter* rec = new RecentCounter();
    int ans;
    ans = rec->ping(1);
    cout << ans << endl;
    ans = rec->ping(100);
    cout << ans << endl;
    ans = rec->ping(3001);
    cout << ans << endl;
    ans = rec->ping(3002);
    cout << ans << endl;
    return 0;
}