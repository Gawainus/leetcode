#include <vector>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        bool isIsland {false};
        int numIslands {0};
        
        int numRows = grid.size();
        if (numRows == 0)
            return 0;
        
        int numColumns = grid[0].size();
        if (numColumns == 0)
            return 0;
        
        for (unsigned int i = 0; i < numRows; i++) {
            for (unsigned int j = 0; j < numColumns; j++) {
                char c = grid[i][j];
                
                if (isIsland) {
                    if (c == '1') {
                        continue;
                    }
                    else {
                        isIsland = false;
                    }
                }
                else {
                    
                    if (i > 0 && grid[i-1][j] == '1') {
                            isIsland = true;
                            continue;
                        }

                        if (j < numColumns-1 && grid[i][j+1] == '1') {
                            isIsland = true;
                            continue;
                        }

                        numIslands++; 
                }
                
            }
        }
        return numIslands;
    }
};
