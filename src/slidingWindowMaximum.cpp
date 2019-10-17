#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            if(i >= k-1) {
                ret.push_back(nums[dq.front()]);
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution *s = new Solution();
    vector<int> ret = s->maxSlidingWindow(nums, 3);
    for(int a : ret) {
        cout << a << " ";
    }
    cout << endl;

}