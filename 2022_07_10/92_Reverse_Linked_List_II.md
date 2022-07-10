# 92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/
```c++
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = new ListNode(0);
        ListNode *store = prev;
        prev -> next = head;
        int freq = right - left;
        left -= 1; // need the previous one
        while(left--){
            store = store -> next;
        }
        ListNode *curr = store -> next;
        for(int i = 0; i < freq;i++){
            ListNode *temp = curr -> next;
            curr -> next = temp -> next;
            temp -> next = store -> next;
            store -> next = temp;
        }
        return prev -> next;
    }
        
};
```
