#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    Solution():eachLayer(100) {}
    void Modified_leetcode105(string pre,string in) {
        _pre = pre;
        _in = in;
        Recursion(0,_pre.length(),0,0);
        for(auto each:eachLayer) {
            cout<<each;
        }
    }
private:
    vector<string> eachLayer;
    string _pre;
    string _in;
    void Recursion(int start,int end,int in_start,int layer) {
        if(end-start==0) { //left or right
            return ;
        }
        eachLayer[layer]+=_pre[start];
        /*
        if(end-start==1) {
            return ;
        }
        */
        int leftEnd ;
        int rightStart ;
        int i;
        for(i=0;i<end-start;i++) {
            if(_in[i+in_start]==_pre[start]) {
                leftEnd = start+1+i;
                rightStart = start+1+i;
                break ;
            }
        }
        Recursion(start+1,leftEnd,in_start,layer+1);
        Recursion(rightStart,end,in_start+i+1,layer+1);
    }
};

int main() {
    Solution test;
    string pre;
    string in;
    cin>>pre>>in;
    test.Modified_leetcode105(pre,in);
}

//without solution
//program 00:39.1
//Debug +1:32.9