//map contains key value pairs map<int,int>
//key is a number and value is frequency of that number
//map stores all the values in sorted order

//find the occurance of query elements by using map

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    //pre compute
    map<int, int> mpp;
    for(int i = 0;i<n;i++) {
        mpp[arr[i]]++;
    }
   

    int q;
    cin>>q;
    while(q--) {
        int number;
        cin>>number;
        //fetch
        cout<< mpp[number] << endl;
    }
    return 0;
}
