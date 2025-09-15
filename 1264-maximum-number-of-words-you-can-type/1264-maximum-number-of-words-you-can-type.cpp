class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int>v(26,0);
        for(int i=0;i<brokenLetters.length();i++)v[brokenLetters[i]-'a']++;
        int i=0;
        int n=text.length(),count=0;
        int flag=0;
        while(i<n){
            if(text[i]==' '){
                if(flag==0)count++;
                flag=0;
                i++;
            }
            if(v[text[i]-'a']!=0)flag=1;
                i++;
            }
            if(flag==0)count++;
        
        return count;
    }
};