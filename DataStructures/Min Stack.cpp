class MinStack {
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        stk.push(number);
        if (minstk.empty()) {
            minstk.push(number);
        } else if (number <= minstk.top()) {
            minstk.push(number);
        } else {
            minstk.push(minstk.top());
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int top = stk.top();
        stk.pop();
        minstk.pop();
        return top;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        return minstk.top();
    }
private:
    stack<int> stk, minstk;
};
