//4ms, 340KB
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
class Solution{
private:
    int freq = 0;
    int *freq_ptr = &freq;
    vector<long long int> res;
public:
    bool Is_Prime(long long int x){
        if(x == 1 || x == 0) return false;
        if(x == 2) return true; 
        for(int i = 2; i < sqrt(x) + 1; i++){
            if (x % i == 0) return false;
        }
        return true;
    }
    vector<long long int> Prime(string str){
        string tempstr = "";
        res.clear();
        for(int i = 0 ;i < str.length();i++){
            tempstr += str[i];
            if(Is_Prime(stoll(tempstr))){
                res.push_back(stoll(tempstr));
                tempstr = "";
                freq ++;
            }
        }
        return res;
    }
    void Print_Vector(vector<long long int> Prime){
        if(*freq_ptr == 0){
            cout << 0 << endl;
        }
        else{
            cout << *freq_ptr << endl;
            for(int i = 0; i < Prime.size() ; i++){
                cout << Prime[i] << endl;
            }
            cout << endl;
        }
        
        freq = 0;
    }
};
int  main(){
    string str;
    Solution ans;
    while(getline(cin, str)){
        vector<long long int> temp = ans.Prime(str);
        ans.Print_Vector(temp);
        temp.clear();
    }
    return 0;
}