class Solution {
public:
    /*
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        int i = 0;
        int j = 0;
        int star = -1;

        while (i < s.size()) {
            if (j < p.size() &&
                (p[j] == '?' || s[i] == p[j])) {
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                star = j;
                j++;
            } else if (star != -1) {
                // aabbkkkapasdo
                //     i
                //     mark
                // aabb*pasdo
                //     star
                //      j
                i++;
                j = star + 1;
            } else {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};
