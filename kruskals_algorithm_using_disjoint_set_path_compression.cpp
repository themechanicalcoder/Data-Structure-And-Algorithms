#include<bits/stdc++.h>
using namespace std;
//typedef pair<int ,int> ii;
vector<pair<int,pair<int,int > > >g(1000);
vector<int>parent;
vector<int>rnk;
int mst_wt=0;

int find(int u){
    if(u!=parent[u])
        parent[u]=find(parent[u]);

return parent[u];
}

void union1(int x,int y){
    int xset=find(x);
    int yset=find(y);

    if(rnk[xset]>rnk[yset])
        parent[yset]=xset;
    else if(rnk[yset]>rnk[xset])
        parent[xset]=yset;
    else{
        parent[yset]=xset;
        rnk[xset]+=1;
    }




}


int  kruskal(int e){

    for(auto it=g.begin();it!=g.end();it++){
        int u=it->second.first;
        int v=it->second.second;

        int setu=find(u);
        int setv=find(v);

        if(setu!=setv){
            cout<<u<<" "<<v<<"\n";
            mst_wt+=it->first;
            union1(setu,setv);
        }


    }


return mst_wt;
}

int main(){
int n,e;cin>>n>>e;
for(int i=0;i<e;i++){
    int a,b,w;
    cin>>a>>b>>w;
   g[i]={w,{a,b}};

}
sort(g.begin(),g.end());
parent.assign(n,0);
rnk.assign(n,0);
for(int i=0;i<n;i++)
    parent[i]=i;
kruskal( e);
cout<<"weight = "<<mst_wt;
return 0;


}


