class MyStack {
public:
    queue<int> que;
    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        while (--size) {
            int temp = que.front(); que.pop();
            que.push(temp);
        }
        int res = que.front(); que.pop();
        return res;
    }

    int top() {
        int res = this->pop();
        que.push(res);
        return res;
    }

    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */