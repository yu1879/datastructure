class MyQueue {
public:
    stack<int> data, tmp;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!data.empty()){
            tmp.push(data.top());
            data.pop();
        }
        int result = tmp.top();
        tmp.pop();
        while(!tmp.empty()){
            data.push(tmp.top());
            tmp.pop();
        }
        return result;
        
    }
    
    /** Get the front element. */
    int peek() {
        while(!data.empty()){
            tmp.push(data.top());
            data.pop();
        }
        int result = tmp.top();
        while(!tmp.empty()){
            data.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */