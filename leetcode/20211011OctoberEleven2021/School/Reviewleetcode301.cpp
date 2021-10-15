#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<set>

using namespace std;


class Solution {
public:
    Solution():targetLeft(0),targetRight(0),deleteLeft(0),deleteRight(0) {}
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        str = s;
        for(int i = 0;i<s.length();i++) {
            if(s[i]=='(') {
                targetLeft++;
            }else 
            if(s[i]==')') {
                targetRight++;
                if(targetRight>targetLeft) {
                    targetRight--;
                    deleteRight++;
                }
            }
        }
        deleteLeft = targetLeft - targetRight;
        targetLeft = targetRight;
        string reference;
        DFS(0,0,0,0,0,reference);
        ret.assign(order_checked.begin(),order_checked.end());
        return ret;
    }
private:
    int targetLeft;
    int targetRight;
    int deleteLeft;
    int deleteRight;
    string str;
    unordered_set <string> checked;
    set<string> order_checked;
    void DFS(int index,int curL,int curR,int curDL,int curDR,string &curStr) {
        if(curR>curL) {
            return ;
        }
        
        if(index==str.length()) {
            if(curDL==deleteLeft&&curDR==deleteRight) {
                checked.insert(curStr);
                order_checked.insert(curStr);
            }
            return;
        }
        /* 枝剪尼玛 
        if(curDL==deleteLeft&&curDR==deleteRight) {
            int length = curStr.length();
            curStr += str.substr(index);
            checked.insert(curStr);
            curStr.resize(length);
            return ;
        }
        */
        if(str[index]=='(') {
            if(curDL<deleteLeft) {
                DFS(index+1,curL,curR,curDL+1,curDR,curStr);
            } 
            curStr.push_back('(');
            DFS(index+1,curL+1,curR,curDL,curDR,curStr);
            curStr.erase(curStr.end()-1);
        }else 
        if(str[index]==')') {
            if(curDR<deleteRight) {
                DFS(index+1,curL,curR,curDL,curDR+1,curStr);
            }
            curStr.push_back(')');
            DFS(index+1,curL,curR+1,curDL,curDR,curStr);
            curStr.erase(curStr.end()-1);
        }else {
            curStr.push_back(str[index]);
            DFS(index+1,curL,curR,curDL,curDR,curStr);
            curStr.erase(curStr.end()-1);
        }
    }
};


int main() {
    Solution test;
    string s;
    cin>>s;
    vector<string> v=test.removeInvalidParentheses(s);
    for(auto each:v) {
        cout<<each<<endl;
    }
}

//Review

//第一次错误：erase(end()-1)
//第二次错误：对着一条到底的分支枝剪，完全没必要

//20:00.0 +28:48.6 access 76/127

//set是为了应付学校字典序排列，无意义