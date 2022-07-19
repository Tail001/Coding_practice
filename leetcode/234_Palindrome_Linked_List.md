# 234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list
``` C++
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
    bool isPalindrome(ListNode* head) {
        vector<int> container;
        ListNode* current = head;
        while(current != NULL){
            container.push_back(current -> val);
            current = current -> next;
        }
        for(int i = 0; i < container.size() / 2; i++){
            if(container[i] != container[container.size() - i - 1])
                return false;
        }
        return true;
    }
};
```
