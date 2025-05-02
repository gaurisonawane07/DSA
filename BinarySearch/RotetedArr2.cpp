/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
 such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
 For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.*/

// it is same as search in sorted array but in this the array might contains duplicate elements 
//in this we do not have to write the index, we have to write true if the target is found otherwise we have to write false

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int low = 0;
            int high = n-1;
            while (low<= high)
            {
                int mid = (low+high)/2;
                if(nums[mid] == target) return true;
                if(nums[low]==nums[mid]&& nums[mid]==nums[high]){ //additional condition
                    low = low+1;
                    high = high-1;
                    continue;
                }
                if(nums[low]<= nums[mid]){
                    if(nums[low]<=target && nums[mid]>= target){
                        high= mid-1;

                    }
                    else{
                        low = mid+1;
                    }
                }
                else{
                    if(nums[mid]<= target && nums[high]>= target ){
                        low = mid+1;

                    }
                    else{
                        high = mid-1;
                    }
                }
            }
            return false; 
            


            
        }
       
};