class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> starts(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(!(starts.contains(nums[i]-1))){
                int length = 1;
                while(starts.contains(nums[i]+length)){
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};
