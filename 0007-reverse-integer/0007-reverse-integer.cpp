class Solution {
public:
    // int reverse(int x) {
    //     if(x==0)return 0;
    //     string s=to_string(abs(x));
    //     string t="";
    //    std:: reverse(s.begin(),s.end());
    //     for(int i=0;i<s.length();i++){
    //         if(t.length()==0&&s[i]=='0');
    //         else t+=s[i];
    //     }
    //     if(x<0){
    //         t='-'+t;
    //     }
    //     return stoi(t);
    // }
    #include <climits>

int reverse(int x) {
    long long rev = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
            return 0; 
        }
        rev = rev * 10 + digit;
    }
    return (int)rev;
}
};