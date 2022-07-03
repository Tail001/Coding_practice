//0.5s, 540KB
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    while(cin >> n >> m){
        int a[n + 1];
        a[0] = 0;
        int input = 0;
        for(int i = 0;i < n;i++){
            cin >> input;
            a[i + 1] = a[i] + input;
        }
        for(int i = 0;i < m;i++){
            int begin, end;
            cin >> begin >> end;
            cout << a[end] - a[begin - 1] << endl;
        }
    }
}
