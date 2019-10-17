#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <climits>
#include <iterator>

using namespace std;
using namespace chrono;


class SolutionQuicikSelect {
public:
    int partition(vector<int> &nums, int start, int end){
        int pivot = nums[start];
        while(start < end) {
            while (start < end && pivot <= nums[end]) {
                end--;
            }
            nums[start] = nums[end];
            while (start < end && pivot > nums[start]) {
                start++;
            }
            nums[end] = nums[start];
        }
        nums[start] = pivot;
        return start;
    }

    int median(vector<int> &nums) {
        int n = nums.size();
        int l=0, r=n-1, target=(n-1)/2;
        int p;
        while(1) {
            p = partition(nums, l, r);
            if(p == target) {
                break;
            } else if(p < target) {
                l=p+1;
            }else{
                r=p-1;
            }
        }
        return  nums[target];
    }
};

// ######################################
class SolutionBFRPT {
public:
    void insert_sort(vector<int> &nums, int l, int r) {
        for(int i=l+1;i<=r;i++) {
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
    int median_of_medians(vector<int> &nums, int l, int r) {
        if(l==r) {
            return nums[l];
        }
        int n = (r-l+1)/5 + ((r-l+1)%5 == 0 ? 0 : 1);
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            int lo=l+i*5;
            int hi=l+i*5+4;
            hi = hi > r ? r : hi;
            insert_sort(nums, lo, hi);
            arr[i]=nums[(lo+hi)/2];
        }
        return select(arr, 0, n-1, (n-1)/2);
    }

    pair<int, int> partition_bfprt(vector<int> &nums, int l, int r, int pivot) {
        int lo = l-1, hi=r+1, cur = l;
        while(cur < hi) {
            if(nums[cur] < pivot) {
                nums[++lo]=nums[cur++];
            } else if(nums[cur] > pivot) {
                swap(nums[--hi], nums[cur]);
            } else {
                cur++;
            }
        }
        for(int i=lo+1;i<=hi-1;i++) {
            nums[i]=pivot;
        }
        pair<int, int> ret(lo+1,hi-1);
        return ret;
    }

    int select(vector<int> &nums, int l, int r, int ki) {
        if(l==r) {
            return nums[l];
        }
        int pivot = median_of_medians(nums, l, r);
        pair<int,int> pivot_range = partition_bfprt(nums, l, r, pivot);
        if(pivot_range.first <= ki && pivot_range.second >= ki) {
            return nums[ki];
        } else if(pivot_range.first >= ki) {
            select(nums, l, pivot_range.first-1, ki);
        } else {
            select(nums, pivot_range.second+1, r, ki);
        }
    }

    int bfrpt(vector<int> nums, int k) {
        return select(nums, 0, nums.size()-1, k-1);
    }

    int median(vector<int> &nums) {
        int n = nums.size();
        return select(nums, 0, n-1, (n-1)/2);
    }
};

class SolutionBFPRT_GeeksForGeeks {
public:
    int findMedian(int arr[], int n)
    {
        sort(arr, arr+n); // Sort the array
        return arr[n/2]; // Return middle element
    }
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // If k is smaller than number of elements in array
        if (k > 0 && k <= r - l + 1)
        {
            int n = r-l+1; // Number of elements in arr[l..r]

            // Divide arr[] in groups of size 5, calculate median
            // of every group and store it in median[] array.
            int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
            for (i=0; i<n/5; i++)
                median[i] = findMedian(arr+l+i*5, 5);
            if (i*5 < n) //For last group with less than 5 elements
            {
                median[i] = findMedian(arr+l+i*5, n%5);
                i++;
            }

            // Find median of all medians using recursive call.
            // If median[] has only one element, then no need
            // of recursive call
            int medOfMed = (i == 1)? median[i-1]:
                           kthSmallest(median, 0, i-1, i/2);

            // Partition the array around a random element and
            // get position of pivot element in sorted array
            int pos = partition(arr, l, r, medOfMed);

            // If position is same as k
            if (pos-l == k-1)
                return arr[pos];
            if (pos-l > k-1) // If position is more, recur for left
                return kthSmallest(arr, l, pos-1, k);

            // Else recur for right subarray
            return kthSmallest(arr, pos+1, r, k-pos+l-1);
        }

