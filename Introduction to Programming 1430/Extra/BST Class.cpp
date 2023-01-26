class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;
    int front;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        if (s1.size() == 1)
            front = s1.top();

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        while (s1.size() > 1)
        {
            int f = s1.top();
            s1.pop();
            s2.push(f);
        }
        int x = s1.top();
        s1.pop();
        if (s2.size() != 0)
            front = s2.top();
        while (!s2.empty())
        {
            int f = s2.top();
            s2.pop();
            s1.push(f);
        }
        return x;
    }

    /** Get the front element. */
    int peek() {

        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
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