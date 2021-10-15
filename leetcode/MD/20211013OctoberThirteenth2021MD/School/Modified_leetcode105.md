# leetcode105. 从前序与中序遍历序列构造二叉树

### 完成情况
Data: OCT 13TH 2021
剩余时间：without solution program 00:39.1 Debug +1:32.9  
通过测试用例:AC
提交错误次数：0
### 个人解题思路
由前序和中序遍历一定可以找到当前层的唯一一个节点，即确定唯一一个二叉树。
前序：根(左)(右)
中序：(左)根(右)
因此在当前preorder的第一个节点一定是当前的根节点，在inorder中找到根节点的位置，就可以得到左子树长度，从而得到左子树，又可以得到右子树，从而可以进行Recursion。
Recursion(int preStart,int preEnd,int inStart)

pseudo code
```
Recursion(int preStart,int preEnd,int inStart,int layer) {
if(preEnd-preStart==0) return; 说明当前根节点为空
if(preEnd-PreStart==1) pre\[preStart\]为当前根节点，且左右均为空节点 return; //这个可以不要，因为1再递归一层就是0
for(int i=0;i<preEnd-PreStart;i++) {
    if(_in[i+in_start]==_pre[start]) {
        leftLength = i; //左子树长度为i
    }
Recursion(preStart+1,preStart+1+length,inStart,layer+1) //左子树在中序遍历串第一位没变
Recursion(preStart+1+length,preEnd,inStart+length+1,layer+1) //左子树在中序遍历串第一位没变
}
}
```

按以上把每层节点都得到，拼接起来就是广度优先遍历结果

### 题解解题思路
与个人相同

### 复杂度分析
时间复杂度：递归n个节点O(n)  
空间复杂度：递归空间复杂度O(logn)，最坏情况下链表O(n)


