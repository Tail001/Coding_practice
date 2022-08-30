//3ms, 328KB
#include<iostream>
#include<string>
using namespace std;

int main(){
    int obj;
    int exp = 0 , down;
    while(cin >> obj){
        for(down = 2 ; down <= obj ; down++){
            exp = 0;
            while(obj % down == 0){
                exp++;
                obj /= down;
            }
            if(exp > 1){
                cout << down << "^" << exp;
                if(obj > 1){
                    cout << " * ";
                }
            }
            else if(exp == 1){
                cout << down;
                if(obj > 1){
                    cout << " * ";
                }
            }
            if(obj == 1){
                cout << endl;
                break;
            }
        }
    }
    return 0;
}