        // If k is more than number of elements in array
        return INT_MAX;
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    // It searches for x in arr[l..r], and partitions the array
    // around x.
    int partition(int arr[], int l, int r, int x)
    {
        // Search for x in arr[l..r] and move it to end
        int i;
        for (i=l; i<r; i++)
            if (arr[i] == x)
                break;
        swap(&arr[i], &arr[r]);

        // Standard partition algorithm
        i = l;
        for (int j = l; j <= r - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[r]);
        return i;
    }
    int median(vector<int> &nums) {
        int n = nums.size();
        int* arr = &nums[0];
        return kthSmallest(arr,  0, n-1, (n-1)/2);
    }
};

class SolutionBFRPT_Fix {
public:
    void insert_sort(vector<int> &nums, int l, int r) {
        for(int i=l+1;i<=r;i++) {
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
    void swapVec(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    int median_of_three(vector<int> &nums, int l, int r) {
        if(r-l+1<3) {
            return nums[l];
        } else {
            int m = l+r/2;
            if(nums[l]>=nums[m] && nums[m] >=nums[r]) {
                return nums[m];
            } else if( nums[m]>= nums[l] && nums[m] >= nums[r]) {
                return max(nums[l], nums[r]);
            } else {
                return max(nums[l], nums[r]);
            }
        }
    }
    int median_of_medians(vector<int> &nums, int l, int r) {
        if(l==r) {
            return nums[l];
        }
        int n = (r-l+1)/5 + ((r-l+1)%5 == 0 ? 0 : 1);
        for(int i=0;i<n;i++) {
            int lo=l+i*5;
            int hi=l+i*5+4;
            hi = hi > r ? r : hi;
            insert_sort(nums, lo, hi);
            swapVec(nums, l+i, (lo+hi)/2);
        }
        return median_of_medians(nums, l, l+n-1);
//        return select(nums, l, l+n-1, l+(n-1)/2); 性能差
//        return nums[l]; 性能极差
    }

    pair<int, int> partition_bfprt(vector<int> &nums, int l, int r, int pivot) {
        int lo = l-1, hi=r+1, cur = l;
        while(cur < hi) {
            if(nums[cur] < pivot) {
                nums[++lo]=nums[cur++];
            } else if(nums[cur] > pivot) {
                swapVec(nums, --hi, cur);
            } else {
                cur++;
            }
        }
        for(int i=lo+1;i<=hi-1;i++) {
            nums[i]=pivot;
        }
        pair<int, int> ret(lo+1,hi-1);
        return ret;
    }

    int select(vector<int> &nums, int l, int r, int ki) {
        if(l==r) {
            return nums[l];
        }
//        int pivot = median_of_medians(nums, l, r);
        int pivot = median_of_three(nums, l, r);
        pair<int,int> pivot_range = partition_bfprt(nums, l, r, pivot);
        if(pivot_range.first <= ki && pivot_range.second >= ki) {
            return nums[ki];
        } else if(pivot_range.first >= ki) {
            select(nums, l, pivot_range.first-1, ki);
        } else {
            select(nums, pivot_range.second+1, r, ki);
        }
    }

    int bfrpt(vector<int> nums, int k) {
        return select(nums, 0, nums.size()-1, k-1);
    }

    int median(vector<int> &nums) {
        int n = nums.size();
        return select(nums, 0, n-1, (n-1)/2);
    }
};

// ######################################
vector<int> gen_vector(int n, int min_value=1, int max_value=100) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min_value, max_value);
    vector<int> ret;
    for(int i = 0;i<n;i++) {
        ret.push_back(dist6(rng));
    }
    return ret;
}

typedef system_clock::time_point tp;

double get_microseconds(tp start, tp end) {
    auto duration = duration_cast<microseconds>(end - start);
    return double(duration.count()) * microseconds::period::num / chrono::microseconds::period::den;
}

int main() {
    SolutionQuicikSelect quicikSelect = SolutionQuicikSelect();
    SolutionBFRPT bfrpt = SolutionBFRPT();
    SolutionBFRPT_Fix bfrptFix = SolutionBFRPT_Fix();
    SolutionBFPRT_GeeksForGeeks geeks = SolutionBFPRT_GeeksForGeeks();


    vector<int> nums = gen_vector(100000, 1,10000);
//    vector<int> nums = {22,37,52,68,90,62,84,42,59,57};
    copy(nums.begin(), nums.begin()+10, ostream_iterator<int>(cout," "));
    cout << endl;

    vector<int> nums0 = nums;
    tp start = system_clock::now();
    sort(nums0.begin(), nums0.end());
    int m0 = nums[(nums.size()-1)/2];
    tp end   = system_clock::now();
    cout << "std::sort : "<< m0 << " 共耗时: " << get_microseconds(start, end) << "秒" << endl;

    vector<int> nums1 = nums;
    start = system_clock::now();
    int m = quicikSelect.median(nums1);
    end   = system_clock::now();
    cout << "quickselect : "<< m << " 共耗时: " << get_microseconds(start, end) << "秒" << endl;
    //-------------------
    vector<int> nums2 = nums;
    start = system_clock::now();
    int m2 = bfrpt.median(nums2);
    end   = system_clock::now();
    cout << "BFRPT : "<< m2 << " 共耗时: " << get_microseconds(start, end) << "秒" << endl;
    //-------------------
    vector<int> nums3 = nums;
    start = system_clock::now();
    int m3 = bfrptFix.median(nums3);
    end   = system_clock::now();
    cout << "BFRPT FIX : "<< m3 << " 共耗时: " << get_microseconds(start, end) << "秒" << endl;
//    //-------------------
//    vector<int> nums3 = nums;
//    start = system_clock::now();
//    int m3 = geeks.median(nums2);
//    end   = system_clock::now();
//    cout << "SolutionBFPRT_GeeksForGeeks : "<< m2 << " 共耗时: " << get_microseconds(start, end) << "秒" << endl;

//    vector<int> nums = {1,3,3,2,2,2,2,4,5,9};
//    partition_bfprt(nums, 0, nums.size()-1, 3);
}