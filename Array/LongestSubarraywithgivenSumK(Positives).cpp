/*
First, we will declare a map to store the prefix sums and the indices.
Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
For each index i, we will do the following:
We will add the current element i.e. a[i] to the prefix sum.
If the sum is equal to k, we should consider the length of the current subarray i.e. i+1. We will compare this length with the existing length and consider the maximum one.
We will calculate the prefix sum i.e. x-k, of the remaining subarray.
If that sum of the remaining part i.e. x-k exists in the map, we will calculate the length i.e. i-preSumMap[x-k], and consider the maximum one comparing it with the existing length we have achieved until now.
If the sum, we got after step 3.1, does not exist in the map we will add that with the current index into the map. We are checking the map before insertion because we want the index to be as minimum as possible and so we will consider the earliest index where the sum x-k has occurred. [Detailed discussion in the edge case section]
*/


#include <iostream>
#include<vector>
#include<map>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// the above solution will be optimal if the array contains negatives also
//but if the array contains only  positives and zeros then the optimal solution will be by using two pointers 

#include <iostream>
#include<vector>
#include<map>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int left = 0, right=0;
    long long sum = a[0];
    int maxlen = 0;
    int n = a.size();
    while(right<n){
        while(left<=right && sum>k){
            left -= sum;
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen,right-left+1);
        }
        right++;
        if(right<n){
            sum += a[n];
        }
        return maxlen;
    }
}

