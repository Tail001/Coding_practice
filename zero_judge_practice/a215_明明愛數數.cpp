//11ms, 320KB
#include<iostream>
using namespace std;
int main(){
    long int start, target;
    while(cin >> start >> target){
        long int sum = 0;
        for(int i = start;; i++){
            sum += i;
            if(sum > target) {
                cout << (i - start + 1) << endl;
                break;
            }
        }
    }

}