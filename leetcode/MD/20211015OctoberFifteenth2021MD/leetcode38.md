# leetcode38.外观数列

### 完成情况
Data: October Fifteenth,2021 Friday 9:00 AM
剩余时间：without solution program 4:31.1 Debug +16:20.3 debug因为代码不规范浪费了大量时间
通过测试用例：AC
提交错误次数：0

### 个人解题思路
遍历生成，每次把n个连续m在下一个字符串变成"nm"即可，注意处理边界情况

### 题解解题思路
与题解相同

### 复杂度分析
时间复杂度：O(1)  
空间复杂度：O(CM) C为总共需要多少个字符串，M为第C个字符串长度

###  巨慢Debug原因
1.i/index出现在同一个地方造成的逻辑混乱，浪费很多时间——代码不规范
2.i=str.length() 判断出错，应该是i=str.length()-1 这个细节浪费大量时间
3.string+int int会被类型转换为char 正确做法string+to_string(int)
这样就可以在string后面加上数字
