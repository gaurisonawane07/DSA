//binary search is only applicable on sorted array
//split the half to find the element
//mid = low+high/2
//compare mid with target element
//if mid<target ; low = mid+1
//if mid>target ; high = mid-1

//ITERATIVE CODE (while loop)

#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr,int target){
    int low = 0;
    int high = 0;
    while(low<= high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;
        else if(target>arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        return -1;
    }
}

//RECURSIVE CODE
