class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> S;
        
        for(int n:students)
            S.push(n);
        
        for(int i=0;i<sandwiches.size();i++){
            int favor = sandwiches[i];
            int len = S.size();
            int counts = 0;
            while(true){
                if(favor == S.front()){
                    S.pop();
                    break;
                }
                else{
                    S.push(S.front());
                    S.pop();
                    counts++;
                    if(counts == len){
                        return counts;
                    }
                }
            }
        }
        return 0;
    }
};
