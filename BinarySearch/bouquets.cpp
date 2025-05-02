/*You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.*/

//impossible case = m*k>n, flowers required to make m bouquets are less 

#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>& bloomDay,int day, int m, int k){
    int nofb = 0;
    int n = bloomDay.size();
    int counter = 0;
    for(int i = 0;i<n;i++){
        if(bloomDay[i]<= day){
            counter++;
        }
        else{
            nofb += (counter/k);
            counter = 0;

        }
    }
    nofb += (counter/k);
    return nofb >= m;
}
//for brute force here,iterate through the array 
//for optimal solution use binary search

int minDays(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    long long val = m*k;
    if(val>n){
        return -1;
    }
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i =0 ;i<n;i++){
        maxi = max(maxi,bloomDay[i]);
        mini = min (mini,bloomDay[i]);
    }
    int low = mini;
    int high = maxi;
    while(low<=high){
        int mid = (low+high)/2;
        if(possible(bloomDay,mid,m,k)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
