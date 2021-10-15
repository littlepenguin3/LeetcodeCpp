#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;


class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if(s.length()<10) {
            return ret;
        }
        int length = s.length();
        unordered_set<string> find;
        unordered_set<string> answer;
        for(int i=0;i<length-9;i++) {
            if(find.find(s.substr(i,10))!=find.end()) {
                answer.insert(s.substr(i,10));
            } else{
                find.insert(s.substr(i,10));
            }
        }
        ret.assign(answer.begin(),answer.end());
        return ret;
    }
};

class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<string> ret;
        if(s.length()<10) {
            return ret;
        }
        unordered_map<int, int> find;
        int length = s.length();
        int bitNumber = 0;
        for(int i=0;i<10;i++){
            bitNumber+=map[s[i]];
            bitNumber = bitNumber<<2;
        }
        bitNumber = bitNumber>>2;
        find[bitNumber]++;
        for(int i=10;i<length;i++) {
            bitNumber = bitNumber<<2;
            bitNumber+=map[s[i]];
            bitNumber = bitNumber & ((1<<20)-1);
            if(++find[bitNumber]==2) {
                ret.push_back(s.substr(i-9,10));
            }
        }
        return ret;
    }
};

int main() {
    Solution2 test;
    string str="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> v=test.findRepeatedDnaSequences(str);
    for(auto each:v) {
        cout<<each<<endl;
    }
}