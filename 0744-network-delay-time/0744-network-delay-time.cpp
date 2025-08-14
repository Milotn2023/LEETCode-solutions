class Solution {
    //adj list
    // initialize the requird vectors
// push the requirements in pQ and set up for pq
// iterate the pq and nodes and its adj nodes and update the vectors
//return the result
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>v(6001);
        for(auto it:times){
            v[it[0]].push_back({it[1],it[2]});
        }
        set<pair<int,int>>st;
        st.insert({0,k});
        vector<long long>dis(6001,1000000000);
        
        dis[k]=0;
    while(!st.empty()){
        auto it=*(st.begin());
        int dist=it.first;
        int node=it.second;
        st.erase(it);
        for(auto i:v[node]){
            int adjNode=i.first;
            int edgeW=i.second;
            if(dist+edgeW<dis[adjNode]){
                dis[adjNode]=dist+edgeW;
                st.insert({dis[adjNode],adjNode});
            }
        }
            }
            int count=0;
        for(auto it:times){
            if(dis[it[0]]==1000000000)return -1;
                if(dis[it[1]]==1000000000)return -1;
            
        }
        int ans=0;
        for(int it:dis){
            if(it!=1000000000){ans=max(ans,it);
            count++;}
        }
        if(count<n)return -1;
        return ans;
    }
};