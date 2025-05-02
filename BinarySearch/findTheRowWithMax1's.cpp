//we have given a 2d array of 0's and 1's we have to find the row with
//maximum number of 1's

//optimal solution :
//we have to sorted array as each row so we have to find first index of occurance 
//after finding the lower bound, find the occurances of one by simply subtracting last index from first occuring index

#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr,int n,int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>= x){
            ans = mid;
            high = mid-1;
        } 
        else{
            low = mid+1;
        }
    }
    return ans;
}

int rowWithMaxIs(vector<vector<int>> &matrix, int n, int m){
    int cnt_max = 0;
    int index = -1;
    for(int i = 0;i<n;i++){
        int cnt_ones = m-lowerBound(matrix[i],m,1);
            if(cnt_ones>cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        
        return index;
    }
}