/*You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.*/

//BRUTE FORCE:
//traverse through the entire 2D Matrix
/*For(i=0 -> n-1)
For(j=0 -> m-1)
*/

//Optimal solution: to get the row of any number
//row = number/m &
//column = number % m

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
             int n = matrix.size();
             int m = matrix[0].size();
             int low = 0;
             int high = n*m-1;
             while(low<=high){
                int mid = (low+ high)/2;
                int row = mid/m;
                int column = mid % m;
                if(matrix[row][column] == target){
                    return true;
                }
                else if(matrix[row][column] < target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
    
             }
             return false;
    
        }
    };