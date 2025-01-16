#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mpp;
        for(int num : arr){
            if(num>=1 && num<=n){
                mpp[num]++;
            }
        }
        vector<int> result(n,0);
        for(int i =0;i<=n;i++){
            result[i-1] = mpp[i];
        }
        
        return result;
        
    }
};