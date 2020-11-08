/*
use a auxiliary stack to record min element
*/

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        x_stack.push(x);
        if (x < min_stack.top())
        {
            min_stack.push(x);
        }
        else
        {
            min_stack.push(min_stack.top());
        }
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};


/*
use a variable to record min element
*/

class MinStack {
    //st record difference between min_mem and x pushed;
    //so it perhaps out of int range, such as MAX_INT - (-MIN_INT)
    stack<long> st;
    long min_mem;  
public:
    /** initialize your data structure here. */
    MinStack() {
        min_mem = INT_MAX;
    }

    void push(int x) {
        if (st.empty())
        {
            st.push(0);
            min_mem = x;
        }
        else
        {
            st.push(x - min_mem);
            if (x < min_mem)
            {
                min_mem = x;
            }
        }
    }

    void pop() {
        if (st.empty())
        {
            return;
        }

        long top = st.top();
        st.pop();
        if (top < 0)
        {
            min_mem = (min_mem - top);
        }
    }

    int top() {
        long t = st.top();
        if (t < 0)
        {
            return (int)min_mem;
        }
        else
        {
            return (int)(st.top() + min_mem);
        }        
    }

    int getMin() {
        return (int)min_mem;
    }
};