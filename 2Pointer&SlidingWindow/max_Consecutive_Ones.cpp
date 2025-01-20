// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int zeros = 0;
        int maxlength = 0;
        while(r<nums.size()){
            if(nums[r] == 0) zeros++;
            if(zeros > k) {
                if(nums[l] == 0) zeros--;
                l++;

            }
            if(zeros<=k){
                int len = r-l+1;
                maxlength = max(len,maxlength);
                
            }
            r++;                
        }
        return maxlength;
    }
};