/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, 
the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.*/

//Brute Force: Generate all the permutations , write it in sorted order ,the next index permutation will be your answer
//time complexity : ~10^12 extremely high
//Better approach : use STL next_permutation(A.begin(),A.end());return A
//this stl will automatically generate next permutation
//interviewer might be ask how to generate this stl 

//optimal solution:
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return; 
        }
        
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[index], nums[i]);
                break;
            }
        }
        
        reverse(nums.begin() + index + 1, nums.end());
    }
};
