#include<iostream>
#include<string>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    stack<int> a;
    for(int i = 0; i < 3; i++){
        a.push(i);
    }
    cout << a.empty() << endl;
    for(int i = 0; i < 3; i++){
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
    cout << a.empty() << endl;
    return 0;
}
