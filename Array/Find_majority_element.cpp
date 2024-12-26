//you have given an array of integers and your task is to find the element that appears mmore than n/2 times
//Brute force: pick up an element search for an entire array , do count++ if the count is>n/2
// better solution: using hashing declare hashmap with (element,count) scan through the array 
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int majorityElement(vector<int> v){
    map<int,int>mpp;
    for(int i=0;i<v.size();i++){
       mpp[v[i]]++; 
    }
    for(auto it: mpp){
         //for iterating the map
         if(it.second > (v.size()/2)){
            return it.first;
         }
    
    }
    return -1;
}

//optimal solution moose voting algorithm
//two variables element and count initially count is 0
//take 1st element and make count 1
//take 2nd element if second element is equal to first increment count otherwise decrease count
//when in an array count is 0 then again take next element and start count from next element

#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>v){
   int cnt = 0;
   int el;
   for(int i = 0;i<v.size();i++){
      if(cnt == 0){
         cnt = 1;
         el =v[i];
      }
      else if(v[i] == el) {
         cnt++;
      }
      else{
         cnt--;
      }
   }
   int cnt1 = 0;
   for(int i=0;i<v.size();i++){
      if(v[i] == el) cnt1++;
   }
   if(cnt1 > (v.size()/2)){
      return el;
   }
   return -1;
}