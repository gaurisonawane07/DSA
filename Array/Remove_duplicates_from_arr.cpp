//brute force approach
//define a set data structure and put all elements one by one into it
//set does not accept duplicates
//set<int>st
//for (i=0;i<n;i++) st.insert(arr[i])
// time complexity: NlogN + N
//optimal solution: Two pointer approach
//i=0; for (j=1;j<n;j++){
//if (arr[j] != arr[i])
//{
//arr[i+1] = arr[j];
//i++}} -> return(i+1)
#include <iostream>
#include <vector>
using namespace std;


int removeduplicates(vector<int> &arr, int n) {
    if (n == 0) return 0; 
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i+1] = arr[j];
        }
    }
    return i + 1; 
}

int main() {
    int n;
    cout << "Enter the total number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Number of elements must be positive." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the elements (sorted in non-decreasing order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newSize = removeduplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}