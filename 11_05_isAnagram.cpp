class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> counts;
        for(char c:s){
            auto iter = counts.find(c);
            if(iter != counts.end())
                counts[c]++;
            else
                counts[c] = 1;
        }
        
        for(char c:t){
            auto iter = counts.find(c);
            if(iter != counts.end()){
                if(counts[c] > 0)
                    counts[c]--;
                else
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
