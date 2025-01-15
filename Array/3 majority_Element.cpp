/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/

//brute force: pick up an integer and iterate through the array and find if the element occurs is more then n/3 times
//better solution : we are using hashmap
//take pair of number and count in the hashmap if first number is appear twice go ahead and increase the count
//ones you iterate through the entire array your hashmap wiill contain every unique element and its count

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> majorityElement(vector<int> v) {
    vector<int> ls;
    map<int,int>mpp;
    int n = v.size();
    int mini = (int)(n/3)+1;
    for(int i = 0;i<n;i++){
        mpp[v[i]]++;
        if(mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }
        if(ls.size() == 2) break;

    }
    sort(ls.begin(), ls.end());
    return ls;
}

//optimal algorithm:
/*APPROACH:
1.Find Two Candidates:
Use two variables (el1 and el2) to store the two possible majority elements.
Use two counters (cnt1 and cnt2) to track their frequencies.

2.Traverse the array:
If cnt1 is 0, set el1 to the current number and reset cnt1 to 1.
If cnt2 is 0 (and the number isn't el1), set el2 to the current number and reset cnt2 to 1.
If the number matches el1 or el2, increment the respective counter.
Otherwise, decrement both counters.

3.Verify the Candidates:
After the first pass, the candidates (el1 and el2) might not actually appear more than n/3 times.
Count the occurrences of both candidates in a second loop.

4.Check the Threshold:
If either candidate appears more than n/3 times, add it to the result.
*/
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0,cnt2=0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for(int i =0;i<nums.size();i++){
            if(cnt1 == 0 && el2 !=nums[i] ){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--,cnt2--;
            }

        }
        vector<int>ls;
        cnt1 = 0, cnt2 =0;
        for(int i =0;i<nums.size();i++){
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }
        int mini = (int)(nums.size()/3)+1;
        if(cnt1>= mini) ls.push_back(el1);
        if(cnt2>= mini) ls.push_back(el2);
        sort(ls.begin(),ls.end());
        return ls;
    }
};