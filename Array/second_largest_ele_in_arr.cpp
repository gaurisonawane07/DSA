// *******brute force solution
// sort athe array and and start iterating from (n-1) and chck if element!=largest
// time complexity sorting = NlogN+N
// ********Better solution
// in first pass we find the largest element
// now keep second_largest = -1
// start iterating and checl if i>second_largest && i!=largest;
// second_largest = -1
// for(i=0;i<n;i++){if(arr[i]>second_largest && arr[i]!=largest)}
// second_largest = arr[i]
// time complexity = O(2n)
// ********optimal solution
//largest = arr[0], slargest = -1

#include <iostream>
#include <vector>
using namespace std;

int secondLargest(vector<int> &a, int n) {
    if (n < 2) {
        return -1; // or throw an exception
    }

    int largest = a[0];
    int slargest = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            slargest = largest;
            largest = a[i];
        } else if (a[i] < largest && a[i] > slargest) {
            slargest = a[i];
        }
    }

    if (slargest == -1) {
        return -1; 
    }

    return slargest;
}

int main() {
    int n;
    cout << "Total number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements in an array:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = secondLargest(a, n);
    if (result == -1) {
        cout << "There is no second largest element." << endl;
    } else {
        cout << "Second largest element: " << result << endl;
    }

    return 0;
}