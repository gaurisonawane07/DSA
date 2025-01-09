/*basically there are three types of problems on pascals triangls
1.we have given position in row and column of the element and we have to find the element at that place*/

#include<iostream>
using namespace std;
int nCr (int n, int r){
    long long res = 1;
    for(int i = 0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

// 2. print any given row of pascal triangle

