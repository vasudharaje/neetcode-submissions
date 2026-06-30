class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int pref = 1;
        int postf = 1;
        for(int i=0; i<nums.size(); i++){
            result[i] = pref;
            pref = pref*nums[i];
        }
        for(int i=nums.size()-1; i>-1; i--){
            result[i] = result[i]*postf;
            postf = postf*nums[i];
        }
        return result;
    }
};
