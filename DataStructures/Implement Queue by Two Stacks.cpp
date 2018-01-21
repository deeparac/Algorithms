class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        main.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        while (!main.empty()) {
            help.push(main.top());
            main.pop();
        }

        int top = help.top();
        help.pop();

        while (!help.empty()) {
            main.push(help.top());
            help.pop();
        }

        return top;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        while (!main.empty()) {
            help.push(main.top());
            main.pop();
        }

        int top = help.top();

        while (!help.empty()) {
            main.push(help.top());
            help.pop();
        }

        return top;
    }

private:
    stack<int> main, help;
};
