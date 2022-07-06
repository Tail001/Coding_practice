# 206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
#####Example 1:
![1](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)
```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```
#####Example 2:
![2](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)
```
Input: head = [1,2]
Output: [2,1]
```
#####Example 3:
```
Input: head = []
Output: []
```
---

My solution:

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = 0, *current = head, *temp;
        while(current){
            temp = current -> next;
            cur -> next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
};
```