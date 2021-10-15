二分搜索的简单实现
二分搜索迭代器实现

二分搜索的行为
upper_bound
lower_bound

# 二分查找

### 二分查找的目的
查找某元素是否在一个排好序的序列里面并不是二分查找的目的  
二分查找的真正目的是找>,>=的下界和<,<=的上界
此处可以插图说明binarysearch1 上界和下界差1，因此只需找两个下界>和>=，也即upper_bound，lower_bound要做的事  
图

### 二分查找实现
1.左开右闭区间 last相当于尾后迭代器，此版本实现不把last取为size-1
2.中点的选取
mid = first + (last - first) / 2 ，这样写的目的是防止溢出 
java标准库曾经的标准写法mid = (first + last) / 2，存在了20多年都没有发现first + last两正数相加可能溢出，笑稀了捏
3.loop invariants 循环不变量
什么是loop invariants Initialization初始化->Maintenance保持->Termination终止，三过程中循环的本质性质都应该是正确的，这样才能确保循环算法的正确
以target>=的下界为例，loop invariants是first < last;first左边都比target小;last右边都大于等于target
直到最终状态 first==last时，因为左开右闭区间说明中间区间为空，便找到了>=的下界
4.查找结果 
对应元素的个数为upper_bound-lower_bound，如果为0就是没有
元素存在的起始位置是upper_bound
元素存在的尾后位置是lower_bound
### 代码

### 特殊情况
1.没有元素 first = 0，last = 0 empty特殊处理
其他情况均不是特殊情况 
