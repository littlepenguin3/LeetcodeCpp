# leetcode Sword to Offer II 069. 山峰数组的顶部

### 完成情况
Data: October 14th,2021 Thursday 8:55 AM
剩余时间：program 05:00.0 Debug +4：50.5 
通过测试用例：AC
提交错误次数：0

### 个人解题思路
Binary search,判断，当前是升序则在右半区搜索，当前是降序则在左半区搜索，当前既不是升序也不是降序说明已经找到了高峰点  
```
bool ascend = (mid==arr.size()-1) || (arr[mid]<arr[mid+1]);
bool deascend = (mid==0) || (arr[mid]<arr[mid-1]);
```  
使用了两个布尔变量判断当前处在升序还是降序中，并且都需要注意边界的情况

### 题解解题思路
同样是二分，当i < ans_index 时，arr\[i] < arr\[ans_index] 
当i >= ans_index 时，arr\[i] > arr\[ans_index] 
所以是找 arr\[i] > arr\[ans_index] 的 upper_case ，即满足条件的上界
这个理解更接近二分的本质

### 复杂度分析
时间复杂度：O(logn)  
空间复杂度：没有任何额外空间O(1)

### 补充
mingw的gdb本身不支持中文路径名造成的，如果你要用gdb调试的话就不能有中文字符出现在路径名里，所以改名Swordto