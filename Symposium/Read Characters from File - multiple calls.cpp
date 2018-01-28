// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char *buf, int n) {
        // Write your code here
        int nbChar = 0;
        while (nbChar < n) {
            if (head == tail) {
                head = 0;
                tail = read4(buffer);
                if (tail == 0) {
                    break;
                }
            }
            while (nbChar < n && head < tail) {
                buf[nbChar++] = buffer[head++];
            }
        }

        return nbChar;
    }
private:
    char buffer[4];
    int head = 0;
    int tail = 0;
};
