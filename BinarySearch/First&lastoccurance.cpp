/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.*/

//BRUTE FORCE:
//iterating through every element of the array
//take two integers first and last and change the value of first and last when found the first target value 
//and after that update the value of last

//optimal solution:Using binary search
//we can calculated usin lower bound which is the first occuring index
//and (upper bound - 1) which is the last occuring index in the array 

//writiing bs code without using lower bound and upper bounds codes

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lowerBound(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    int upperBound(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    vector<int> searchRange(const vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        int end = upperBound(nums, target);
    
        if (start == end) {
            return {-1, -1}; 
        } else {
            return {start, end - 1};
        }
    }
    };

