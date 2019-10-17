#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void change(vector<char> &ret, vector<char> &m, char cur) {
    sort(m.begin(), m.end());
    for(char c: m) {
        ret.push_back(c);
        ret.push_back(cur);
    }
    ret.pop_back();
    m.clear();
}

int main(){
    int  n;
    scanf("%d", &n);
    vector<char> exp;
    char tc;
    for(int i = 0;i <= 2*n-2;i++) {
        scanf("%c", &tc);
        exp.push_back(tc);
    }
    vector<char> m, ret;
    char cur = '#';
    int i = 0;
    while(i<=2*n-2) {
        if(i%2==0) {
            m.push_back(exp[i]);
        } else {
            if(cur=='#' || cur == exp[i]) {
                cur = exp[i];
                ret.push_back(exp[i]);
            } else {
                change(ret, m, cur);
                ret.push_back(exp[i]);
                cur = exp[i];
            }
            i++;
        }
    }

    for(auto c : ret) {
        printf("%c ", c);
    }
    printf("\n");
}