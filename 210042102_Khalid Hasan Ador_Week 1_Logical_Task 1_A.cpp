#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
using namespace std;


void dfs(int cur,vector<vector<int>>&adj,vector<int>&vis) //A simple dfs function to visit all the adjacent vertices of a particular vertice.
{
    vis[cur]=1;
    for(int nxt:adj[cur])
    {
        if(vis[nxt]) continue;
        dfs(nxt,adj,vis);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,i;
    cin>>n>>m; //Taking input of number of vertices and number of edges. Here n is the number of vertices and m is the number of edges. Vertices will be numbered from 0 to n-1.

    vector<vector<int>>adj(n); //Keep track of adjacent vertices.
    vector<int>vis(n); //Keep track of visited vertices.

    while(m--)  //Taking input of the edges and making the adjacent list.
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ct=0; //Keep track of number of connected components.
    for(i=0;i<n;i++)
    {
        if(vis[i]) continue;
        dfs(i,adj,vis);
        ct++;
    }
    //cout<<ct<<endl;
    if(ct==1) //If there is only 1 connected component then output true.
    {
        cout<<"True"<<endl;
    }
    else //If there are more or less than 1 connected components output false.
    {
        cout<<"False"<<endl;
    }
}
