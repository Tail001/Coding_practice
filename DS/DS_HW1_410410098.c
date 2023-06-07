#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 1000

int edge_list[MAX_SIZE][MAX_SIZE]; //record link amounts between nodes
typedef struct result res;
typedef struct req req_list;
struct req{ // every request has been written in struct
    int req_id;
    int req_src;
    int req_dest;
    req_list *next; 
};
struct result{  //output will be stored in this struct 
    int id;
    int path[MAX_SIZE];
};
struct queue{ //use queue for BFS
    int size;   
    int front;
    int rear;
    int *arr;
};
//Belows function declaration are less important
//So I put details after main function
int is_Empty(struct queue *);
int is_Full(struct queue *);
void enqueue(struct queue *, int );
int dequeue(struct queue *);

req_list * append_req_list(int id_num){ 
    req_list *first, *curr, *prev;
    first = (req_list *) malloc(sizeof(req_list)); //allocation 
    for(int i = 0 ; i < id_num ; i++){ // for loop to enter id, source, destination of req
        curr = (req_list *)malloc(sizeof(req_list));
        scanf("%d %d %d", &(curr -> req_id), &(curr -> req_src), &(curr -> req_dest));
        if(i == 0) first = curr;    //let first one be the finished input we just made 
        else{
            prev -> next = curr;    // linked 
        }
        curr -> next = NULL;   
        prev = curr;    // let previous list be the current one
    }
    return first;  
}

int * get_node_info(int node_num){
    int* quantum_array;
    quantum_array = malloc(sizeof(int) * node_num);
    for(int i = 0; i < node_num; i++){  // get node info and return a whole 1d array
        int node_id, quantum;              
        scanf("%d %d", &node_id, &quantum);
        quantum_array[node_id] = quantum;
    }
    return quantum_array;
}

void get_link_info(int link_num){
    for(int i = 0; i < link_num ; i++){ 
        int link_id, start, end, channels;
        scanf("%d %d %d %d", &link_id, &start, &end, &channels);
        edge_list[start][end] = channels;   //let the content of 2d array be amount of channels
        edge_list[end][start] = channels;   // rows and column do the same operations
    }
}

bool BFS(req_list* node, int v, int pred[]){
    struct queue q;
    q.front = 0;        //queue init
    q.rear = 0;         //queue init
    q.size = MAX_SIZE;  //queue init
    q.arr = (int*) malloc(q.size * sizeof(int));
    int *visited = malloc(sizeof(int) * v);  //keep track of whether visited 
    for(int i = 0; i < v; i++){
        visited[i] = 0; // represents false
        pred[i] = -1; // previous node -1 means no previous node 
    }
    visited[node -> req_src] = 1; // represents true (visited)
    enqueue(&q, node -> req_src); //put into queue
    while(!is_Empty(&q)){
        int u = dequeue(&q);
        for(int i = 0 ; i < v ; i++){
            if(edge_list[u][i] > 0 && visited[i] == 0){
                visited[i] = 1;
                pred[i] = u;    // record the previous node's id
                enqueue(&q, i);
                if(i == node -> req_dest){  //search destination
                    return true;            // if found return find the shortest path
                }
            }
        }
    }
    return false; // false
}
//This function for checking whether enough quantum for nodes
bool enough_qum(int quantum[], int pred[], int v, req_list* node){
    int* path = malloc(sizeof(int)* v);
    int crawl = node -> req_dest;   // use to track the nodes 
    int index = 0;
    path[index] = crawl;    // store in path array for coding easily 
    while(pred[crawl] != -1){   // keep tracking until find the source node
        path[++index] = pred[crawl];
        crawl = pred[crawl];
    }
    //start and end vertex cost one, while the others cost two. 
    for(int i = 0 ; i < index ; i++){
        if(i == 0 && i == v - 1){
            if(quantum[path[i]] < 1)
                return false;
        }
        else{
            if(quantum[path[i]] < 2)
                return false;
        }
    }
    return true;
}
//same operation as the function at line 96
void consume_resources(req_list* node, int quantum[], int v, int *pred){
    int* path = malloc(sizeof(int)* v);
    int crawl = node -> req_dest;
    int index = 0;
    path[index] = crawl;
    while(pred[crawl] != -1){
        path[++index] = pred[crawl];
        crawl = pred[crawl];
    }
    path[++index] = -1;
    for(int i = index - 1 ; i >= 0 ; i--){ // consume quantum
        if(i == index - 1 || i == 0){      // start and end cost one
            quantum[path[i]] -= 1;
        }
        else{
            quantum[path[i]] -= 2;         //the others cost two
        }
    }
    // consume link
    index = 0;
    while(path[index] != -1){
        if(index == 0){
            index++;
            continue;
        }
        edge_list[path[index - 1]][path[index]]--;
        edge_list[path[index]][path[index - 1]]--;
        index++;
    }
}
// As function name shows, same operation as function at line 96
void store_output(req_list* node, res* output, int v, int* pred){
    output -> id = node -> req_id;
    int crawl = node -> req_dest, index = 0;
    output -> path[index] = crawl;
    while(pred[crawl] != -1){
        output -> path[++index] = pred[crawl];
        crawl = pred[crawl];
    }
    output -> path[++index] = -1; // end of the tracker
}

