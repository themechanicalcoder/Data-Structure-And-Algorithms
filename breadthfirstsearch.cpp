#include<bits/stdc++.h>
using namespace std;
vector<vector<int > >g;
vector<int >v;

void bfs(int u){

v[u]=1;
queue<int >q;
q.push(u);
while(!q.empty()){
    int f=q.front();
    cout<<f;
    q.pop();
    for(auto it =g[f].begin();it!=g[f].end();it++){
        if(!v[*it]){
            q.push(*it);
            v[*it]=1;
        }
    }

}
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m,a,b;
cin>>n>>m;
v.assign(n+1,0);
g.assign(n+1,vector<int>());
for(int i=0;i<m;i++){
  cin>>a>>b;
  g[a].push_back(b);
  g[b].push_back(a);

}
for(int i=1;i<n+1;i++){
    if(!v[i]){
     bfs(i);
    }
}
return 0;
}
