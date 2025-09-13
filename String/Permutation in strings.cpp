#include<iostream>
using namespace std;

class Solution {
public:
    bool isFreqSame(int freq1[],int freq2[]){
        for(int i = 0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0;i<s1.length();i++){
            int idx = s1[i]-'a';
            freq[idx]++;
        }
        int winsize = s1.length();
        for(int i = 0;i<s2.length();i++){
            int winidx = 0 , idx = i;
            int winfreq[26] = {0};

            while(winidx<winsize && idx<s2.length()){
                winfreq[s2[idx]-'a']++;
                winidx++;
                idx++;
            }
            if(isFreqSame(freq,winfreq)){//found
                return true;
            }
        }
        return false;
        
    }
};