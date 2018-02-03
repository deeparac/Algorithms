class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values,
                                vector<pair<string, string>> queries) {
        vector<double> rst;
        if (queries.empty()) {
            return rst;
        }
        unordered_map<string, pair<string, double>> parents;

        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i].first;
            const string& B = equations[i].second;
            const double k = values[i];

            if (!parents.count(A) && !parents.count(B)) {
                parents[A] = {B, k};
                parents[B] = {B, 1.0};
            } else if (!parents.count(A)) {
                parents[A] = {B, k};
            } else if (!parents.count(B)) {
                parents[B] = {A, 1.0 / k};
            } else {
                auto& rA = find(A, parents);
                auto& rB = find(B, parents);
                if (rA != rB) {
                    rA.first = rB.first;
                    rA.second *= (k * rB.second);
                }
            }
        }

        for (const auto& pair : queries) {
            const string& X = pair.first;
            const string& Y = pair.second;
            if (!parents.count(X) || !parents.count(Y)) {
                rst.push_back(-1.0);
                continue;
            }
            auto& rX = find(X, parents);
            auto& rY = find(Y, parents);
            if (rX.first != rY.first)
                rst.push_back(-1.0);
            else
                rst.push_back(rX.second / rY.second);
        }
        return rst;
    }
private:
    pair<string, double>& find(const string& C, unordered_map<string, pair<string, double>>& parents) {
        if (C != parents[C].first) {
            const auto& p = find(parents[C].first, parents);
            parents[C].first = p.first;
            parents[C].second *= p.second;
        }
        return parents[C];
    }
};
