# 单调栈

### 储水池问题
[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

输入为一个整型数组height。

#### 解法一: 辅助数组
 看到这个问题，首先想到的是采用两个辅助数组h1和h2，分别从左到右、从右到左遍历。其中h1和h2每个位置的数字
都是目前为止height中最大的值。然后利用height、h1和h2分别计算每个位置的储水量，相加即为答案。 一个优化的
方案是只用一个辅助数组h1，h2中的值在最后一次遍历中得到。

trappingRainWater.cpp/Solution::trap1

时间复杂度：O(n)
空间复杂度: O(n)

#### 解法二: 单调栈

利用单调栈可以实现从左到右1次扫描。

trappingRainWater.cpp/Solution::trap2

时间复杂度：O(n)
空间复杂度: O(n)

#### 解法三： 双指针法

这种解法是解法一的最终优化版。

trappingRainWater.cpp/Solution::trap3

时间复杂度：O(n)
空间复杂度: O(n)


### 滑动窗口最大值
[Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

本题如达到O(n)的时间复杂度，需要采用单调deque（单调栈的增强）

slidingWindowMaximum.cpp/Solution::maxSlidingWindow

时间复杂度：O(n)
空间复杂度: O(n)
