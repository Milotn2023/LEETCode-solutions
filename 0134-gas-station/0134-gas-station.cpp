class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gassum=0,costsum=0,fuel=0,start=0;
        for(int i=0;i<gas.size();i++){
            gassum+=gas[i];
            costsum+=cost[i];
            fuel+=gas[i]-cost[i];
            if(fuel<0){start=i+1;
            fuel=0;}
        }
        if(costsum>gassum)return -1;
        return start;
    }
};