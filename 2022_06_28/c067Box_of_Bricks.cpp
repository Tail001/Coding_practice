//5ms, 324KB
#include<iostream>
using namespace std;
int main(){
    int count = 1;
    int n;
    while(cin >> n && n != 0){
        int a[n];
        int ans = 0, sum = 0, average = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        average = sum / n;
        for(int i = 0; i < n; i++){
            if(a[i] > average){
                ans += a[i] - average;
            }
        }
        cout << "Set #" << count << endl; 
        cout << "The minimum number of moves is " << ans << "."<< endl;
        count++;
    }
}

 