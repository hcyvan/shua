#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int cal(int left, int right, int cur) {
        int tmp = min(left, right) - cur;
        return tmp >= 0 ? tmp : 0;
    }

    int trap1(vector<int>& height) {
        int n = height.size();
        if(n<=2) {
            return 0;
        }
        vector<int> h(n, 0);
        h[0] = height[0];
        for(int i=1; i < n; i++) {
            h[i] = max(height[i], h[i-1]);
        }
        int right_max = height[n-1];
        int ret = cal(h[n-1], right_max, height[n-1]);
        for(int i = n-2; i>=0;i--) {
            right_max = max(right_max, height[i]);
            ret += cal(h[i],right_max, height[i]);
        }
        return ret;
    }
    int trap2(vector<int>& height) {
        stack<int> st;
        int ret = 0;
        for(int i=0; i < height.size(); i++) {
            while(!st.empty() && height[st.top()] < height[i]) {
                int cur = st.top();
                st.pop();
                if(!st.empty()) {
                    int w = i - st.top() - 1;
                    int h = min(height[st.top()], height[i]) - height[cur];
                    ret += h * w;
                }
            }
            st.push(i);
        }
        return ret;
    }
    int trap3(vector<int>& height) {
        int ret = 0;
        int l = 0, r = height.size()-1, lm = 0, rm = 0;
        while(l < r) {
            if(height[l] <= height[r]) {
                if(lm > height[l]) {
                    ret += lm - height[l];
                } else {
                    lm = height[l];
                }
                l++;
            } else {
                if(rm > height[r]) {
                    ret += rm - height[r];
                } else {
                    rm = height[r];
                }
                r--;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution *s = new Solution();
    cout << s->trap1(height) << endl;
    cout << s->trap2(height) << endl;
    cout << s->trap3(height) << endl;
}