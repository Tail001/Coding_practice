//2ms, 308KB
#include<iostream>
#include<vector>
using namespace std;
class Binary_Convert{
    vector<int> res;
public:
    void Convertion(int num){
        while(num >= 2){ // less than 2 will break this loop
            int remender = num % 2;
            num /= 2;
            res.push_back(remender);
        }
        res.push_back(num);
    }
    void Get(){
        for(int i = res.size() - 1; i >= 0; i--){
            cout << res[i];
        }
        cout << endl;
    }
};
int main(){
    int num;
    while(cin >> num){
        Binary_Convert binary;
        binary.Convertion(num);
        binary.Get();
    }
}