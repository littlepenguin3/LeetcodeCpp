#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start =0;
        int end = arr.size();
        int mid = 0;
        while(start<end) {
            mid = start + (end-start) / 2;
            bool ascend = (mid==arr.size()-1) || (arr[mid]<arr[mid+1]);
            bool deascend = (mid==0) || (arr[mid]<arr[mid-1]);
            if((!ascend)&&(!deascend)) {
                return mid;
            }else {
                if(ascend) {
                    start = mid+1;
                }
                if(deascend) {
                    end = mid;
                }
            }
        }
        return -1;
    }
};

class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size();
        int mid = 0;
        int ans = arr.size()-1;
        while(start<end) {
            mid = start + (end-start) / 2;
            if(arr[mid]>arr[mid+1]) {
                ans = mid;
                end = mid;
            }else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution1 test;
    vector<int> v={1,2,3,4,5,6,7};
    cout<<test.peakIndexInMountainArray(v);
}
//without solution
//Program 5:00.0 Debug +4:58.8 
//mingw的gdb本身不支持中文路径名造成的，如果你要用gdb调试的话就不能有中文字符出现在路径名里