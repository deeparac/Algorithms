class Solution {
public:
    double myPow(double x, int n) {
        if ((n == INT_MIN || n == INT_MAX) && abs(x) > 1) {
            return 0.0;
        }

        if (n < 0) {
            return 1 / helper(x, -n);
        } else {
            return helper(x, n);
        }
    }

private:
    double helper(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double partial = helper(x, n / 2);
        if (n % 2 == 1) {
            return partial * partial * x;
        } else {
            return partial * partial;
        }
    }
};
