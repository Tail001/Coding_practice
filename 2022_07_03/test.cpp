#include <iostream>
#include <string>
#include<math.h>
using namespace std;
bool Is_Prime( long long int x){
        if(x == 1) return false;
        if(x == 2) return true; 
        for(int i = 2; i < sqrt(x) + 1 ; i++){
            if (x % i == 0) return false;
        }
        return true;
}
int main() {
    long long int a = 8888888809;
    cout << Is_Prime(a);

}