#include <vector>
#include <algorithm>
#include <iostream>

class Prime {
public:
    // std::vector<int> rst;
    std::vector<bool> isPrime;
    int upper_bound;

    Prime(int n) {
        upper_bound = n;
        isPrime = std::vector<bool>(upper_bound, false);
    }

    void solver() {
        for (int i = 2; i <= upper_bound; ++i) {
            for (int j = i + i; j <= upper_bound; j += i) {
                isPrime[j] = true;
            }
        }
    }

    void printer() {
        for (int i = 1; i <= upper_bound; ++i) {
            if (!isPrime[i]) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Prime p = Prime(20);
    p.solver();
    p.printer();
    return 0;
}
