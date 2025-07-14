//optimal solution
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       if (matrix.empty() || matrix[0].empty()) {
            return; // Handle empty matrix case
        }

        int R = matrix.size();
        int C = matrix[0].size();
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        // Step 1: Check if the first row has any zeros
        for (int j = 0; j < C; ++j) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        // Step 2: Check if the first column has any zeros
        for (int i = 0; i < R; ++i) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        // Step 3: Use the first row and first column as markers
        // Iterate from (1,1) to (R-1, C-1)
        for (int i = 1; i < R; ++i) {
            for (int j = 1; j < C; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the corresponding row
                    matrix[0][j] = 0; // Mark the corresponding column
                }
            }
        }

        // Step 4: Zero out elements based on the markers in the first row/column
        // Iterate from (1,1) to (R-1, C-1)
        for (int i = 1; i < R; ++i) {
            for (int j = 1; j < C; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Zero out the first row if it originally had a zero
        if (firstRowHasZero) {
            for (int j = 0; j < C; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Zero out the first column if it originally had a zero
        if (firstColHasZero) {
            for (int i = 0; i < R; ++i) {
                matrix[i][0] = 0;
            }
        }
       
    }
};