class Solution {

private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& used){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            dfs(nums,curr, used);
            curr.pop_back();
            used[i] = false;
        }
        
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        dfs(nums, curr, used);
        return res;
    }
};
