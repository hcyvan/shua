cmake_minimum_required(VERSION 3.10)
project(zuo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(tt tt.cpp)

add_executable(coinChange src/coinChange.cpp)
add_executable(coinChange2 src/coinChange2.cpp)
add_executable(decompressString src/decompressString.cpp)
add_executable(trappingRainWater src/trappingRainWater.cpp)
add_executable(slidingWindowMaximum src/slidingWindowMaximum.cpp)
add_executable(sortImp src/sortImp.cpp)
add_executable(longestIncreasingSubsequence src/longestIncreasingSubsequence.cpp)
add_executable(NQueen src/NQueen.cpp)
add_executable(findMedian src/findMedian.cpp)

add_executable(stlBsearch src/stl/stlBsearch.cpp)


add_executable(upsetModAdd src/zhenti/upsetModAdd.cpp)

