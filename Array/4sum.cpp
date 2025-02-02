/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

//brute force

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    for(int l = k+1;l<n;l++){
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if(sum == target) {
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;

    }
};

//optimal solution
//eliminate fourth for loop
//nums[l] = target-(nums[i]+nums[j]+nums[k])

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int n = nums.size();
        set<vector<int>>st;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                set<long long>hashset;
                for(int k = j+1 ;k<n;k++){
                    long long fourth = target-(nums[i]+nums[j]+nums[k]);
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k],static_cast<int>(fourth)};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;

    }

};

//optimal solution
//first sort the given array
//we need to find out four elements i,j,k,l
//we will fixe two i & j and run two pointers
//i,j,k are at the starting positions and l is at last position 
//we will check for the sum
//ignore duplicates by comparing it with previous

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<n;j++){
                if(j!= i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;

                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

