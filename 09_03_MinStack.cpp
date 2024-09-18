class MinStack {
    stack<int> data;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        
        if(min.empty()){
            min.push(val);
            return ;
        }
        
        int current_min = min.top();
        
        if(current_min>val){
            min.push(val);
        }
        else{
            min.push(current_min);
        }
    }
    
    void pop() {
        if(data.empty())
            return ;
        data.pop();
        min.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */