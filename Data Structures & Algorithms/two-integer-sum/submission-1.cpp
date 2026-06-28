class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> bag;
        for(int i=1; i<nums.size()+1;i++){
            bag.insert({nums[i-1], i});
        }
        vector<int> rem;
        for(const auto& n: nums){
            rem.push_back(target - n);
        }
        for(int j=0; j<rem.size(); j++){
            if(bag.count(rem[j])){
                if(j == bag[rem[j]]-1){
                    continue;
                }
                return {min(j, bag[rem[j]]-1), max(j, bag[rem[j]]-1)};
            }
            }
        return {};
    }
};
