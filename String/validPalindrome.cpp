//check whether string is palindrome or not by : converting all uppercase letters into lowercase letters 
//and removing non-alphanumeric characters
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int st = 0;
        int end = n-1;
        while(st<end){
        while((st<end) && !isalnum(s[st])) st++; // isalnum is a standard function chack whether character is alphanumeric or not
        while((st<end) && !isalnum(s[end])) end--;
        if(tolower(s[st]) != tolower(s[end])){
            return false;
        }
        st++;
        end--;
        }
        return true;
    }
};