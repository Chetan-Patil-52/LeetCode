// First app (failed to check for minmum) 

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowMax = 0;
        for(int row=0;row<m;row++){
            // rowMax = 0;
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    // rowMax = max(rowMax,col);
                    rowMax++;
                }
            }
        }
        // rowMax++;
        int colMax = 0;
        for(int col=0;col<n;col++){
            for(int row=0;row<m;row++){
                if(grid[row][col]==1){
                    // colMax = max(colMax,row);
                    colMax++;
                }
            }
        }
        // colMax++;

        return colMax+rowMax;
        
    }
};


// Optimal with checks - inital val of min/max - Col and rows
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowMax = -1;
        int rowMin = m;
        for(int row=0;row<m;row++){
            // rowMax = 0;
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    rowMax = max(rowMax,col);
                    rowMin = min(rowMin,col);
                    // rowMax++;
                }
            }
        }
        int rowL = rowMax - rowMin + 1;

        int colMax = -1;
        int colMin = n;
        for(int col=0;col<n;col++){
            for(int row=0;row<m;row++){
                if(grid[row][col]==1){
                    colMax = max(colMax,row);
                    colMin = min(colMin,row);
                    // colMax++;
                }
            }
        }
        int colL = colMax - colMin + 1;
        // colMax++;

        // if(rowL == 0 || colL == 0){
        //     return max(rowL,colL)-1;
        // }

        return colL*rowL;
        
    }
};


// 
