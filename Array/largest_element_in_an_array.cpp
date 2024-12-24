//to find the largest element in an array
//Brute force solution : sort the array and print last element

//optimal solution : initially largest = a[0] start iterating
//largest = a[0]
//for(i=0;i<n;i++) if (a[i]>largest) largest = a[i], print largest
//time complexity = O(n)

#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int> &arr, int n){
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    
    int largest = arr[0];
    
    
    for(int i = 1; i < n; i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }

    
    cout << "The largest element is: " << largest << endl;

    return largest;
}

int main() {
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;

    vector<int> arr(n);
    
    
    largestElement(arr, n);

    return 0;
}