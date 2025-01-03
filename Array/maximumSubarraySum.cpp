//kadanes algorithm
/*approach: take variable sum = 0
varible max which contains one max element initially max=a[0]
increment sum by adding next element to it
find the maximum between maximum and sum and store it into maximum
if sum<0 take sum = 0*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int maxSubArray(vector<int>& nums){
        int sum = 0;
        int maxi = nums[0];
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(sum,maxi);
            if(sum<0) sum =0;

        }
        return maxi;
    }
    
};