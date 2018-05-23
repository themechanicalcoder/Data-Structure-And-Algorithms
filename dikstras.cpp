#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int> ipair;
//#define infi=100000;
vector<vector<ipair>>g;
vector<int>d;

 void spath(int s){

 priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
 d[s]=0;
 pq.push(make_pair(0,s));
 while(!pq.empty()) {
    int u=pq.top().second;
    pq.pop();

    for(auto it=g[u].begin();it!=g[u].end();it++){
         int v=(*it).first;
         int weight=(*it).second;
         if(d[v]>d[u]+weight){
               d[v]=d[u]+weight;
               pq.push(make_pair(d[v],v));
         }
    }

 }







 }




int main(){
int n,m,a,b,l,s;
cin>>n>>m>>s;
g.assign(n+1,vector<ipair>());
d.assign(n+1,100000);
for(int i=0;i<m;i++){
    cin>>a>>b>>l;
    g[a].push_back(make_pair(b,l));
    g[b].push_back(make_pair(a,l));

}

spath(s);
for(int i=0;i<n+1;i++){
    cout<<d[i]<<"\n";
}
return 0;
}
