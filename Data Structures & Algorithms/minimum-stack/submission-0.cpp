class MinStack {
private:
    stack<int> normalStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        normalStack.push(val);

        if (minStack.empty()) minStack.push(val);
        else minStack.push(min(val, minStack.top()));
    }
    
    void pop() {
        normalStack.pop();
        minStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
