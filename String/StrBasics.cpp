//strings are dynamic in nature => It can resize at runtime
/*#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    cout<<"String is:"<<str<<endl;

    string str = "DO DSA ANYWAY";
    for(int i = 0;i<str.length();i++){
        cout<<str[i]<<endl;
    }
    return 0;
}*/

//REVERSE A STRING
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string str = "YOU CAN DO IT";
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}
