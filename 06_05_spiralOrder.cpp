class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> result;
        int row_lower = 0;
        int row_upper = rows-1;
        int col_lower = 0;
        int col_upper = cols-1;
        int direction = 3;
        // 0: up, 1:down, 2:left, 3:right
        // 3(right) -> 1(down) - > 2(left) -> 0(up) -> 3(right)
        int i = 0;
        int j = 0;
        while(row_upper>=row_lower && col_upper>=col_lower){
            result.push_back(matrix[i][j]);
            switch(direction){
                case 0: // up
                    if(i-1 >= row_lower){
                        i--;
                    }
                    else{
                        direction = 3;
                        col_lower++;
                        j++;
                    }
                    break;
                case 1: // down
                    if(i+1 <= row_upper){
                        i++;
                    }
                    else{
                        direction = 2;
                        col_upper--;
                        j--;
                    }
                    break;
                case 2: // left
                    if(j-1 >= col_lower){
                        j--;
                    }
                    else{
                        direction = 0;
                        row_upper--;
                        i--;
                    }
                    break;
                case 3: // right
                    if(j+1 <= col_upper){
                        j++;
                    }
                    else{
                        direction = 1;
                        row_lower++;
                        i++;
                    }
                    break;
            }
        }
        return result;
    }
};