class MyQueue {
public:
    stack<int>inputStack;
    stack<int>outputStack;
    MyQueue() {
    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (!outputStack.empty()) {
            int res = outputStack.top();
            outputStack.pop();
            return res;
        }
        else {
            while (!inputStack.empty()) {
                int temp = inputStack.top(); inputStack.pop();
                outputStack.push(temp);
            }
            if (!outputStack.empty()) {
                int res = outputStack.top();
                outputStack.pop();
                return res;
            }
            else return false;
        }
    }

    int peek() {
        int res = this->pop();
        outputStack.push(res);
        return res;
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
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