class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> existed;
        for(int num: nums){
            auto iter = existed.find(num);
            if(iter != existed.end()){
                // exist!
                return true;
            }
            existed[num] = true;
        }
        return false;
    }
};