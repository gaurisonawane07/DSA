//1st problem
//you have given an array of integers and a target value your task is to write yes if there exist two numbers whose sum is target value else write no
//2nd problem
//to find these two elements whose sum is target value and write their indexes
//brute force: take first element andcheck its sum with every other element then take second and do the same
//for(i=0;i<n;i++){ for(j=i+1;j<n;j++)}
//if(i==j) continue;
//if(arr[i]+arr[j]==target)
//time complexity O(n2) 
//optimal solution
//by using hashing
//take hashmap and in hashmap store array element and index 
//now suppose first element is 2 and target is 14 we required 12 for addition =14 then check if 12 present in hashmap or not
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int more = target - a;
            if (mpp.find(more) != mpp.end()){
                return {mpp[more],i};
            }
            mpp[a] = i;
        }
        return {-1,-1};
    }
    
};