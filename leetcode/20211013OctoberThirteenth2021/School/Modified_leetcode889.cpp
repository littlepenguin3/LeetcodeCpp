#include<iostream>
#include<vector>

using namespace std;


class Solution1 {
public:
    int Modified_leetcode889(string pre,string post) {
        _pre = pre;
        _post = post;
        return Recursion(0,_pre.length(),0);
    }
private:
    string _pre;
    string _post;
    int Recursion(int start,int end,int post_start) {
        if(end-start==0) { //left or right
            return 2;
        }
        if(end-start==1) {
            return 1;
        }
        int leftRoot = start+1;
        int rightRoot = -1;
        int i;
        for(i=0;i<end-start;i++) {
            if(_post[i+post_start]==_pre[leftRoot]) {
                rightRoot = i+1+leftRoot;
                break ;
            }
        }
        return Recursion(leftRoot,rightRoot,post_start)*Recursion(rightRoot,end,post_start+i+1);
    }
};

int main() {
    Solution1 test;
    string pre="QWERTYUIOPAS";
    string post="ROIUYASPTEWQ";
    cout<<test.Modified_leetcode889(pre,post);
}

//without solution
//program 20:00.0 +5.38:3
//Debug 14:39.2 乱 Debug花费大量时间 一开始递归函数没有加post_start没法做出来