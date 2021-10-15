#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<cctype>

using namespace std;


class Solution {
private:
    unordered_map<int,string> twobits;
    unordered_map<int,string> tenbit;
    unordered_map<int,string> thousandbit; //thouthand,incorrect
public:
    Solution () {
        thousandbit.insert(make_pair(1,""));
        thousandbit.insert(make_pair(2,"thousand"));
        thousandbit.insert(make_pair(3,"million"));
        thousandbit.insert(make_pair(4,"billion"));


        tenbit.insert(make_pair(1,""));
        tenbit.insert(make_pair(2,"twenty"));
        tenbit.insert(make_pair(3,"thirty"));
        tenbit.insert(make_pair(4,"forty"));
        tenbit.insert(make_pair(5,"fifty"));
        tenbit.insert(make_pair(6,"sixty"));
        tenbit.insert(make_pair(7,"seventy"));
        tenbit.insert(make_pair(8,"eighty"));
        tenbit.insert(make_pair(9,"ninety"));  //ninty,incorrect

        twobits.insert(make_pair(0,""));
        twobits.insert(make_pair(1,"one"));
        twobits.insert(make_pair(2,"two"));
        twobits.insert(make_pair(3,"three"));
        twobits.insert(make_pair(4,"four"));
        twobits.insert(make_pair(5,"five"));
        twobits.insert(make_pair(6,"six"));
        twobits.insert(make_pair(7,"seven"));
        twobits.insert(make_pair(8,"eight"));
        twobits.insert(make_pair(9,"nine"));
        twobits.insert(make_pair(10,"ten"));
        twobits.insert(make_pair(11,"eleven"));
        twobits.insert(make_pair(12,"twelve"));
        twobits.insert(make_pair(13,"thirteen"));
        twobits.insert(make_pair(14,"fourteen"));
        twobits.insert(make_pair(15,"fifteen"));
        twobits.insert(make_pair(16,"sixteen"));
        twobits.insert(make_pair(17,"seventeen"));
        twobits.insert(make_pair(18,"eighteen"));
        twobits.insert(make_pair(19,"nineteen"));
        for(int i=20;i<100;i++) {
            string temp;
            temp += tenbit[i/10];
            temp += (i%10==0) ? "":" ";
            temp += twobits[i%10];
            twobits.insert(make_pair(i,temp));
        }
    }
    string numberToWords(int num) {
        if(num==0) {
            return "Zero";
        }
        string ret;
        vector<int> bars;
        while(num>=1000){
            bars.insert(bars.begin(),num%1000);
            num/=1000;
        }
        bars.insert(bars.begin(),num);
        int counter = bars.size();
        for(auto eachBar:bars) {
            ret += twobits[eachBar/100];
            ret += ((eachBar/100)==0) ? "":" hundred "; //handred,incorrect
            ret += twobits[eachBar%100];
            ret += ((eachBar%100)==0) ? "":" ";
            
            if(eachBar!=0) {
                ret += thousandbit[counter];
                ret += " ";
            }
            counter--;
        }
        for(int i=0;i<ret.length();i++) {
            if(i==0||(ret[i-1]==' '&&ret[i]!=' ')) {
                ret[i] = toupper(ret[i]);
            }
        }
        while(ret.back()==' '){
            ret.erase(ret.end()-1); //important
        }
        while(ret.front()==' '){  //12345
            ret.erase(ret.begin());
        }
        return ret;
    }
};

int main() {
    Solution test;
    cout<<test.numberToWords(13);
}
//without solution
//25:00:0 complex
//+5:00:0