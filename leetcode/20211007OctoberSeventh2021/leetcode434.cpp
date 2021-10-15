//October 7,2021 daily question
#include<iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        int i=0;
        if(s.empty()) {
            return segments;
        }
        for(i=0;i<s.length();i++) {
            if(s[i]!=' ') {
                break;
            }
        }
        for(;i<s.length();i++) {
            if(s[i]==' ') {
                segments++;
                for(;i<s.length();i++){
                    if(s[i]!=' '){
                        break;
                    }
                }
                i--;
            }
        }
        if(s.back()==' ') {
            return segments;
        }
        return segments+1;
    }
};

int main() {
    Solution test;
    cout<<test.countSegments("Hello, my name is John     ");
}