#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;


class SummaryRanges {
private:
    map<int,int> ranges;
public:
    SummaryRanges():ranges() {}
    
    void addNum(int val) {
        if(ranges.empty()) {
            ranges.emplace(make_pair(val,val));
        }
        //decltype(ranges.begin()) rightRangeKey = ranges.lower_bound(val);
        //decltype(rightRangeKey) leftRangeKey = (rightRangeKey==ranges.begin())? ranges.end():prev(rightRangeKey);
        decltype(ranges.begin()) rightRangeKey = ranges.upper_bound(val);
        decltype(rightRangeKey) leftRangeKey = (rightRangeKey==ranges.begin())? ranges.end():prev(rightRangeKey);
        if(leftRangeKey!=ranges.end())
        cout<<val<<":"<<leftRangeKey->first<<","<<leftRangeKey->second<<endl;
        if(leftRangeKey->first<=val&&leftRangeKey->second>=val) {}else 
        {
            bool leftConnect = ((leftRangeKey != ranges.end())&&(leftRangeKey->second==val-1));
            bool rightConnect = ((rightRangeKey != ranges.end())&&(rightRangeKey->first==val+1));
            //cout<<val<<":"<<leftConnect<<","<<rightConnect<<endl;
            if(leftConnect&&rightConnect) {// merge two ranges
                leftRangeKey->second = rightRangeKey->second;
                ranges.erase(rightRangeKey);
            }else 
            if(leftConnect) { //left range's second+1
                leftRangeKey->second++;
            }else
            if(rightConnect) { //right range's first-1;
                int l = val;
                int r = rightRangeKey->second;
                ranges.erase(rightRangeKey);
                ranges.emplace(make_pair(l,r));
            }else {
                ranges.emplace(make_pair(val,val)); //这里用low
            }
        }

    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(auto eachPair : ranges) {
            vector<int> temp(2);
            temp[0] = eachPair.first;
            temp[1] = eachPair.second;
            ret.emplace_back(temp);
        }
        return ret;
    }
};

//with solution
//20:56:7 输出与预期不符，输出了完全分割了一个一个的小区间
//+5:00:0 通过