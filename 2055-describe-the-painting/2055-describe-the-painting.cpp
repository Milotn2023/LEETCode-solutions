class Solution {
public:
    // vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    //     vector<vector<long long>>ans;
    //     vector<int>v;
    //     int size=0;
    //     for(auto &i:segments)size=max(size,i[1]);
    //     v.resize(size+1,0);
    //     for(auto &i:segments){
    //         v[i[0]]+=i[2];
    //         v[i[1]]-=i[2];
    //     }
    //     for(int i=1;i<v.size();i++)
    //     v[i]=v[i]+v[i-1];
    //     int start=1,val;
    //     for(int i=1;i<v.size();i++){
    //         val=v[i];
    //         if(val==0)continue;
    //         if(v[i+1]!=val){
    //             if(v[i-1]!=val)start=i;
    //             ans.push_back({start,i+1,val});
    //             start=i+1;
    //         }

    //     }
    //     return ans;
    // }
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    int size = 0;
    for (auto &i : segments) size = max(size, i[1]);
    map<int,int>mp;
    vector<long long> v(size + 2, 0); 
    for (auto &i : segments) {
        v[i[0]] += i[2];
        v[i[1]] -= i[2];
        mp[i[0]]++;
        mp[i[1]]++;
    }
    for (int i = 1; i <= size; i++) {
        v[i] += v[i - 1];
    }
    vector<vector<long long>> ans;
    for (auto it = mp.begin(); it != mp.end(); ) {
    auto nxt =next(it);
    if (nxt == mp.end()) break;
    if(v[it->first]!=0)
    ans.push_back({it->first, nxt->first, v[it->first]});
    if (it->second == 1) {
        it = mp.erase(it);
    } else {
        --(it->second);
        ++it;
    }
    if (nxt != mp.end() && nxt->second == 0) {
        mp.erase(nxt);
    }
}

    

    return ans;
}

};