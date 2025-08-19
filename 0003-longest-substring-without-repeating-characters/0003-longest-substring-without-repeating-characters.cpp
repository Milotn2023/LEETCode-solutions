class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(256,0);
        int len=0;
        queue<char>q;
        for(int i=0;i<s.length();i++){
           if( v[s[i]]!=0){
                while(!q.empty()&&q.front()!=s[i]){
                    v[q.front()]=0;
                    q.pop();
                }
                q.pop();
            }
                q.push(s[i]);
                v[s[i]]=1;
                len=max(len,(int)q.size());
            }
        
        return len;
    }
};