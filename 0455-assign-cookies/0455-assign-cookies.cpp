class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int i=0,j=0;
        int ans=0;
        while(i<g.size()&&j<s.size()){
            if(g[i]<=s[j]){ans++;j++;}
            i++;
        }
        return ans;
    }
};