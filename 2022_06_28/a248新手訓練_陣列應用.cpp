//0.7s, 420KB
//practice vector
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int a, b, n;
    vector<int> store;
    while(cin >> a){
        cin >> b >> n;
        int r = a % b;
        cout << a / b << ".";
        
        for(int i = 0; i < n; i++){
            int temp;
            temp = (r * 10) / b;
            store.push_back(temp);
            r = (r * 10) % b;
        }
        for (auto &v : store) 
            cout << v ;
        cout << endl;
        store.clear();
    }

}
