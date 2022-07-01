//73ms, 376KB
#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){   //n-- is better
        int dim, option; 
        int dir;
        // 0右1下2左3上 clockwise
        // 1下0右3上2左
        cin >> dim >> option;
        int a[dim][dim];
        int x = -1, y = -1; //position
        int step = dim - 1;
        int count = 0;
        //first
        for(int i = 0;i < dim; i++){
            count++;
            if(option == 1){ //clockwise
                dir = 0;
                a[0][i] = count;
                y++; 
                x = 0;
            }
            else{ //counterclockwise
                dir = 1;
                a[i][0] = count;
                x++; 
                y = 0;
            }
        }
        int time = (dim - 1) * 2;
        int change = 0; 
        //remaining
        for(int i = 0; i < time; i++){
            if(option == 1){  //clockwise
                dir = (dir + 1) % 4; // clockwise
                if(dir == 0){ //go right
                    for(int i = 0; i < step;i++){
                        count++;
                        a[x][++y] = count;
                    }
                }
                else if(dir == 1){ // go down
                    for(int i = 0;i < step; i++){
                        count++;
                        a[++x][y] = count;
                    }
                }
                else if(dir == 2){ // go left
                    for(int i = 0;i < step; i++){
                        count++;
                        a[x][--y] = count;
                    }
                }
                else{ // go  up
                    for(int i = 0;i < step; i++){
                        count++;
                        a[--x][y] = count;
                    }
                }    
            }

            else{ //counterclockwise
                dir = (dir + 3) % 4; // counterclockwise
                if(dir == 0){
                    for(int i = 0; i < step;i++){
                        count++;
                        a[x][++y] = count;
                    }
                }
                else if(dir == 1){ // go down
                    for(int i = 0;i < step; i++){
                        count++;
                        a[++x][y] = count;
                    }
                }
                else if(dir == 2){ // go left
                    for(int i = 0;i < step; i++){
                        count++;
                        a[x][--y] = count;
                    }
                }
                else{ // go  up
                    for(int i = 0;i < step; i++){
                        count++;
                        a[--x][y] = count;
                    }
                }          
            }
            if(change == 1){
                step--;
            }
            change = (change + 1) % 2;     
        }

        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                cout << setw(5) << a[i][j];
            }
            cout << endl;
        }
    } 
}
