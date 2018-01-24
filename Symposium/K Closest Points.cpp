/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        vector<Point> rst;
        if (points.empty() || k == 0 || k > points.size()) {
            return rst;
        }

        vector<ResultType> q;
        for (auto& point : points) {
            ResultType rt = ResultType(
                point.x,
                point.y,
                calcDist(point, origin)
            );
            q.push_back(rt);
        }

        sort(q.begin(), q.end(), cmp);

        for (int i = 0; i < k; ++i) {
            rst.push_back(Point(q[i].x, q[i].y));
        }

        return rst;
    }

private:
    struct ResultType {
        int x, y, dist;
        ResultType(int a, int b, int c) : x(a), y(b), dist(c) {}
    };

    double calcDist(Point p, Point o) {
        return sqrt(pow(p.x-o.x, 2) + pow(p.y-o.y, 2));
    }

    static bool cmp(const ResultType& lhs, const ResultType& rhs) {
        if (lhs.dist != rhs.dist) {
            return lhs.dist < rhs.dist;
        } else {
            if (lhs.x != rhs.x) {
                return lhs.x < rhs.x;
            } else {
                return lhs.y < rhs.y;
            }
        }
    }

};
