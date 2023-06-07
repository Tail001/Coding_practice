#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 9000
int strNum = 0, MaxStrLen = 0;
int incorrectStrings = 0;

typedef struct node {
    int level;
    int index;
    char* hashValue;
    struct node* right;
    struct node* left;
} node;

int key[MAX];
char data[MAX][MAX];  // store string data

char* ulToStr(unsigned long long num);  // converter
unsigned long long strToUl(char*);      // converter

// given hashing function
unsigned long long MurmurOAAT32(char* key) {
    unsigned long long h = 3323198485ul;
    for (; *key; ++key) {
        h ^= *key;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}
node* build_merkle_tree(node* root, int depth, int level, int index) {
    root = malloc(sizeof(node));
    // base case
    if (level == depth) {
        root->right = NULL;
        root->left = NULL;
        unsigned long long hashKey = MurmurOAAT32(data[index]);
        root->hashValue = ulToStr(hashKey);
        root->level = level;
        root->index = index;
        return root;
    }

    root->left = build_merkle_tree(root->left, depth, level + 1, index * 2);
    root->right = build_merkle_tree(root->right, depth, level + 1, index * 2 + 1);
    unsigned long long hashKey = strToUl(root->left->hashValue) + strToUl(root->right->hashValue);
    char* hashKeyStr = ulToStr(hashKey);

    root->hashValue = ulToStr(MurmurOAAT32(hashKeyStr));
    root->level = level;
    root->index = index;
    return root;
}
void inorderTraversal(node* root) {  // LVR
    if (!root)
        return;
    inorderTraversal(root->left);
    printf("hashValue is %s\n", root->hashValue);
    printf("(%d, %d)\n\n", root->level, root->index);
    inorderTraversal(root->right);
}

void check(node* root, int depth, int level, int* wrong) {
    printf("1 %d %d\n", root->level, root->index);
    fflush(NULL);
    char* given;
    given = malloc(sizeof(char) * MaxStrLen);
    scanf("%s", given);
    // strcmp return 0 if the two strings are the same
    if (strcmp(given, root->hashValue)) {  // not equal then continue asking
        // base case
        if (root->level == depth) {
            key[(*wrong)++] = root->index;
            return;
        }
        check(root->left, depth, level + 1, wrong);
        check(root->right, depth, level + 1, wrong);
    }
    return;
}

int main() {
    scanf("%d %d", &strNum, &MaxStrLen);
    // get input
    int i, wrong = 0;  // wrong number
    for (i = 0; i < strNum; i++) {
        char input[MAX];
        scanf("%s", input);
        strcpy(data[i], input);
    }
    char lastStr[MAX];
    char* ptr = lastStr;
    ptr = data[i - 1];

    int depth = (int)ceil(log2(strNum));
    double maxEdge = pow(2, depth);

    for (; i < (int)maxEdge; i++) {
        strcpy(data[i], ptr);
    }

    node* head = malloc(sizeof(node));
    head = build_merkle_tree(head, depth, 0, 0);
    // inorderTraversal(head);
    check(head, depth, 0, &wrong);
    printf("2 %d\n", wrong);
    for (int j = 0; j < wrong; j++) {
        printf("%s\n", data[key[j]]);
    }
    fflush(NULL);
    return 0;
}

char* ulToStr(unsigned long long num) {
    char* str;
    int i = 0;  // counter
    str = malloc(sizeof(char) * MAX);
    while (num) {
        str[i++] = 48 + (num % 10);
        num /= 10;
    }
    str[i] = '\0';  // add string end
    // reverse the string
    int j = 0;
    for (; j < i / 2; j++) {
        char tmp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = tmp;
    }
    return str;
}

unsigned long long strToUl(char* a) {
    unsigned long long res = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        res += ((int)a[i] - 48);
        if (a[i + 1] != '\0')
            res *= 10;
    }
    return res;
}
