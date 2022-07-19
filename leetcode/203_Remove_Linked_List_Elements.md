# 203. Remove Linked List Elements
https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int target) {
        while(
            head != NULL && head -> val == target){
            head = head -> next;
        }
        if(head == NULL)
            return head;
        ListNode *res = head;
        while(head -> next != NULL){
            if(head -> next -> val == target){
                head -> next = head -> next -> next;
            }
            else head = head -> next;
        }
        return res;
        
    }
    
};
```
