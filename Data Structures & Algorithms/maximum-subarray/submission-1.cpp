class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar = nums[0];
        int temp = 0;
        for(int i=0; i<nums.size() ; i++){
            if(temp < 0){ temp = 0; }
            temp += nums[i];
            if(temp > maxsofar){
                maxsofar = temp;
            }
        }
        return maxsofar;
    }
};
