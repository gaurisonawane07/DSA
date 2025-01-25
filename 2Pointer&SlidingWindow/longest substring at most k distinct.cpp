/*in this problem we have to find the longest substring with at most k distinct characters*/

//Brute force
//strat with first character and push it into map with its frequency
//when map.size()> k erase the map and start eith next element to find the longest substring

//Better solution
//by using two pointers and sliding window
//take left pointer,right pointer,map,maxlength

//optimal solution

#include<bits/stdc++.h>
using namespace std;
class solution {
    public:
    int longestSubstring(vector<int>& num ,int k){
        int l = 0;
        int r = 0;
        int maxlength = 0;
        map<int,int>mpp;
        while (r<num.size())
        {
            mpp[num[r]]++;
            if(mpp.size()>k){
            mpp[num[l]]--;
            if(mpp[num[l]] == 0) mpp.erase(num[l]);
            l++;
        } 

        if(mpp.size()<k) maxlength = max(maxlength,r-l+1);
        r++;
        }
        return maxlength;
    }
};