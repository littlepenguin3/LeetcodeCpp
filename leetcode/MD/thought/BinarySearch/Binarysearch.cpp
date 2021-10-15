#include<iostream>
#include<vector>

using namespace std;

class BinarySearch {
    public: 
        int Lower(vector<int> date,int target) {
            int mid = 0;
            int first = 0;
            int last = date.size();
            while(first<last) {
                mid = first + (last - first)/2;
                if(date[mid] >= target) {
                    last = mid;
                }else {
                    first = mid+1;
                }
            }
            return first;
        }
        int Upper(vector<int> date,int target) {
            int mid = 0;
            int first = 0;
            int last = date.size();
            while(first<last) {
                mid = first + (last - first)/2;
                if(date[mid] > target) {
                    last = mid;
                }else {
                    first = mid+1;
                }
            }
            return first;
        }
};

int main() {
    vector<int> v={1,1,3,3,3};
    BinarySearch test;
    cout<<"l:"<<test.Lower(v,2)<<endl<<"u:"<<test.Upper(v,2)<<endl;
}