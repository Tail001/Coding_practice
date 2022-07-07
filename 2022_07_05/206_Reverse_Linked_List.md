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
        ListNode *pre = new ListNode(0), *cur = head;
        pre -> next = head;
        while (cur && cur -> next) {
            ListNode* temp = cur -> next;
            cur -> next = temp -> next;
            temp -> next = pre -> next;
            pre -> next = temp;
        }
        return pre -> next;
    }
};
```

```C++
ListNode* reverseList(ListNode* head)
{
	if (head == NULL)       return head;
	if (head->next == NULL) return head;

	ListNode *past = NULL, *present = head;

	while (present != NULL)
	{
		// main logic:
		ListNode *future = present->next;
		present->next = past;

		// updation:
		past = present;
		present = future;
	}

	return past;
}
```