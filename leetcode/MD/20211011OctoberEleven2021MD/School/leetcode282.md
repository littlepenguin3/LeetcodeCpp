# leetcode282.给表达式添加运算符

### 完成情况
Data: Month Day,Year XX:XXXX
剩余时间：00:08.8  Debug +06：00.0
通过测试用例：all clear(with soulution)
提交错误次数：两次
第一次出错 str\[index\]=='0'错写str\[index\]==0,字符串的字符'0'和数字0的小坑
第二次出错 runtime error: signed integer overflow: 345 * 6237490 cannot be represented in type 'int' (solution.cpp) 改用long long即可

### 个人解题思路
未解出

### 题解解题思路
DFS，记录上一个操作数和当前总和，在DFS函数中分割出所有可以分出的数字作为curNumber（相当于DFS有几个子节点），要注意当str\[index\]==0时，只能分出0
如果是乘法，则sum-preNumber+preNumber\*curNumber为新sum，preNumber\*curNumber为新preNumber
如果是加法，则+curNumber+sum为新sum，+curNumber为新preNumber
如果是减法，则-curNumber+sum为新sum，-curNumber为新preNumber

### 复杂度分析
时间复杂度：O(n^4) 递归有三个分支，每层递归要遍历后续的string,因此相当于n*n^3=n^4  
改进前空间复杂度：O(n) 改进前我自己写的代码大约是n^5，因为在进入每一个DFS节点时都要copy一个新的数组，消耗了大量空间，并且拷贝操作也增大了时间复杂度
改进后空间复杂度

### 其他思考
1.通过效率特别低，能否更快？
执行用时：536 ms, 在所有 C++ 提交中击败了10.00%的用户
内存消耗：113.1 MB, 在所有 C++ 提交中击败了7.77%的用户
原因：代码里面的String用的太烂，DFS每次递归进入一个新函数都产生一个string的copy，空间占用极大而且频繁复制影响了速度
函数 str.resize()
void std::__cxx11::string::resize(std::size_t __n, char __c)
Resizes the %string to the specified number of characters.

Parameters:
__n – Number of characters the %string should contain.
__c (optional)– Character to fill any new elements. This function will %resize the %string to the specified number of characters. If the number is smaller than the %string's current size the %string is truncated, otherwise the %string is extended and new elements are %set to __c.
解决办法：使用一个track string的引用去完成DFS中的所有事，在一个curNumber遍历完后，使用resize截短track string到之前的位置

经过在本电脑上测试，stoll占用很长时间，都使用stoll差距不大
但是leetcode修改后也用了很长时间，自己研究发现别人的代码和自己的差不多，不知道为什么运行时间相差那么多

2.long 和 long long
sizeof(long) 返回4 跟int一样 我服了
大数一定要用 long long  
long就是个傻逼  