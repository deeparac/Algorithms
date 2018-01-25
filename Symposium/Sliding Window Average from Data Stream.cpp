class MovingAverage {
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        // do intialization if necessary
        this->size = size;
        this->sum = 0;
    }

    /*
     * @param val: An integer
     * @return:
     */
    double next(int val) {
        // write your code here
        sum += val;
        if (q.size() == size) {
            sum -= q.front(); q.pop();
        }
        q.push(val);

        return sum / q.size();
    }

private:
    double sum;
    int size;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
