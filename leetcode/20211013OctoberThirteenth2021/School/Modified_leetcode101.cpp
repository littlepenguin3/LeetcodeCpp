#include<iostream>
#include<vector>

using namespace std;


struct Node {
    int value;
    int leftNode;
    int rightNode;
    int quantity;
};

class Solution {
public:
    int leetcode101() {
        int n;
        maxQuantity = 1;
        cin>>n;
        nodes.resize(n);
        for(int i=0;i<n;i++) {
            cin>>nodes[i].value;
        }
        for(int i=0;i<n;i++) {
            cin>>nodes[i].leftNode>>nodes[i].rightNode;
            if(nodes[i].leftNode>0) nodes[i].leftNode--;
            if(nodes[i].rightNode>0) nodes[i].rightNode--;
        }
        cout<<endl;
        CalcQuantity(0);
        for(int i=0;i<n;i++) {
            Recursion(nodes[i].leftNode,nodes[i].rightNode);
        }
        return maxQuantity;
    }
private:
    vector<Node> nodes;
    int maxQuantity;
    int CalcQuantity(int index) {
        if(index==-1) {
            return 0;
        }
        nodes[index].quantity = CalcQuantity(nodes[index].leftNode)+CalcQuantity(nodes[index].rightNode)+1;
        return nodes[index].quantity;
    }
    bool Recursion(int nodeindex1,int nodeindex2) {
        if(nodeindex1==-1&&nodeindex2==-1) {
            return true;
        }
        if(nodeindex1==-1||nodeindex2==-1) {
            return false;
        }
        if(nodes[nodeindex1].value!=nodes[nodeindex2].value) {
            return false;
        }
        if(nodes[nodeindex1].quantity!=nodes[nodeindex2].quantity) {
            return false;
        }
        if(Recursion(nodes[nodeindex1].leftNode,nodes[nodeindex2].rightNode)&&Recursion(nodes[nodeindex1].rightNode,nodes[nodeindex2].leftNode)) {
            maxQuantity = max(maxQuantity,nodes[nodeindex1].quantity+nodes[nodeindex2].quantity+1);
            return true;
        } else{
            return false;
        }
    }
};

int main() {
    Solution test;
    cout<<test.leetcode101();
}
//with solution
//program 20:00.0 +12:22.5
//Debug 15:13.8 

