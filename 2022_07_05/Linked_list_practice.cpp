#include <iostream>
using namespace std;

class LinkedList;
class LinkNode{
    int data;
    LinkNode* next;
public:
    LinkNode() : data(0), next(0){};
    LinkNode(int a) : data(a), next(0){}; 
    friend LinkedList;

};
class LinkedList{
    LinkNode* first;
public:
    LinkedList():first(0){};
    void PrintList();
    void Push_Front(int x);
    void Push_Back(int x);
    void Delete(int x);
    void Clear();
    void Reverse();
};
void LinkedList::PrintList(){
    if(first == NULL){
        cout << "List is empty" << endl;
        return;
    }
    LinkNode *current = first;
    while(current != 0){
        cout << current -> data << " "; //當宣告為指標型態時 MyClass * CA
        current = current -> next;      //就使用箭頭(->)來存取Class中的成員：
    }
    cout << endl;
}
void LinkedList::Push_Front(int x){
    LinkNode *newNode = new LinkNode(x);
    newNode -> next = first;  //當宣告為指標型態時 MyClass * CA
    first = newNode;          //就使用箭頭(->)來存取Class中的成員：
}
void LinkedList::Push_Back(int x){
    LinkNode *newNode = new LinkNode(x);
    if(first == 0){
        first = newNode;
        return;
    }
    LinkNode *current = first;
    while(current -> next != 0){
        current = current -> next;
    }
    current -> next = newNode;
}
void LinkedList::Delete(int x){
    LinkNode* current = first;
    LinkNode* previous = 0;
    while(current != 0 && current -> data != x){
        previous = current;
        current = current -> next;
    }
    if(current == 0){
        cout << "There is no " << x << " in the list." << endl;
        return;
    }
    else if(current == first){
        first = current -> next;
        delete current;
        current = 0;
        return;
    }
    else{
        previous -> next = current -> next;
        delete current;
        current = 0;
        return;
    }
}
void LinkedList::Clear(){
    while(first != 0){
        LinkNode* current = first;
        first = first -> next;
        delete current;
        current = 0;
    }
}
void LinkedList::Reverse(){
    if(first == 0 || first -> next == 0){
        cout << "This list can't be reversed." << endl;
    }
    LinkNode* previous = 0;
    LinkNode* current = first;
    LinkNode* preceding = first -> next;
    while(preceding != 0){
        current -> next = previous;
        previous = current;
        current = preceding;
        preceding = preceding -> next;
    }
    current -> next = previous;
    first = current;
}

int main() {
    LinkedList list;
    list.PrintList(); 
    list.Push_Front(10);
    list.Push_Front(9);
    list.Push_Back(11);
    list.Reverse();
    list.PrintList();
    list.Delete(3);
    list.Delete(9);
    list.PrintList();
    list.Clear();
    list.PrintList();
    return 0;
}