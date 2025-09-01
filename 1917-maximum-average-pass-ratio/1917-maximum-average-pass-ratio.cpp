#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int a, int b) {
            return (double)(a + 1) / (b + 1) - (double)a / b;
        };
        priority_queue<tuple<double,int,int>> pq;
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), c[0], c[1]});
        }
        while (extraStudents--) {
            auto [g, a, b] = pq.top();
            pq.pop();
            a++, b++;
            pq.push({gain(a, b), a, b});
        }
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, a, b] = pq.top();
            pq.pop();
            sum += (double)a / b;
        }

        return sum / classes.size();
    }
};
