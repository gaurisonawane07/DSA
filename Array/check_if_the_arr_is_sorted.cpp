#include<iostream>
#include<vector>
using namespace std;

int isSorted(int n, vector<int> a){
    for(int i = 0;i<n-1;i++){
        if(a[i] >= a[i+1]){
            cout<<"array is not sorted"<<endl;
            return false;
        }
        cout<<"array is sorted"<<endl;
        return true;
    }
}
int main(){
    int n;
    cout<<"Enter number of elements in an array"<<endl;
    cin>>n;
    vector<int> a(n);
    cout<<"Enter elements in an array";
    for(int i = 0 ;i<n;i++){
        cin>>a[i];

    }
    return isSorted(n,a);
    return 0;
}