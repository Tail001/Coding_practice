//10ms, 336KB
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num;
    cin >> num;
    vector<int> space;
    vector<int> time;
    for(int i = 0; i < num; i++){
        space.push_back(0);
        time.push_back(0);
    }
    int user, cd;
    while(cin >> user >> cd){
        bool find = false;
        // decide position:
        for(int i = 0; i < num ;i++){ // fiest part: find wheather is a perfect position
            if(space[i] == 0){
                if(i + 1 < num){
                    if(space[i + 1] != 0) continue;
                }
                if(i - 1 >= 0){
                    if(space[i - 1] != 0) continue;
                }
                space[i] = user;
                time[i] = cd;
                find = true;
                break;
            }
        }
        // second part : find a position, which is not space between.
        if(find == false){
            for(int i = 0; i < num; i++){
                if(space[i] == 0){
                    space[i] = user;
                    time[i] = cd;
                    find = true;
                    break;
                }
            }
        }
        if(find == false) cout << "Not enough" << endl; // not enough space
        //output part:
        cout << "Number: ";
        for(int i = 0; i < num; i++) cout << space[i] << " ";
        cout << endl << "Time: ";
        for(int i = 0; i < num; i++) cout << time[i] << " ";
        cout << endl;
        // time decreasing:
        for(int i = 0; i < num; i++){ 
            if(time[i] != 0)
                time[i]--;
            if(time[i] == 0) space[i] = 0; // take user away, letting next in
        }
    }
}