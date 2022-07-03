// 88ms, 316KB
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int length, reverse = 0, count = 1;
    while(cin >> length){
        int temp = 0;
        for(int i = 0; i < length ; i++){
            if(!reverse){ //normal
                for(int i = 0;i < length; i++ ){
                    cout << count++ << " ";
                }
                cout << endl;
            }
            else{
                for(int i = 0;i < length; i++ ){
                    int ans = count + length - temp - 1;
                    cout << ans << " ";
                    count++;
                    temp += 2;
                }
                cout << endl;
                temp = 0;
            }
            reverse = (reverse + 1) % 2;
        }
        count = 1;
        reverse = 0;
    }
}
