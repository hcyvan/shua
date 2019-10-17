#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    bool canPlace(const vector<int> &que, int x, int y) {
        for(int i = 0;i<x;i++) {
            if(que[i]==y || abs(que[i]-y)==abs(i-x)){
                return false;
            }
        }
        return true;
    }
    vector<string> getStr(const vector<int> &que, int N) {
        vector<string> ret(N, string(N,'.'));
        for(int i = 0; i < N; i++) {
            ret[i][que[i]] = 'Q';
        }
        return ret;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        if(n==0){
            return ret;
        }
        vector<int> que(n, -1);
        int l = 0;
        while(l>=0) {
            int i = que[l]+1;
            for(;i<n;i++) {
                if(canPlace(que, l, i)) {
                    que[l] = i;
                    break;
                }
            }
            if(i<n) {
                l++;
            }else {
                que[l]=-1;
                l--;
            }
            if(l==n) {
                vector<string> tmp = getStr(que, n);
                ret.push_back(tmp);
                l--;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> coins = {2, 5, 10,1};
    Solution *s = new Solution();
    vector<vector<string>> ret = s->solveNQueens(0);
    for (auto v: ret) {
        cout << "==============" << endl;
        copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
    }
}