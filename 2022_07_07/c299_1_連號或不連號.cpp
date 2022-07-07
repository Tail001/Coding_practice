//12ms, 344KB
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
    int user_arr[1000];
public:
    int is_continue(int *n){
        for(int i = 0; i < *n; i++){
            cin >> user_arr[i];
        }
        sort(user_arr, user_arr + *n);
        cout << user_arr[0] << " " << user_arr[*n - 1] << " ";
        for(int i = 0 ; i < *n - 1;i++){
            if(user_arr[i] + 1 != user_arr[i + 1]){
                cout << "no" << endl;
                return 0;
            }
        }
        cout << "yes" << endl;
        return 0;
    }

};
int main() {
   int n;
   Solution ans;
   while(cin >> n){
        ans.is_continue(&n);
   }
}
