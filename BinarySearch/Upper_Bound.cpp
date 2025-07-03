//find smallest index such that arr[index]>target

/*Given a sorted array arr[] (with unique elements) and an integer k, find the index (0-based) of the largest element in arr[] that is greater than or equal to k. This element is called the "floor" of k. If such an element does not exist, return -1.*/
//smallest index such that arr[ind]>=n

//APPROACH
//using binary search take low pointer at index 0 and high at last index

#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] > target) { 
            ans = mid;  
            high = mid - 1;  
        } else {
            low = mid + 1;
        }
    }
    return ans; 
}   

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 5;
    cout << "Index of first occurrence of target or the smallest greater element: " << binarySearch(arr, target) << endl;
    return 0;
}
