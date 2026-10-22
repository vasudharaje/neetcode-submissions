class Solution {
private:
    vector<int> memo;
    
    int dfs(vector<int>& nums, int i) {
        // Base case: Fixed with '>=' to handle overshooting the end of the array safely
        if (i >= nums.size() - 1) {
            return 0;
        }

        if (nums[i] == 0) {
            return memo[i] = INT_MAX; 
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        int minm = INT_MAX;
        
        for (int j = 1; j <= nums[i]; j++) {
            // Call dfs once and store in temp
            int temp = dfs(nums, i + j);
            
            // Check temp instead of calling dfs a second time
            if (temp != INT_MAX) {
                minm = min(minm, 1 + temp);
            }
        }

        return memo[i] = minm;
    }

public:
    int jump(vector<int>& nums) {
        memo.assign(nums.size()+1, -1);
        return dfs(nums, 0);
    }
}; 