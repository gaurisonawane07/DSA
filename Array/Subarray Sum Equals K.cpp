#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        long long prefSum = 0;
        map<long long,int>prefSumCount;
        prefSumCount[0] = 1;
        for(int i = 0;i<nums.size();i++){
            prefSum += nums[i];
            int remove = prefSum - k;
            count += prefSumCount[remove];
            prefSumCount[prefSum] += 1;

        }
        return count;
    }
};