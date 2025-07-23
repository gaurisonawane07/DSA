// variation 1:
//give row and column and find the element at that place
//the brute force solution is by using formula n!/r!*(n-r)!

#include<iostream>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}

//variation 2
//we have given n i.e.number of row and we have to print entire row n

#include<iostream>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}

//variation 3


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int col = 1;col<=row;col++){
            ans = ans * (row-col+1);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 0;i<numRows;i++){
            ans.push_back(generateRow(i));
           
        }
         return ans;
    }
};