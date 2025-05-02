/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            int row = 0 , column = m-1;
            while(row<n && column >= 0){
                if(matrix[row][column] == target){
                    return true;
                }
                else if(matrix[row][column] < target){
                    row++;
                }
                else{
                    column--;
    
                }
            }
            return false;
        }
    };