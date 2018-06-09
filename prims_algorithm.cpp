#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int> ipair;
//#define infi=100000;
vector<vector<ipair>>g;
vector<int>d;
vector < int>mst;
vector<int>parent;
void prims(int s){
//v.assign(n+1,0);
d[s]=0;
priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
pq.push(make_pair(0,s));


while(!pq.empty()){

    int u=pq.top().first;
    //int weight=pq.top().second;
    pq.pop();
    mst[u]=1;
    for(auto it=g[u].begin();it!=g[u].end();it++){

        int v=(*it).first;
        int weight=(*it).second;

        if(d[v]>weight&&mst[v]==0){
            d[v]=weight;
            pq.push(make_pair(d[v],v));
            parent[v]=u;
            mst[v]=1;

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
parent.assign(n+1,0);
prims(s);

for(int i=0;i<n+1;i++){
    cout<<d[i]<<"\n";
}
return 0;
}
