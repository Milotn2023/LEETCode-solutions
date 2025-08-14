class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
//         vector<vector<pair<int, double>>> v(n);
// for (int j = 0; j < edges.size(); j++) {
//     v[edges[j][0]].push_back({edges[j][1], succProb[j]});
//     v[edges[j][1]].push_back({edges[j][0],succProb[j]});
// }
//         set<pair<int,int>>s;
//         vector<double>pro(n,0.0000);
//         s.insert({1,start_node});
//         pro[start_node]=1;
//         while(!s.empty()){
//             auto it=*s.begin();
//             int node=it.second;
//             int p=it.first;
//             s.erase(it);
//             for(auto i:v[node]){
//                 if(pro[i.first]<(i.second*p)){pro[i.first]=i.second*p;
//                 s.insert({pro[i.first],i.first});}
//             }
//         }
//         return pro[n-1];
vector<vector<pair<int, double>>> v(n);
    for (int j = 0; j < edges.size(); j++) {
        v[edges[j][0]].push_back({edges[j][1], succProb[j]});
        v[edges[j][1]].push_back({edges[j][0], succProb[j]});
    }
    vector<double> pro(n, 0.0);
    pro[start_node] = 1.0;
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start_node});

    while (!pq.empty()) {
        auto [p, node] = pq.top();
        pq.pop();

        if (node == end_node) return p;

        if (p < pro[node]) continue;
        for (auto& [next, prob] : v[node]) {
            if (pro[next] < p * prob) {
                pro[next] = p * prob;
                pq.push({pro[next], next});
            }
        }
    }
    return 0.0;
    }
};