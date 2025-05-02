#include<bits/stdc++.h>
using namespace std;
    int findmax(vector<int>&v){
        int maxi = INT_MIN;
        for(int i = 0;i<v.size();i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }
    
    int calculateTotalHours(vector<int> &v,int h){
        int totalh = 0;
        int n = v.size();
        for(int i = 0;i<n;i++){
            totalh += ceil((double)(v[i])/(double)(h));

        }
        return totalh;
    }
    
    int findMin(vector<int>& v,int h){
            int n = v.size();
            int low = 1;
            int high = findmax(v);
            while(low<=high){
                int mid = (low+high)/2;
                int totalh = calculateTotalHours(v,mid);
                if(totalh <= h){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            return low;
    }

