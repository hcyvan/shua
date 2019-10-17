#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size(), ret=1;
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++) {
            int max_val=0;
            for(int j=0;j<i;j++) {
                max_val = max(max_val, nums[i]>nums[j]?dp[j]+1:1);
            }
            dp[i]=max_val;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
    int lengthOfLIS2(vector<int>& nums) {
        int len = nums.size();
        if(!len) {
            return 0;
        }
        vector<int> ends(len, 0);
        ends[0] = nums[0];
        int right = 0;
        int l, r, mid;
        for(int i = 1; i < len; i++) {
            l = 0;
            r = right;
            while(l <= r) {
                mid = (l+r)/2;
                if(ends[mid] < nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid  - 1;
                }
            }
            ends[l] = nums[i];
            right = max(right, l);
        }
        return right + 1;
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution *s = new Solution();
    cout << s->lengthOfLIS1(nums) << endl;
    cout << s->lengthOfLIS2(nums) << endl;
}