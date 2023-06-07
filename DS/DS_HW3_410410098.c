#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define MAX_SIZE 1000
const int Max_Weight = 9999; // represent infinity
double distance_table[100][100]; // adjacency matrix
int node_num, B; // required data(see assignment slides)
int *cycle_list;
typedef struct node{
    // every place and their info
    int id;
    double x;
    double y;
}Node;
//define a stack
int top = -1;
int stack[MAX_SIZE];
bool IsEmpty(){
    return (top < 0);
}
bool IsFull(){
    return (top >= MAX_SIZE - 1);
}
void push(int data){
    if(IsFull())
        return;
    else
        stack[++top] = data;
}
int pop(){
    if(IsEmpty())
        return -1;
    else    
        return stack[top--];
}
// using a function caculating distances
double distance(Node a, Node b){
    double x, y;
    x = a.x - b.x;
    y = a.y - b.y;
    return sqrt(x * x + y * y);
}
//The name is Mini key extracting
// return a int represented "minimum index"(the shortest path lead to a node)
int MinKeyExtract(double *key, bool *visited, int n){
    int min_idx = 0, min = Max_Weight;
    for(int i = 0; i < n; i++){
        // not visited yet and the shortest node
        if(visited[i] == false && key[i] < min){
            min = key[i];
            min_idx = i;
        }
    }
    return min_idx;
}
// use dfs in order to make a cycle of original tree
void DFS_cycle(double *key, int *pred, int n){
    //cycle_list is a set of array stored a cycle of input graph
    cycle_list = malloc(sizeof(int) * n);
    //init
    int start = 0;
    //the rest is DFS algorithm, using this method to form a cycle
    push(start);
    int j = 0;
    while(!IsEmpty()){
        int u = pop();
        cycle_list[j++] = u;
        for(int i = n; i >= 0; i--){
            if(pred[i] == u){
                push(i);
            }
        }
    }
}
void Span_Tree(int n){
    //use Prim algorithm
    bool *visited = malloc(sizeof(bool) * n);
    int *pred = malloc(sizeof(int) * n);
    double *key = malloc(sizeof(double) * n);
    //init
    for(int i = 0; i < n; i++){
        pred[i] = -1; //keep track of previous node
        visited[i] = false;
        key[i] = Max_Weight;
    }
    int start = 0;
    key[start] = 0; // set node 0 as start point
    for(int i = 0; i < n; i++){
        // find the less cost edge's index
        int u = MinKeyExtract(key, visited, n);
        visited[u] = true;
        for(int j = 0; j < n; j++){
            // judge whether visited or is shorter than the previous and avoid finding self-connect-self
            if(visited[j] == false && distance_table[u][j] != 0 && distance_table[u][j] < key[j]){
                pred[j] = u;
                key[j] = distance_table[u][j];
            }
        }
    }
    // run DFS to form a cycle we need
    DFS_cycle(key, pred, n);
}
void UVA_algorithm(int n){
    double temp = 0.0;
    int j = 0; // the UVA's num
    // this part is to caculate the number of UVA
    for(int i = 0; i < n - 1; i++){
        temp += distance_table[cycle_list[i]][cycle_list[i + 1]];
        if(temp > (B / 2)){
            ++j;
            temp = 0.0;
        }
    }
    temp = 0.0;
    //from this line, we print every place that UVA pass by
    printf("%d\n", ++j);
    j = 0; // and reset the counter j (UVA's num)
    printf("%d ", j);
    for(int i = 0; i < n - 1; i++){
        //add distance and decide whether the distance is bigger (B / 2) or not
        // and we process the stdoutput at the same time
        temp += distance_table[cycle_list[i]][cycle_list[i + 1]];
        printf("%d ", cycle_list[i]);
        if(temp > (B / 2)){
            printf("\n%d ", ++j);
            temp = 0.0;
        }
    }
    //the last node.Since we cannot print the last node through the algorithm we made
    printf("%d\n", cycle_list[n - 1]);
}

int main(){
    Node place[100];
    //input
    scanf("%d %d", &node_num, &B);
    for(int i = 0; i < node_num; i++){
        scanf("%d %lf %lf", &place[i].id, &place[i].x, &place[i].y);
    }
    // constract a table
    for(int i = 0; i < node_num; i++){
        for(int j = 0; j < node_num; j++){
            distance_table[i][j] = distance(place[i], place[j]);
        }
    }
    // major algorithm
    Span_Tree(node_num);
    UVA_algorithm(node_num);
    return 0;
}
