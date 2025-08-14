class Solution {
public:
    // int countPaths(int n, vector<vector<int>>& roads) {
    //     const int MOD = 1e9+7;
    //     vector<vector<pair<int,int>>>v(n);
    //     for(auto it:roads){
    //         v[it[0]].push_back({it[1],it[2]});
    //         v[it[1]].push_back({it[0],it[2]});
    //     }
    //     vector<int>dis(n,INT_MAX);
    //     dis[0]=0;
    //     vector<int> ways(n, 0);
    //     ways[0]=1;
    //     // priority_queue<pair<int,int>>q;
    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    //     q.push({0,0});
    //     while(!q.empty()){
    //         int node=q.top().second;
    //         int dist=q.top().first;
    //         q.pop();
    //         if (dist > dis[node]) continue;
    //         for(auto it:v[node]){
    //             int adjNode=it.first;
    //             int w=it.second;
    //         long long newDist = dist + w;
    //         ways[adjNode] = ways[node];
    //             if(dis[adjNode]>=newDist){
    //                 dis[adjNode]=newDist;
    //                 q.push({dis[adjNode],adjNode});
    //             }
    //             else if (newDist == dis[adjNode]) {
    //             ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
    //         }
    //         }
    //     }
    //     return ways[n-1];
    // }
    int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1e9+7;
    vector<vector<pair<int,int>>> v(n);
    for (auto &it : roads) {
        v[it[0]].push_back({it[1], it[2]});
        v[it[1]].push_back({it[0], it[2]});
    }

    vector<long long> dis(n, LLONG_MAX);
    vector<int> ways(n, 0);
    dis[0] = 0;
    ways[0] = 1;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [dist, node] = q.top();
        q.pop();

        if (dist > dis[node]) continue; // skip outdated entries

        for (auto &[adjNode, w] : v[node]) {
            long long newDist = dist + w;
            if (newDist < dis[adjNode]) {
                dis[adjNode] = newDist;
                ways[adjNode] = ways[node];
                q.push({newDist, adjNode});
            } 
            else if (newDist == dis[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
            }
        }
    }

    return ways[n-1];
}
};