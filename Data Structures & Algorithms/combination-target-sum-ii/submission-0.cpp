class Solution {

private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int target, int i, vector<int> curr){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<0 || i>= nums.size()){ return;}
        curr.push_back(nums[i]);
        dfs(nums, target-nums[i], i+1, curr);
        curr.pop_back();
        while(i+1<nums.size() && nums[i+1] == nums[i]){
            i++;
        }
        dfs(nums, target, i+1 , curr);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, curr);
        return res;
    }
};
