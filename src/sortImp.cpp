#include <vector>
#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start];
    while(start < end) {
        while(start < end && pivot <= nums[end]) {
            end--;
        }
        nums[start] = nums[end];
        while(start < end && pivot > nums[start]) {
            start++;
        }
        nums[end] = nums[start];
    }
    nums[start] = pivot;
    return start;
}

void quicksort_recurse(vector<int>& nums, int start, int end) {
    if(start >= end) {
        return;
    }
    int key = partition(nums, start, end);
    quicksort_recurse(nums, start, key-1);
    quicksort_recurse(nums, key+1, end);
}

void quicksort_iteration(vector<int>& nums, int start, int end) {
    stack<int> st;
    st.push(start);
    st.push(end);
    while(!st.empty()) {
        int e = st.top();
        st.pop();
        int s = st.top();
        st.pop();
        int key = partition(nums, s, e);
        if (key > s){
            st.push(s);
            st.push(key - 1);
        }
        if (key < e) {
            st.push(key + 1);
            st.push(e);
        }
    }
}

void quicksort(vector<int>& nums) {
//    quicksort_recurse(nums, 0, nums.size()-1); //递归版
    quicksort_iteration(nums, 0, nums.size()-1); //迭代版
}

void merge(vector<int>& nums, vector<int>& tmp, int left, int mid, int right) {
    int l = left, r = mid + 1,cur=left;
    while(l <= mid && r <= right) {
        if(nums[l] <= nums[r]) {
            tmp[cur++] = nums[l++];
        } else {
            tmp[cur++] = nums[r++];
        }
    }
    while(l <= mid) {
        tmp[cur++] = nums[l++];
    }
    while(r <= right) {
        tmp[cur++] = nums[r++];
    }
    for(int i = left; i<=right;i++){
        nums[i] = tmp[i];
    }
}

void mergeSortRecurse(vector<int>& nums, int left, int right, vector<int>& tmp) {
    if(left < right) {
        int mid = (left + right)/2;
        mergeSortRecurse(nums, left, mid, tmp);
        mergeSortRecurse(nums, mid+1, right, tmp);
        merge(nums, tmp, left, mid, right);
    }
}

void mergeSortIteration(vector<int>& nums, vector<int>& tmp) {
    int n = nums.size();
    for(int i = 1; i < n; i+=i) {
        for(int j = 0; j < n; j += 2*i) {
            int left = j;
            int mid = min(n-1, j+i-1);
            int right = min(n-1, j+2*i-1);
            merge(nums, tmp, left, mid, right);
        }
    }
}

void mergeSort(vector<int>& nums) {
    if(nums.size()>1) {
        int n = nums.size();
        vector<int> tmp(n, 0);
//        mergeSortRecurse(nums, 0, n-1, tmp);//递归
        mergeSortIteration(nums, tmp);//迭代
    }
}

void heapify(vector<int>& nums, int index, int len) {
    int top = nums[index];
    int child = index*2 + 1;
    while(child < len) {
        if(child+1 < len && nums[child] < nums[child+1]) {
            child++;
        }
        if(nums[child] > nums[index]) {
            nums[index] = nums[child];
            index = child;
            child = index*2 + 1;
        } else {
            break;
        }
        nums[index] = top;
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();
    for(int i = (n-2)/2; i>=0; i--) {
        heapify(nums, i, n);
    }
    for(int i = n-1; i > 0; i--) {
        int tmp = nums[i];
        nums[i] = nums[0];
        nums[0] = tmp;
        heapify(nums, 0, i-1);
    }
}

void insertSort(vector<int> &nums) {
    for(int i=1;i<nums.size();i++) {
        int cur = nums[i], j=i;
        for(;j>0;j--){
            if(cur < nums[j-1]) {
                nums[j] = nums[j-1];
            } else {
                break;
            }
        }
        nums[j] = cur;
    }
}


void print(const vector<int> nums, string prefix="") {
    if(prefix!="") {
        cout << prefix << " : ";
    }
    for(int n:nums) {
        cout << n << " ";
    }
    cout << endl;
}

void selectSort(vector<int> &nums) {
    int n = nums.size();
    int minIndex;
    for(int i=0; i<n;i++) {
        minIndex=i;
        for(int j=i+1;j<n;j++) {
            if(nums[minIndex] > nums[j]) {
                minIndex = j;
            }
        }
        if(i!=minIndex) {
            int tmp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = tmp;
        }
    }
}

int main() {
    vector<int> nums;

    nums = {2, 5, 10,1,9,9,3,6,4,7,9};
    selectSort(nums);
    print(nums, "select sort");

    nums = {2, 5, 10,1,9,9,3,6,4,7,9};
    quicksort(nums);
    print(nums);

    nums = {2, 5, 10,1,9,9,3,6,4,7,9};
    mergeSort(nums);
    print(nums);

    nums = {2, 5, 10,1,9,9,3,6,4,7,9};
    heapSort(nums);
    print(nums);

    nums = {2, 5, 10,1,9,9,3,6,4,7,9};
    insertSort(nums);
    print(nums, "insert sort");
}