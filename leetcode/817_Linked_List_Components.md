https://leetcode.com/problems/linked-list-components/
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map <int, bool> map;
        int chain = 0, res = 0;
        ListNode* current = head;
        for(int i = 0; i < nums.size();i++){
            map[nums[i]] = true;
        }
        while(current){
            if(map[current -> val] == true) chain++;
            else{
                if(chain > 0){
                    res++;
                }
                chain = 0;
            }
            current = current -> next;
        }
        if(chain > 0) res++;
        return res;
    }
};
```