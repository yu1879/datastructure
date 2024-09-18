class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> data;
        data[0] = -1; // for 1 -1
        int sum = 0;
        int longest = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i])
                sum++;
            else
                sum--;
            
            auto iter = data.find(sum);
            if(iter != data.end()){
                // longest = max(longest, i-data[sum])
                longest = longest > i-data[sum]?longest:i-data[sum];
            }
            else{
                data[sum] = i;
            }
        }
        return longest;
        // O(n)
    }
};