//we have to find occurance of each character in the string

#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;

    //pre compute
    int hash[26] = {0};//if there are upper case letters also then we have to take size 256 of hashmap
    for(int i = 0;i<s.size();i++){
        hash[s[i]-'a']++;//it subtracts ascii number of eacg element from ascii number of a then index is stored in hash
    }

    int q;
    cin>>q;
    while(q--){
        int c;
        cin>>c;
        //fetch
        cout<<hash[c-'a']<<endl;
    }
    return 0;
}