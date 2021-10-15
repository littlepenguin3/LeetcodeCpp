#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>

using namespace std;

class Solution {
public:
    Solution():ans(50){ans[0]="1"; }
    string countAndSay(int n) {
        for(int i=1;i<n;i++) {
            CountString(i);
        }
        return ans[n-1];
    }
private:
    vector<string> ans;
    void CountString(int index) {
        int counter = 0;
        string temp;
        cout<<ans[index-1]<<endl;
        for(int i=0;i<ans[index-1].length();i++) {
            if(i==0) {
                counter++;
            } else{
                if(ans[index-1][i-1]!=ans[index-1][i]) {
                    temp += to_string(counter);
                    temp += ans[index-1][i-1];
                    counter = 0;
                }
                counter++;
            }
            if(i==ans[index-1].length()-1) {
                temp += to_string(counter);
                temp += ans[index-1][i];
                counter = 0;
                ans[index] = temp;
                continue ;
            }
        }
    }
};

int main() {
    Solution test;
    cout<<test.countAndSay(20);
}

//4:31.1
//+16:20.3 -1错误 i/index错误
//without solution