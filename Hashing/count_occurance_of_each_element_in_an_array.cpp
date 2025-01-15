//we have given an size of the array and elements in an array
//also given number of queries and query elements we have to find that each query number occurs how many times in an array

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++) {
        cin>>arr[i];
    }
    //precompute

    int hash[13] = {0};
    for(int i = 0;i<n;i++) {
        hash[arr[i]] += 1;
    }


    int q;
    cin>>q;
    while(q--) {
        int number;
        cin>>number;
        //fetch

        cout<<hash[number]<<endl;
    }
}