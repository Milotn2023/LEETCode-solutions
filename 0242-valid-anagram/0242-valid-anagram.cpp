class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            v[t[i]-'a']--;
        }
        for(auto i:v){
            if(i!=0)return false;
        }
        return true;
    }
};