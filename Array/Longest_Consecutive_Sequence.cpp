/*There is an integer array ‘A’ of size ‘N’.
A sequence is successive when the adjacent elements of the sequence have a difference of 1.
You must return the length of the longest successive sequence.
Note:
You can reorder the array to form a sequence.*/

//Brute force approach: staart iterating from first element anf find its consecutive next then start from second element and fine its consecutive next

/*OPTIMAL SOLUTION: 
1.use an unordered set to store all elements of the array for 0(1) lookup
2.for each element,check if it is a start of a sequence(i.e. it-1 is not in the set)
3.if it is a start of the sequence,count the length of that sequence by iterating through the consecutive elements
4.keep track of max sequence length*/
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int longestSuccessiveElements(vector<int>&a){
    int n = a.size();
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int>st;
    for(int i =0;i<n;i++){
        st.insert(a[i]);
    }
    //iterate in the set
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                x = x+1;
                cnt += 1;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}