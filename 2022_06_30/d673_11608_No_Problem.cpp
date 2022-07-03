//2ms, 328KB
#include<iostream>
using namespace std;
int main()
{
    int s;
    int count = 1;
    int a[12], b[12];
    while(cin >> s){
        if(s < 0)
            break;
        for(int i = 0; i < 12;i++){
            cin >> a[i];
        }
        for(int i = 0; i < 12;i++){
            cin >> b[i];
        }
        cout << "Case " << count++ << ":" << endl;
        for(int i = 0;i < 12;i++){
            
            if(s >= b[i]){
                cout << "No problem! :D" << endl;
                s -= b[i];
            }
            else{
                cout << "No problem. :(" << endl;
            }
            s += a[i];
        } 
    }
}