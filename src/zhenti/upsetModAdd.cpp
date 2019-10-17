#include <iostream>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int n, m, tmp_int;
    cin >> n >> m;
    multiset<int> s1, s2;
    for(int i=0;i<n;i++) {
        cin >> tmp_int;
        s1.insert(tmp_int);
    }
    for(int i=0;i<n;i++) {
        cin >> tmp_int;
        s2.insert(tmp_int);
    }
    vector<int> ret;
    for(int i=m-1;i>=0;i--){
        vector<int> toDel;
        for(multiset<int>::iterator iter=s1.begin(); iter!=s1.end();iter++) {
            int num = (i - *iter + m) % m;
            multiset<int>::iterator is2 = s2.find(num);
            if(is2!=s2.end()) {
                toDel.push_back(*iter);
                ret.push_back(i);
                s2.erase(is2);
            }
        }
        for(int d: toDel){
            s1.erase(s1.find(d));
        }
    }
    copy(ret.begin(), ret.end(),ostream_iterator<int>(cout, " "));
}