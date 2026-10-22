class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg=0 , sumc = 0;
        for(int gas_i : gas){
            sumg += gas_i;
        }
        for(int cost_i : cost){
            sumc += cost_i;
        }
        if(sumc > sumg){ return -1;}
        int diff = 0;
        int ind = 0;
        for(int i=0 ; i< gas.size()-1 ; i++){
            diff = diff + gas[i] - cost[i];
            if(diff < 0){ 
                diff = 0;
                ind = i+1;}
        }
        return min(ind, (int)gas.size()-1);
    }
};
