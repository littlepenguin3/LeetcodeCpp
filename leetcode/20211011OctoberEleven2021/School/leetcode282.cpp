#include<string>
#include<vector>
#include<cstdlib>
#include<iostream>
#include<ctime>

using namespace std;

class Solution1 {
public:
    vector<string> addOperators(string num, int target) {
        Solution1::target = target;
        Solution1::str = num;

        DFS(0,0,0,"");
        return answer;
    }
private:
    string str;
    int target;
    vector<string> answer;
    void DFS(long long preNumber,long long sum,int index,string curStr) {
        if(index == str.length()) {
            if(sum==target) {
                answer.push_back(curStr);
            }
            return ;
        }
        long long int curNumber = 0;
        if(index!=0) {
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stol(temp);
                DFS(preNumber*curNumber,sum-preNumber+preNumber*curNumber,index+len+1,curStr+"*"+temp); //*
                DFS(curNumber,sum+curNumber,index+len+1,curStr+"+"+temp); //+
                DFS(-curNumber,sum-curNumber,index+len+1,curStr+"-"+temp); //-  
                if(str[index]=='0') { //曾错写str[index]==0
                    break;
                }
            }
        } else{
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stoll(temp);
                DFS(curNumber,curNumber,index+len+1,curStr+str.substr(index,len+1));
                if(str[index]=='0') {
                    break;
                }
            }
        }
    }
};

class Solution2 {
public:
    vector<string> addOperators(string num, int target) {
        Solution2::target = target;
        Solution2::str = num;
        string reference;
        DFS(0,0,0,reference);
        return answer;
    }
private:
    string str;
    int target;
    vector<string> answer;
    void DFS(long long preNumber,long long sum,int index,string &curStr) {
        if(index == str.length()) {
            if(sum==target) {
                answer.push_back(curStr);
            }
            return ;
        }
        long long int curNumber = 0;
        if(index!=0) {
            int curStrlength = curStr.length();
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stoll(temp);
                curStr = curStr+'*'+temp;
                DFS(preNumber*curNumber,sum-preNumber+preNumber*curNumber,index+len+1,curStr); //*
                curStr.resize(curStrlength);
                curStr = curStr+'+'+temp;
                DFS(curNumber,sum+curNumber,index+len+1,curStr); //+
                curStr.resize(curStrlength);
                curStr = curStr+'-'+temp;
                DFS(-curNumber,sum-curNumber,index+len+1,curStr); //-  
                curStr.resize(curStrlength);
                if(str[index]=='0') { //曾错写str[index]==0
                    break;
                }
            }
        } else{
            int curStrlength = curStr.length();
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stoll(temp);
                curStr += temp;
                DFS(curNumber,curNumber,index+len+1,curStr);
                curStr.resize(curStrlength);
                if(str[index]=='0') {
                    break;
                }
            }
        }
    }
};

class Solution3 {
public:
    vector<string> addOperators(string num, int target) {
        Solution3::target = target;
        Solution3::str = num;
        string reference;
        DFS(0,0,0,reference);
        return answer;
    }
private:
    string str;
    int target;
    vector<string> answer;
    void DFS(long preNumber,long sum,int index,string &curStr) {
        if(index == str.length()) {
            if(sum==target) {
                answer.push_back(curStr);
            }
            return ;
        }
        long int curNumber = 0;
        if(index!=0) {
            int curStrlength = curStr.length();
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stol(temp);
                curStr = curStr+'*'+temp;
                DFS(preNumber*curNumber,sum-preNumber+preNumber*curNumber,index+len+1,curStr); //*
                curStr.resize(curStrlength);
                if(str[index]=='0') { 
                    break;
                }
            }
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stol(temp);
                curStr = curStr+'+'+temp;
                DFS(curNumber,sum+curNumber,index+len+1,curStr); //+
                curStr.resize(curStrlength);
                if(str[index]=='0') { 
                    break;
                }
            }
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stol(temp);
                curStr = curStr+'-'+temp;
                DFS(-curNumber,sum-curNumber,index+len+1,curStr); //-  
                curStr.resize(curStrlength);
                if(str[index]=='0') { 
                    break;
                }
            }
        } else{
            int curStrlength = curStr.length();
            for(int len=0;len+index<str.length();len++) {
                string temp = str.substr(index,len+1);
                curNumber = stol(temp);
                curStr += temp;
                DFS(curNumber,curNumber,index+len+1,curStr);
                curStr.resize(curStrlength);
                if(str[index]=='0') {
                    break;
                }
            }
        }
    }
};

class Solution4 {
public:
    vector<string>res;
    string path;
    typedef long long LL;
    vector<string> addOperators(string num, int target) {
        path.resize(100);
        dfs(num,0,0,0,1,target);
        return res;
    }
    void dfs(string& nums,int index,int len,LL preNumber,LL b,LL target)
    {
        if(index==nums.size())
        {
            
            if(preNumber==target) {
                //cout<<preNumber<<endl;
                res.push_back(path.substr(0,len-1));
            }
            return ;
        }
        LL curNumber=0;
        for(int i=index;i<nums.size();i++)
        {
            curNumber=curNumber*10+nums[i]-'0';
            //curNumber = stoll(nums.substr(index,i-index+1));
            path[len++]=nums[i];
            // +
            path[len]='+';
            dfs(nums,i+1,len+1,preNumber+b*curNumber,1,target);
            if(i+1<nums.size())
            {
                //-
                path[len]='-';
                dfs(nums,i+1,len+1,preNumber+b*curNumber,-1,target);

                //*
                path[len]='*';
                dfs(nums,i+1,len+1,preNumber,b*curNumber,target);
            }
            if(nums[index]=='0')break;
        }

    }
};

int main() {
    Solution1 test;
    string num;
    int target;
    cin>>num>>target;
    clock_t startTime = clock();
    vector<string> v=test.addOperators(num,target);
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<endl;
    }
    clock_t endTime = clock();
    cout<<endTime - startTime;
}

//with solution
//第一次出错 str[index]=='0'错写str[index]==0
//第二次出错 runtime error: signed integer overflow: 345 * 6237490 cannot be represented in type 'int' (solution.cpp)

//solution3为了学校字典序检查特别写的，无意义