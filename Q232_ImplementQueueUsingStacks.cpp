/*
using vector simulate queue
*/

class MyQueue {
private:
    vector<int> queue;
    int front;
    int rear;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        queue.resize(100);
        rear = -1;
        front = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        queue[++rear] = x;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        return queue[front++];
    }

    /** Get the front element. */
    int peek() {
        return queue[front];
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (rear + 1) == front ? true : false;
    }
};

/*
using stack to simulate queue
*/

class MyQueue {
    stack<int> stk_in;
    stack<int> stk_out;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stk_out.empty())
        {
            while (!stk_in.empty())
            {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }

        int res = stk_out.top();
        stk_out.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        int res = pop();
        stk_out.push(res);
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk_in.empty() && stk_out.empty();
    }
};
