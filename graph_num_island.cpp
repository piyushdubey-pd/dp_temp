#include <bits/stdc++.h>
using namespace std;

void NoofIslands(vector<vector<int>> &V, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || V[i][j]!=1)
    {
        // cout <<endl<< "OUT -> "<<"i " << i << " j " << j << " V[i][j] " << V[i][j] << endl;
        return;
    }
    
    // if (!V[i][j])
    // {
    //     cout<<"dick"<<endl;
    //     cout << endl<< "0 ->"<< "i " << i << " j " << j << " V[i][j] " << V[i][j] << endl;
    //     return;
    // }
    if(V[i][j]==1){
        V[i][j] = 0;
        // cout<<"ticl"<<endl;
        NoofIslands(V, i + 1, j , n, m);  //RIGHT
        NoofIslands(V, i - 1, j , n, m);  //BOTTOM
        NoofIslands(V, i, j + 1, n, m);  //LEFT
        NoofIslands(V, i, j - 1, n, m);  //TOP
        NoofIslands(V, i + 1, j + 1, n, m);
        NoofIslands(V, i - 1, j - 1, n, m);
        NoofIslands(V, i + 1, j - 1, n, m);
        NoofIslands(V, i - 1, j + 1, n, m);
    }
}

int main(){

    int A[][5] = { {0, 1, 1, 1, 0},
                   {0, 0, 1, 1, 0}};
    
    int n = 2;
    int m = 5;
    int c = 0;

    vector<vector<int>> V(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            V[i][j] = A[i][j] ;
        }
    }

    cout<<"ARRAY --> "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "VECTOR --> " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(V[i][j] == 1){
                // cout<<"ticl"<<endl;
                NoofIslands(V, i , j , n, m);
                // NoofIslands(V, i + 1, j , n, m);  //RIGHT
                // NoofIslands(V, i - 1, j , n, m);  //BOTTOM
                // NoofIslands(V, i, j + 1, n, m);  //LEFT
                // NoofIslands(V, i, j - 1, n, m);  //TOP
                // NoofIslands(V, i + 1, j + 1, n, m);
                // NoofIslands(V, i - 1, j - 1, n, m);
                // NoofIslands(V, i + 1, j - 1, n, m);
                // NoofIslands(V, i - 1, j + 1, n, m);
                V[i][j] = 0;
                c++;
            }
        }
        // cout<<c<<endl;
    }

    cout << "VECTOR AFTER  --> " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"ans -> "<<c<<endl;
   
}