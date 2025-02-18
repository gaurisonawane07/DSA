//the function is calling itself until the specific condition meets
//the condition is konwn as base condition

#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void print(){
    if(cnt ==3) return; //BASE CONDITION
    cout<<cnt<<endl;
    cnt++;
    print();
}
int main(){
    print();
    return 0;
}

/*
RECURSION TREE:

          f()
          //
        f()
        //
      f()
      //
    f()  

*/

//STACK OVERFLOW

//where all functions remains unexecuted no specific condition meets