/*Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result 
mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.*/

#include<bits/stdc++.h>
using namespace std;
int summation(vector<int>&nums,int num){
    int sum = 0;
    for(int i = 0;i<nums.size();i++){
        sum += ceil(nums[i]/num);
    }
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold){
    int n = nums.size();
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i = 0;i<n;i++){
        maxi = max(maxi , nums[i]);
        mini = min(mini,nums[i]);
    }
    int sum = 0;
    int low = mini;
    int high = maxi;
    while(low<= high){
        int mid = (low+high)/2;
        if(summation(nums,mid)<= threshold){
            int ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        

    }
}