// if quantum num is 0, means no one can connect with.
//Set every connected link to 0
void reset_map(int v, int quantum[]){
    for(int i = 0 ; i < v ; i++){
        if(quantum[i] == 0){
            for(int j = 0 ; j < v ; j++){
                edge_list[i][j] = 0;
                edge_list[j][i] = 0;
            }
        }
    }
}
// find the end of the path tracker
int traversal(res output){
    int index = 0;
    for(int i = 0 ; ;i++){
        if(output.path[i] == -1){
            return index;
        }
        index++;
    }
}

int main(){
    int node_num, link_num, req_num; // node_num == rows
    scanf("%d %d %d", &node_num, &link_num, &req_num);// get basic info
    int accept_num = 0;
    res output[500];
    bool accepted;  //BFS accepted or not
    bool enough;    // whether there is enough quantum
    int *pred;
    pred = malloc(sizeof(int) * node_num);  // store prev node id
    req_list *head;
    
    int *quantum = get_node_info(node_num);
    get_link_info(link_num);
    head = append_req_list(req_num);
    req_list *curr = head;
    
    for(int i = 0 ; i < req_num ; i++){
        accepted = BFS(curr, node_num, pred); // path saved in pred
        enough = enough_qum(quantum, pred, node_num, curr);
        if(accepted && enough){
            consume_resources(curr, quantum, node_num, pred);
            store_output(curr, &output[accept_num++], node_num, pred);
        }
        else{
            curr = curr -> next;
            continue;
        }
        reset_map(node_num, quantum);
        curr = curr -> next;
    }
    
    printf("%d\n", accept_num); 
    for(int i = 0 ; i < accept_num ; i++){
        printf("%d ",output[i].id);
        int start = traversal(output[i]);   //find the begin start of the path
        for(int j = start - 1; j >= 0 ; j--){ //printf reversely
            if(j == 0){
                printf("%d\n", output[i].path[j]);
            }
            else{
                printf("%d ", output[i].path[j]);
            }
        }
    }
    return 0;
}

// queue setting shows below
int is_Empty(struct queue *q){
    return 1 ? (q -> rear == q -> front) : 0;
}

int is_Full(struct queue *q){
    return 1 ? (q -> rear == q -> size - 1) : 0;
}

void enqueue(struct queue *q, int value){
    if(is_Full(q)){
        printf("FULL\n");
    }
    else{
        q -> rear++;
        q -> arr[q -> rear] = value;
    }
}

int dequeue(struct queue *q){
    int deq_num = -1;
    if(is_Empty(q)){
        printf("EMPTY\n");
    }
    else{
        q -> front++;
        deq_num = q -> arr[q -> front]; 
    }
    return deq_num;
}
