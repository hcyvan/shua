#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    vector<int> nums = {1,2,3,4,5,5,5,6,7,8};
    vector<int>::iterator iter;
    pair<vector<int>::iterator, vector<int>::iterator> ipair;
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " | "));
    cout << endl;

    bool ret = binary_search(nums.begin(), nums.end(),5);
    cout << "binary_search";
    cout << "the answer is " << ret;
    cout << endl;

    iter = lower_bound(nums.begin(), nums.end(), 5);
    cout << "lower_bound: ";
    copy(iter, nums.end(), ostream_iterator<int>(cout, " | "));
    cout << endl;

    iter = upper_bound(nums.begin(), nums.end(), 5);
    cout << "upper_bound: ";
    copy(iter, nums.end(), ostream_iterator<int>(cout, " | "));
    cout << endl;

    ipair = equal_range(nums.begin(), nums.end(), 5);
    cout << "equal_range: ";
    copy(ipair.first, ipair.second, ostream_iterator<int>(cout, " | "));
    cout << endl;
}
