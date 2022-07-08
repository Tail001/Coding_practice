//2ms, 332KB
#include<iostream>
#include<string>
using namespace std;
class Solution{
    int key = 7;
public:
    void Convert_Code(string str){
        for(int i = 0; i < str.length(); i++){
            cout << (char)(str[i] - key) ;
        }
    }
};
int main(){
    Solution ans;
    string str;
    while(getline(cin, str)){
        ans.Convert_Code(str);
    }
}