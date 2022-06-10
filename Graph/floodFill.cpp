
void dfs(vector<vector<int>>& image, int x, int y, int src, int newColor, int row, int column){
    if(x<0 || x>=row || y<0 || y>=column || image[x][y]!=src){
        return;
    }
    image[x][y] = newColor;
    
    dfs(image,x, y+1, src, newColor, row,column);
    dfs(image,x+1, y, src, newColor, row,column);
    dfs(image,x, y-1, src, newColor, row,column);
    dfs(image,x-1, y, src, newColor, row,column);
    
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int row = image.size();
    int column = image[0].size();
    
    if(image[x][y]==newColor) return image;
    
    int src = image[x][y];
    
    dfs(image, x,y,src,newColor,row,column);
    return image;
}