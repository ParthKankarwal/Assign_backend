#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void Solve_bfs(vector < vector <int> > &res, vector <int> ans, int n, int u, vector <int> &Dt)
{
    queue <int>Q;
    Q.push(u);
    ans[u] = 1;
    vector <int> distance;
    distance.resize(n+1);
    distance[u] = 0;
    while(!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        for(int i=0;i<res[t].size();i++)
        {
            if(ans[res[t][i]] == 0)
            {
                ans[res[t][i]] = 1;
                distance[res[t][i]] = 1 + distance[t];
                Q.push(res[t][i]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        Dt[i] = max(Dt[i],distance[i]);
    }
}
int main()
{
    int n,h,x;
    cin>>n>>h>>x;
    vector <int> hot;
    for(int i=0;i<h;i++)
    {
        int p;
        cin>>p;
        hot.push_back(p);
    }
    vector < vector <int> > res;
    res.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        res[a].push_back(b);
        res[b].push_back(a);
    }
    vector <int> ans;
    ans.resize(n+1);
    vector <int> dist;
    dist.resize(n+1);
    dist.assign(n+1,-1);
    for(int i=0;i<h;i++)
    {
        Solve_bfs(res, ans, n, hot[i],dist);
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i] <= x)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}