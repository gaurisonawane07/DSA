//we have to print the number of substrings which contains all three characters

//brute force:
//traverse through the array and find all the possible substrings
/* 
cnt = 0;
for(i=0->n)
{
hash[3] = {0}
}
for(j=i->n){
hash[s[j] - 'a'] = 1;
if(hash[0]+hash[1]+hash[2] == 3){
cnt = cnt+(n-j) break;
}
}
*/

//optimal:
/* Approach:
Track Last Seen Indices:
Use an array lastseen[3] to store the last seen indices of the characters 'a', 'b', and 'c' in the string s.
Iterate Over the String:
For each character in the string:

Update its corresponding position in the lastseen array based on its ASCII value (s[i] - 'a').
Check Valid Substring Condition:
If all three characters ('a', 'b', 'c') have been encountered at least once (lastseen[0], lastseen[1], lastseen[2] are not -1):

Find the minimum index among them (min({lastseen[0], lastseen[1], lastseen[2]})).
Add 1 + minimum index to the count of valid substrings.
Return the Total Count:
After the loop, return the total count of substrings containing at least one of each character.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseen[3] = {-1,-1,-1};
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            lastseen[s[i] - 'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                cnt += 1+ min({lastseen[0],lastseen[1],lastseen[2]});

            }
            return cnt;
        }
    }
};