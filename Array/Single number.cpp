/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.*/

//BRUTE FORCE: iterate through all the arrays and take cnt = 0;if num == arr[j]; cnt ++; if cnt =o;return num

//better approach:by using hashing or map 
//better approach 1
// for hashing
#include <vector>        
#include <map>           
#include <unordered_map>
#include <iostream> 
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0;i<nums.size();i++){
            maxi = max(nums[i],maxi); 
        }
        vector<int> hash(maxi + 1, 0);
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i = 0;i<nums.size();i++){
            if(hash[nums[i]] == 1){ //if value of any element is 1
                return nums[i];
            }
        }
        return -1;
    }
};

//better approach 2
//by using map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <long long , int>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;

        }
        for(auto it :mpp){
            if(it.second == 1){//it.second means value in the key value pair if its value is 1 means it appears only once 
                return it.first;//it returns key
            }
        }
        return -1;
    }
};

//optimal solution 
//by using XOR
//xor operation eliminates all the elements which appears twice means 1^1 = 0 2^2=0 and written answer as the element which appears twice

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for(int i = 0;i<nums.size();i++){
            XOR = XOR ^ nums[i];
           
        }
         return XOR;
    }
    
};