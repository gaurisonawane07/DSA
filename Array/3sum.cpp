/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/


//Brute Force: try out every triplet
//take three pointers i,j,k , check if(arr[i]+arr[j]+arr[k])

//BRUTE FOrce CODE
#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for(int i =0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                for(int k = j+1;k<nums.size();k++){
                    if(nums[i] + nums[j] + nums[k] == 0);
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

//better solution
//i+j+k = 0
//k= -(i+j)
//replace last for loop
#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
using namespace std;
class Solution{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for(int i = 0;i<nums.size();i++){
            set<int>hashset;
            for(int j = i+1;j<nums.size();j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;

    }

};

//optimal solution
//first sort the entire array
//using two pointer approach
#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Step 1: Sort the array

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Step 2: Skip duplicate elements

            int left = i + 1, right = nums.size() - 1; // Step 3: Two-pointer initialization
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Step 4: Skip duplicate elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;  // Increase left to get a larger sum
                } 
                else {
                    right--; // Decrease right to get a smaller sum
                }
            }
        }
        return ans;

    }
};