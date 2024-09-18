class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        
        for(int i=0;i<nums.size();i++){
            // nums[i] exist in index or not?
            auto iter = index.find(nums[i]);
            if(iter != index.end()){
                if(i - index[nums[i]] <= k)
                    return true;
            }
            index[nums[i]] = i;
        }
        return false;
    }
};