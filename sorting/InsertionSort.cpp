//This is the easiest sorting technique 
//in which we take sorted and unsorted part of the array take each element and place it in its correct position
//its not optimal and efficient
//in worst case it can take n^2 operations
//it swap the element with its neighbouring element
#include<bits/stdc++.h>
using namespace std;
int arr[] = {1,4,6,2,3};
int main(){
    int n = 5;
int arr[] = {1,4,6,2,3};
for(int i = 0;i < arr.size();i++){
    int position = i;
    while(arr[position]<arr[position]-1){
        swap(arr[position],arr[position-1])
    }
}
}