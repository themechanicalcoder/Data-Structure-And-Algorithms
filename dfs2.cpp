#include<bits/stdc++.h>
using namespace std;
vector<list<int> >g;
vector<int>v;
vector<int>d;
void dfs(int u){
if(!v[u]){
        v[u]=1;
        cout<<u<<" ";
for(auto it=g[u].begin();it!=g[u].end();it++){
    if(!v[*it]){
        d[*it]=d[u]+1;
        dfs(*it);

    }
}
}}
int main(){
int n,m,a,b;
cin>>n>>m;
d.assign(n+1,0);
v.assign(n+1,0);
g.assign(n+1,list<int>());
for(int i=0;i<m;i++){
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
for(int i=1;i<=n;i++){
    if(!v[i]){
        dfs(i);
    }
}
for(int i=1;i<=n;i++){
    cout<<d[i];
}
return 0;
}
