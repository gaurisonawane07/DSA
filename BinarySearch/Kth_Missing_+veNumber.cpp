/*Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int low = 0;
            int high = arr.size()-1;
            while(low<=high){
                int mid = (low+high)/2;
                int missing = arr[mid] - (mid+1);
                if(missing<k){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            return (k+high+1);
        }
    };