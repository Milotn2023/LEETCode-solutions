class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        int mod=0;
        while(n>1){
            mod=n%3;
            if(mod!=0)return false;
            n/=3;
        }
        return true;
    }
};