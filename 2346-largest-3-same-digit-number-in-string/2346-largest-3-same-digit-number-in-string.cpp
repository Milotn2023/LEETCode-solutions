class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int>v;
        int maxi=-1;
        for(int i=0;i<num.length()-2;i++){
            if(num[i]==num[i+1]&&num[i]==num[i+2])maxi=max(maxi,(int)num[i]);
        }
        if (maxi==-1)return "";
        string t="";
        t+=(char)maxi;
        t+=(char)maxi;
        t+=(char)maxi;
        return t;
    }
};