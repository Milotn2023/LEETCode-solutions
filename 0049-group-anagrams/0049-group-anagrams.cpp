class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto i:strs){
            string t=i;
            sort(t.begin(),t.end());
            mp[t].push_back(i);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};