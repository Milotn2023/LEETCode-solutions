class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(int i:nums)v.push_back(to_string(i));
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });
        string ans="";
        if(v[0]=="0")return "0";
        for(auto s:v)ans+=s;
        return ans;
    }
};