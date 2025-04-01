//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 #include<bits/stdc++.h>
 using namespace std;
 class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            int count = 0;
            map<int,int>mpp;
            for(int n: nums){
                if(mpp.count(n)>0){
                    return true;
                }
            }
            return false;
        }
    };