#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    map<int, string> testmap = {
        {1,"hello"},
        {2,"not hello"}
    };
    cout << testmap.containsKey("hello") << endl;
}
