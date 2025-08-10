class Solution {
public:
    bool reorderedPowerOf2(int n) {
        for(int i=0;i<32;i++){
            if(pos(1<<i)==pos(n))return true;
        }
        return false;
    }
    private:
    int pos(int t){
        int res=0;
        for(;t;t/=10)res+=pow(10,t%10);
        return res;
    }
};