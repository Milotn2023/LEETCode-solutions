class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
                v[s[j]-'a']++;
                int mini=INT_MAX,maxi=0;
                for(int k=0;k<26;k++){
                    if(v[k]!=0){
                    mini=min(mini,v[k]);
                    maxi=max(maxi,v[k]);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};