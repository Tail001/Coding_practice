//2ms, 340KB
#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
    string Palindrome(string str){
        string reverse = str;
        if(str.length() == 1) return "yes";
        for(int i = 0; i < str.length() / 2; i++){
            if(str[i] != str[str.length()-i-1]){
                return "no";
            }
        }
        return "yes";
    } 
};
int main(){
    Solution ans;
    string str;
    while(cin >> str){
        cout << ans.Palindrome(str) << endl;
    }
}