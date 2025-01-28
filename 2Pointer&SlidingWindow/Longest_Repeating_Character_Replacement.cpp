/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.*/

//APPROACH:
//convert the numbers which are low frequency in substring
//the numbers that we need to convert are length - maxfrequency
//keep the track of maxfrequency and check if len-maxfreq <= k

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        int hash[26] = {0};
        while(r<s.size()){
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq,hash[s[r]- 'A']);

            if((r-l+1) - maxfreq > k){
                hash[s[l] - 'A'] --;
                maxfreq = 0;
                for(int i = 0;i<s.size();i++){
                    maxfreq = max(maxfreq,hash[i]);
                    l=l+1;
                }
            }
            if((r-l+1) - maxfreq <= k) {
                maxlen = max(maxlen,r-l+1);
                r++;
            }
        }
        return maxlen;
    }
};