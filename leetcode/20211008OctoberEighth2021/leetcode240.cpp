#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colNumber = matrix[0].size();
        int rowNumber = matrix.size();
        vector<int> maxModel(max(colNumber,rowNumber));
        if(colNumber>rowNumber) {
            for(int i=0;i<maxModel.capacity();i++) {
                if(i<rowNumber) {
                    maxModel[i] = matrix[i][i];
                }else {
                    maxModel[i] = matrix[rowNumber-1][i];
                }
            }
        }else {
            for(int i=0;i<maxModel.capacity();i++) {
                if(i<colNumber) {
                    maxModel[i] = matrix[i][i];
                }else {
                    maxModel[i] = matrix[i][colNumber-1];
                }
            }
        }
        decltype(maxModel.begin()) it = lower_bound(maxModel.begin(),maxModel.end(),target);
        if(it == maxModel.end()) {
            return false;
        }
        if(*it == target) {
            return true;
        }
        int layer = it - maxModel.begin();
        while(layer<maxModel.capacity()) {
        if(layer<colNumber) {
            int first = 0;
            int last = layer;
            int mid = 0;
            while(first<last) {
                mid = first + (last-first) / 2;
                if(matrix[min(layer,rowNumber-1)][mid]==target) {
                    return true;
                }
                if(matrix[min(layer,rowNumber-1)][mid]>target){
                    last = mid;
                }else{
                    first = mid+1;
                }
            }
            if(matrix[min(layer,rowNumber-1)][first]==target) {
                return true;
            }
        }
        if(layer<rowNumber) {
            int first = 0;
            int last = layer;
            int mid = 0;
            while(first<last) {
                mid = first + (last-first) / 2;
                if(matrix[mid][min(layer,colNumber-1)]==target) {
                    return true;
                }
                if(matrix[mid][min(layer,colNumber-1)]>target){
                    last = mid;
                }else{
                    first = mid+1;
                }
            }
            if(matrix[first][min(layer,colNumber-1)]==target) {
                return true;
            }
        }
        layer++;
        }
        return false;
    }
private:
    int min(int a,int b) {return a<b?a:b;}
};

int main() {
    Solution test;
    vector<vector<int>> matrix={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    cout<<test.searchMatrix(matrix,15);
}