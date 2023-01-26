class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }
        int islands = 0;
        for(int i=0; i<grid.size(); i++)
        {
            //looping through all the columns
            for(int j=0; j<grid[i].size(); j++)
            {
                // bfs: expand in all direction and flip connected land pieces to 0's to avoid over counting.
                if(grid[i][j]== '1')
                    islands += bfs(grid, i, j);
            }
        }
        return islands;
    }
    
    int bfs(vector<vector<char>>& grid, int i, int j){ // pass by reference here to mod for recurs
    //top,bottom
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0'){
          return 0;  
        }
        grid[i][j] = '0';
        //recursively expand
        bfs(grid, i+1, j);
        bfs(grid, i-1, j);
        bfs(grid, i, j+1);
        bfs(grid, i, j-1);
        
        return 1;
    }
};