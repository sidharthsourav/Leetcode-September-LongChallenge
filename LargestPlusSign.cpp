/*

Problem Statement.

You are given an integer n. You have an n x n binary grid grid with all values initially 1's except 
for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] 
where grid[xi][yi] == 0.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of 
length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

NOTE: Refer to the image provided on the leetcode site for more explanation.

Example 1:


Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
Example 2:


Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
 

Constraints:

1 <= n <= 500
1 <= mines.length <= 5000
0 <= xi, yi < n
All the pairs (xi, yi) are unique.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool PlusVerifier(int x,int y,int PlusSize,vector <vector<int>>& grid)
{
    bool up=true,down=true,left=true,right=true;
    for(int i=x;i<=x+PlusSize;i++)
        if(grid[i][y]==0) down=false;
    for(int i=x;i>x-PlusSize;i--)
        if(grid[i][y]==0) up=false;
    for(int j=y;j<=y+PlusSize;j++)
        if(grid[x][j]==0) right=false;
    for(int j=y;j>=y-PlusSize;j--)
        if(grid[x][j]==0) left=false;
    
    return (up && down) && ( left && right);
    
}
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
{
    if(n<=2) return 0;  // if grid is lesser than 3 it's not possible to form a minimum plus which height is 3 
    // Grid initializing with all one's.
    vector<vector<int>> grid(n,vector<int>(n,1));

    // Editing zero's in the grid.
    for(int i=0;i<mines.size();i++)  grid[mines[i][0]][mines[i][1]]=0;

    //Starting to point to search plus exist or not.
    int MaximumPlus=n;
    if(MaximumPlus%2==0) MaximumPlus=MaximumPlus-1;
    bool result=false;
    for(MaximumPlus;MaximumPlus>=3;MaximumPlus=MaximumPlus-2) //this loops is resopnsible for the maximum plus 
    {
        for(int i=MaximumPlus/2;i<n-(MaximumPlus/2);i++)
            for(int j=MaximumPlus/2;j<n-(MaximumPlus/2);j++)
            {
                bool verify=PlusVerifier(i,j,(MaximumPlus/2),grid);
                if (verify==true) return MaximumPlus/2 +1;
            }
    }
    return 0;

}

int main()
{
    vector <vector<int>> mines={{4,2}};
    int x=orderOfLargestPlusSign(5,mines);
    cout<<x;
}



