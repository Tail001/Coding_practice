# 232. Implement Queue using Stacks
https://leetcode.com/problems/implement-queue-using-stacks/
original thought:
```c++
class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {  
        peek();
        int res = st2.top();
        st2.pop();
        return res;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        if(st1.empty()&&st2.empty())
            return true;
        else 
            return false;
    }
};
```