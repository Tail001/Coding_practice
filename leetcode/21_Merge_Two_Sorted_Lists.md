# 21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(list1 && list2){
            if(list1 -> val >= list2 -> val){
                tail -> next = list2;
                list2 = list2 -> next;
            }
            else{
                tail -> next = list1;
                list1 = list1 -> next;
            }
            tail = tail -> next;
        }
        if(list1) tail -> next = list1;
        if(list2) tail -> next = list2;
        return dummy.next;
    }
};
```

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *head = list1;
        if(list1 -> val > list2 -> val){
            head = list2;
            list2 = list2 -> next;
        }
        else{ // list2 -> val >= list1 -> val
            list1 = list1 -> next;
        }
        ListNode *current = head;
        while(list1 && list2){
            if(list1 -> val > list2 -> val){
                current -> next = list2;
                list2 = list2 -> next;
            }
            else{ // list2 -> val >= list1 -> val
                current -> next = list1;
                list1 = list1 -> next;
            }
            current = current -> next;
        }
        if(list1) current -> next = list1;
        if(list2) current -> next = list2;
        return head;
        
    }
};
```