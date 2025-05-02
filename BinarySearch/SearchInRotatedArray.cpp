/*There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
 */

//BRUTE FORCE
//iterate through the whole array and find the target element

//In this problem since the array is rotated the ine half of the array cannot be completely sorted
//so , we cannot check in just one half
//KEY POINT: check which half is sorted
//compare lower value with mid and check if it is smaller then mid and compare high with mid and check if it is greater

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int low = 0;
            int high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid] == target) return mid;
                if(nums[low]<= nums[mid]){
                    if(nums[low]<= target && target<= nums[mid]){
                        high = mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                else{
                    if(nums[mid] <= target && nums[high]>= target){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                return -1;
            }
        }
    };