/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here
        map<int, double> rst;
        map<int, priority_queue<int>> q;

        for (auto& rec : results) {
            if (q.find(rec.id) == q.end()) {
                q[rec.id] = priority_queue<int>();
            }

            q[rec.id].push(rec.score);
        }

        for (auto& p : q) {
            int idx = p.first;
            priority_queue<int> hp = p.second;
            int sum = 0;
            for (int i = 0; i < 5; ++i) {
                sum += hp.top(); hp.pop();
            }
            rst[idx] = sum / 5.0;
        }

        return rst;
    }
};
