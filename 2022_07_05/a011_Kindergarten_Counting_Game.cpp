//2ms, 316KB
#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
    int count(string str){
        int word = 0;
        bool is_alpha = false;
        for(int i = 0 ; i < str.length(); i++){
            if(isalpha(str[i])) is_alpha = true;
            else{
                if(is_alpha){
                    is_alpha = false;
                    word++;
                }
            }
        }
        return word + (int)is_alpha;
    }
};

int main(){
    string s;
    int num = 0;
    Solution ans;
    while(getline(cin, s)){
        cout << ans.count(s) << endl;
    }
}
