#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // 2 1 4 3 5
    long long countSubarrays(vector<int>& nums, long long k) {
        queue<int> q;
        long long ans = 0;
        long long int cnt = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(q.size() == 0) {
                if(nums[i] < k) {
                    q.push(nums[i]);
                    cnt = 1;
                    count = nums[i];
                }
                continue;
            }
            cout << " start "<< i << " " << cnt << " " << count << " " << q.size() << " " << ans << " "<< nums[i] << endl;
            if((count + nums[i]) * (cnt + 1) < k) {
                q.push(nums[i]);
                cnt += 1;
                count += nums[i];
            } else {
                int t = q.size();
                while(!q.empty()) {
                    int number = q.front();
                    cout << "number : " << number << endl;
                    q.pop();
                    cnt--;
                    count -= number;
                    if((count  + nums[i]) * (cnt + 1) < k) {
                        for(int j = t; t >= q.size(); t--)
                        q.push(nums[i]);
                        count = count + nums[i];
                        cnt++;
                        break;
                    }
                }
                if(q.size() == 0) {
                    for(int j = 1; j <= t; j++) {
                        ans += j;
                            cout << "std" <<i << " " << j << " "  << cnt << " " << count  << " " << q.size() << " " << ans << endl;

                    }
                    if(nums[i] < k) {
                        q.push(nums[i]);
                        count = nums[i];
                        cnt = 1;
                    } 
                }
            }
        }
        if(!q.empty()) {
            for(int i = 1; i <= q.size(); i++) {
                
                ans += i;
                            cout << "std" <<i << " " << " "  << cnt << " " << count  << " " << q.size() << " " << ans << endl;
            }
        }
        return ans;
    }
};

int main() {
    Solution su;
    vector<int> numbers;
    long long int ans;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    //numbers.push_back(3);
   // numbers.push_back(5);
    ans = su.countSubarrays(numbers, 5);
    cout << ans << endl;
    return 0;
}




