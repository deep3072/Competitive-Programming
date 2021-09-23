// WAP to find an element in a Row wise And Column wise Sorted Matrix.

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
        // Worst case Complexity : O(n+m)
        int row=0,col=matrix[0].size()-1;
        while(col>=0 && row<matrix.size())
        {
                int curr=matrix[row][col];
                if(curr==target)
                        return 1;
                else if(curr>target)
                        col--;
                else
                        row++;
        }
        return 0;
}
int main()
{
        FAST;
        ll testcases=1;
        cin >> testcases;
        while(testcases--)
        {
                ll n,i,j,m;
                int target;
                cin >> n >> m;
                vector<vector<int>>arr(n,vector<int>(m,0));
                for(i=0;i<n;i++)
                        for(j=0;j<m;j++)
                                cin >> arr[i][j];
                cin >> target;
                if(searchMatrix(arr,target))
                        cout << "Element found";
                else cout << "Element not found";
        }
}
