//2ms, 336KB
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
class Solution{
public: 
    int spilt_string_to_int(string str){
            set<char> optr = {'+', '-', '*', '/', '%'};
            char user_optr;
            string tempstr = "";
            vector<int> vtint;
            int i, res = 0;
            for(i = 0; i < str.length(); i++){
                if(optr.count(str[i])){
                    user_optr = str[i];
                    break;
                }
                if(isdigit(str[i])){
                    tempstr += str[i];
                }
            }
            vtint.push_back(stoi(tempstr));
            tempstr = "";
            for(int j = i + 1;j < str.length();j++){
                if(isdigit(str[j])){
                    tempstr += str[j];
                }
            }
            vtint.push_back(stoi(tempstr));
            if(user_optr == '+'){
                res = vtint[0] + vtint[1];
            }
            else if(user_optr == '-'){
                res = vtint[0] - vtint[1];
            }
            else if(user_optr == '*'){
                res = vtint[0] * vtint[1];
            }
            else if(user_optr == '/'){
                res = vtint[0] / vtint[1];
            }
            else {
                res = vtint[0] % vtint[1];
            }
            return res;
        }
};
int main(){
    int num;
    string s;
    Solution a;
    cin >> num ;
    while(num--){
        cin >> s;
        int ans = a.spilt_string_to_int(s);
        cout << ans << endl;
    }
    return 0;
}