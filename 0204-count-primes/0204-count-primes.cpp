class Solution {
public:
    int countPrimes(int n) {
        if(n==0)return 0;
        vector<bool>v(n,true);
        v[0]=v[1]=false;
        for(int i=2;i<n;i++){
            if(v[i]){
                for(long long j=1ll*i*i;j<n;j+=i){
                    v[j]=false;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i])count++;
        }
        return count;
    }
};