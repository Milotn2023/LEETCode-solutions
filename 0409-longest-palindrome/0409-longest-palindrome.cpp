class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int ans=0;
        for(auto it:mp){
            ans+=2*((it.second)/2);
        }
        if(ans<n)ans++;
        return ans;
    }
};