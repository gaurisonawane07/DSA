//optimal solution
//by using dutch national flag algorithm
//[0 to low-1]->0
//[low to mid-1]->1
//[high+1 to n-1]->2
#include<iostream>
#include<vector>

using namespace std;
void sortArray(vector<int>& arr, int n){
    int low = 0,mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid == 1]){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}