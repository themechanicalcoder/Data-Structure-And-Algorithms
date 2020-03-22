#include<bits/stdc++.h>
using namespace std;
vector<list<int> >g;
vector<int>v;
vector<int>s;

bool iscycle(int u){

v[u]=1;
s[u]=1;

for(auto it=g[u].begin();it!=g[u].end();it++){

    if(!v[*it]&&iscycle(*it)){
        return true;
    }
    if(s[*it]){
        return true;
    }
}

//s[u]=0;
return false;
}





int main(){
int n,m,a,b;
cin>>n>>m;
s.assign(n+1,0);
v.assign(n+1,0);
g.assign(n+1,list<int>());
for(int i=0;i<m;i++){
    cin>>a>>b;
    g[a].push_back(b);
    //g[b].push_back(a);
}
bool u;
for(int i=1;i<=n;i++){
    if(!v[i]){
      u =  iscycle(i);
    }
}
cout<<u;


return 0;
}
