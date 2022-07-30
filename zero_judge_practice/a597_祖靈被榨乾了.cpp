//0.6s, 724KB
#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Solution{
    vector<string> map;
    int groups = 0, max_size = 0;
public:
    Solution(int R, int C){
        for(int i = 0; i < R; i++){
            string str;
            cin >> str;
            map.push_back(str);
        }
    }
    pair<int, int> BFS(int R, int C){
        const int x_dir[] = {0, 1, 0, -1},  y_dir[] = {1, 0, -1, 0}; // determine direction
        for(int i = 0 ; i < R; i++){
            for(int j  = 0 ; j < C ; j++){
                if(map[i][j] == 'J'){
                    map[i][j] = 'X'; // prevent to be tracked again
                    groups ++;
                    queue<pair<int, int>> q; //queue for BFS
                    int size = 0;
                    q.push({i, j});
                    while(!q.empty()){ // queue is not empty -> continue else break
                        auto current = q.front();
                        size ++;
                        q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int dir_i = current.first + x_dir[dir];
                            int dir_j = current.second + y_dir[dir];
                            if(dir_i >= 0 && dir_i < R && dir_j >= 0 && dir_j < C && map[dir_i][dir_j] == 'J'){
                                map[dir_i][dir_j] = 'X';
                                q.push({dir_i, dir_j});
                            }
                        }
                    }
                    max_size = max(max_size, size); // find the largest one
                }
            }
        }
        pair<int, int> res(groups, max_size);
        return res;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); // To fasten this code, not very vital at all
    int row, col;
    while(cin >> row >> col){
        Solution ancestor(row, col);
        cout << ancestor.BFS(row, col).first << " " << ancestor.BFS(row, col).second << endl;
    }
    return 0;
}