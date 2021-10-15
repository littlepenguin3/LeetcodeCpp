#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int curRow,curCol;
        int maxRow = matrix.size();
        int smallRow = 0,bigRow = maxRow-1;
        int left=0,right=matrix[0].size()-1;
        while(smallRow<bigRow) {
            curRow = (smallRow+bigRow) / 2;
            int curNumber = matrix[curRow][0];
            if(curNumber == target) {
                return true;
            }else {
                if(curNumber < target){
                    smallRow = curRow+1;
                }else {
                    bigRow = curRow-1;
                } 
            }
        }
        curRow = smallRow;
        if(matrix[curRow][0]>target&&curRow>0) {
            curRow--;
        }
        while(left<right) {
            curCol = (left+right) / 2;
            int curNumber = matrix[curRow][curCol];
            if(curNumber == target) {
                return true;
            }else {
                if(curNumber < target){
                    left = curCol+1;
                }else {
                    right = curCol-1;
                } 
            }
        }
        curCol = left;
        if(matrix[curRow][curCol]==target) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<vector<int>> matrix={{1}};//{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<test.searchMatrix(matrix,0);
}