class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        int srt=sqrt(n);
        if(srt*srt!=n)return false;
        return ((int)pow(2,15)%(int)srt==0);
    }
};