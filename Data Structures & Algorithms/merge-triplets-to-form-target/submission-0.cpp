class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool true0 = false;
        bool true1 = false;
        bool true2 = false;
        for(const auto& t : triplets){
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]){
                continue;
            }
            if(t[0] == target[0]) true0 = true;
            if(t[1] == target[1]) true1 = true;
            if(t[2] == target[2]) true2 = true;
            if(true0 && true1 && true2){return true;}
        }
        return false;
    }
};
