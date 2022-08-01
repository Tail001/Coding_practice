//63ms, 328KB
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Water{
    vector<vector<int>> map;
    int row, col;
public:
    Water(int r, int c){
        this -> row = r;
        this -> col = c;
        for(int i = 0; i < r; i++){
            map.push_back(vector<int>());
            for(int j = 0; j < c; j++){
                int temp;
                cin >> temp;
                map[i].push_back(temp);
            }
        }
    }
    void BFS(int type){
        const int dir_i[] = {-1, 0, 1, 0}, dir_j[] = {0, 1, 0, -1}; // dertermine direction
        int hole = 0;
        queue<pair<int, int>> q;
        while(map[0][hole] != 1) hole++;
        q.push({0, hole});
        while(!q.empty()){
            pair<int, int> current = q.front();
            q.pop();
            for(int dir = (type == 1)? 0 : 1; dir < 4; dir++){
                int i_axis = current.first + dir_i[dir];
                int j_axis = current.second + dir_j[dir];
                if(i_axis >= 0 && i_axis < row && j_axis >= 0 && j_axis < col){
                    if(map[i_axis][j_axis] == 1 && !(i_axis == 0 && j_axis == hole)){ // avoid the original one
                        map[i_axis][j_axis] = map[current.first][current.second] + 1;
                        q.push({i_axis, j_axis});
                    }
                }
            }
        }
    }
    void Display(){
        for(int i = 0; i < col; i++){
            cout << map[0][i] << " ";
        }
        cout << endl;
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                if(map[i][j] != 1) cout << map[i][j] << " ";
                else  cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main(){
    int type, row, col, count = 1;
    while(cin >> type){
        cin >> row >> col;
        Water water(row, col);
        cout << "Case " << count << ":" << endl;
        water.BFS(type);
        water.Display();
        count++;
    }
}