#include<stdio.h>
#include<stdlib.h>
// use binary tree for packing
typedef struct node{
    struct node *parent;
    struct node *down;
    struct node *right;
    int used; // represent the node is used or not 
    int width; 
    int height;
    int x; // coordinate x and y
    int y;
}Node;
typedef struct block{
    Node *fit; // determine the block's positon
    int id;
    int width;
    int height;
    int x;
    int y;
}Block;

int res = 0; // outcome of accept num 
int map_x, map_y, req_num;
Node *findNode(Node*,int , int );
Node *splitNode(Node**, int, int);

int main(){
    int i, j; // counter

    Node *root;
    Block **blocks;

    scanf("%d %d %d", &map_y, &map_x, &req_num);
    //root init:
    root = malloc(sizeof(Node));
    root -> x = root -> y = 0;
    root -> width = map_x;
    root -> height = map_y;
    root -> down = NULL;
    root -> right = NULL;
    root -> used = 0;

    // allocation for blocks
    blocks = malloc(sizeof(Block) * req_num);

    for(i = 0 ; i < req_num ; i++){
        int index, x_dir, y_dir;
        scanf("%d %dx%d%*[^\r\n]", &index, &y_dir, &x_dir);
        blocks[i] = malloc(sizeof(Block));
        //setting every imfo of blocks
        blocks[i] -> id = index;
        blocks[i] -> height = y_dir;
        blocks[i] -> width = x_dir;

    }
    // there is a bug when domain(x and y) less than 16
    // use baseline algorithm to cope with
    int x = 0;
    if(map_y < 16 || map_x < 16){
        for(i = 0; i < req_num; i++){
            if(x + blocks[i] -> width - 1 >= map_x || blocks[i] -> height >= map_y){
                continue;
            }
            res++;
            x += blocks[i]->width;
        }
        printf("%d\n", res);
        x = 0;
        for(int i = 0;i < req_num; i++){
            if(x + blocks[i] -> width - 1 >= map_x || blocks[i] -> height >= map_y){
                continue;
            }
            printf("%d %dx%d 0 %d\n",i,blocks[i]->height,blocks[i]->width,x);
            x+=blocks[i]->width;
            }
        return 0;
    }
    // end of the baseline algorithm


    //bubble sort
    //for better space usage rate
    for(i = 0 ; i < req_num ;i++){
        for(j = 0 ; j < req_num - i - 1 ; j++){
            if(blocks[j] -> width > blocks[j + 1] -> width){
                Block *temp = blocks[j + 1];
                blocks[j + 1] = blocks[j];
                blocks[j] = temp;
            }
        }
    }

    //FIT -> find every blocks' position
    for(i = 0; i < req_num ; i++){
        Node *node;
        Block *block = blocks[i];
        // interatively find the nodes' position
        node = findNode(root, block -> height, block -> width);
        if(node){
            block -> fit = splitNode(&node, block -> height, block -> width);
            //found
            res++;
        }

    }
    //find the exactly accepted req
    int req = 0;
    for(i = 0 ; i < res ; i++){
        if(blocks[i] -> fit){
            if(blocks[i] -> fit -> x <= map_x && blocks[i] -> fit -> y <= map_y){
                req++;
            }

        }
    }

    //output for binary tree algorithm
    printf("%d\n", req);
    for(i = 0 ; i < res ; i++){
        Block *block = blocks[i];
        if(block -> fit){
            if(block->fit->x <= map_x && block->fit->y <= map_y){
                printf("%d %dx%d ", block->id, block -> height, block -> width);
                printf("%d %d\n", block -> fit -> y, block -> fit -> x);
            }

        }
    }
    return 0;
}
//find the blocks' position
Node *findNode(Node *root, int height, int width){
    //find node which is not used.
    //If usend, use the node that represents the spilt space right priorly
    //then still not, used the spilt space down, and add node to the tree
    if(root -> used == 1){
        Node *rightNode = findNode(root -> right, height, width);
        if(rightNode != NULL)
            return rightNode;
        Node *downNode = findNode(root -> down, height, width);
        return downNode;
    }
    else if((root -> width >= width) && (root -> height >= height)){
        // enough space
        return root;
    }
    //there is no space for the node
    else{
        return NULL;
    }
}

// mark the node is used
// let every blocks spilt other space into two, where right and down
// and every info(coordinate, blocks' width, height) are store in the node
// last step, mark the next node unused
Node *splitNode(Node **node, int height, int width){
    (*node) -> used = 1;

    if((*node) -> height >0){
    (*node) -> down = malloc(sizeof(Node));
    (*node) -> down -> parent = (*node);
    (*node) -> down -> down = NULL;
    (*node) -> down -> right = NULL;
    (*node) -> down -> x = (*node) -> x;
    (*node) -> down -> y = (*node) -> y + height;
    (*node) -> down -> width = (*node) -> width;
    (*node) -> down -> height = (*node) -> height - height;
    (*node) -> down -> used = 0;
    }
    (*node) -> right = malloc(sizeof(Node));
    (*node) -> right -> parent = (*node);
    (*node) -> right -> down = NULL;
    (*node) -> right -> right = NULL;
    (*node) -> right -> x = (*node) -> x + width;
    (*node) -> right -> y = (*node) -> y;
    (*node) -> right -> width = (*node) -> width - width;
    (*node) -> right -> height = height;
    (*node) -> right -> used = 0;

    return *node;
}

