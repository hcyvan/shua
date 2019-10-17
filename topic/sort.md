# 排序
./src/sortImp.cpp
## 比较排序
### 冒泡排序：稳定，O(n^2)
### 插入排序：稳定，O(n^2)
插入排序对于较短的是数组具有很好的排序效果。例如c++ stl中的sort，在数组小于16的情况下，采用插排。在
BFPRT算法中，对于每一个长度为5的子数组进行排序的过程中，使用的也是插排。
### 选择排序：不稳定，O(n^2)
### 希尔排序：（递减增量排序算法，插排优化）稳定，平均O(n^1.3)，最好O(n^2)
### 归并排序：稳定，O(n*logn)
### 快速排序:  不稳定，O(n*logn)
### 堆排序：不稳定，O(n*logn)

## 非比较排序
### 计数排序: 不稳定， O(n)
### 桶排序：稳定，O(n)
### 基数排序：稳定，O(k * n)

# 中位数
## 求无序数组的中位数
[无序数组找中位数](https://www.lintcode.com/problem/median/my-submissions)
./src/findMedian.cpp

使用quickSelect方法有较好的效果，但使用BFPRT时，耗时反而多了。

std::swap性能极低
# TopK