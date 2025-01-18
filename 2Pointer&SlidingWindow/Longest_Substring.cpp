/*here we use sliding window approach it is not a specific algorithm we tke two pionters one is at the first index initially and 
second keep moving until duplicate element not find and stores the element with their index in an map ones we found the duplicate 
element we move the first pointer and then again check*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        memset(hash, -1, sizeof(hash)); // Initialize all elements to -1
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while(r<n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >=l){
                    l = hash[s[r]] +1;
                }
            }
            int len = r-l+1;
            maxlen = max(len,maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;

    }
};