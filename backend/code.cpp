#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<ll> visit;
vector<vector< vector<ll> > >  adj;
vector<set <ll> > ma;
void dfs(ll cur ,ll time){
    if(time>visit[cur])return ;
    visit[cur]=time;
    if(ma[cur].find(time)!=ma[cur].end()){

       auto i=ma[cur].find(time);
       while(i!=ma[cur].end()  && (*i)==time){
        i++;
        time++;
       }
       time-=1;
    }
    for(auto i: adj[cur]){
        dfs(i[0],time+i[1]);
    }


}
void add(ll a,ll b ,ll c){
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){

      int n,m;
      cin>>n>>m;
      vector<ll> emp(n+1,INT_MAX);
      vector<vector<vector< ll> > > emp2(n+1);
      vector<set<ll> > emp3(n+1);
      visit=emp;
      adj=emp2;
      ma=emp3;
      ll a,b,c;
      for(int i=0;i<m;i++){
          cin>>a>>b>>c;
          add(a,b,c);
      }
      for(int i=0;i<n;i++){
        ll k ;
        cin>>k;
       for(int j=0;j<k;j++){
            ll x;
            cin>>x;
            ma[i+1].insert(x);
        }
      }
      dfs(1,0);
      if(visit[n]==INT_MAX){
        cout<<-1<<endl;
      }

      else cout<<visit[n]<<endl;


    }


}
