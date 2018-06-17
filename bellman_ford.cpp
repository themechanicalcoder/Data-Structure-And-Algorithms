#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int >ii;
vector<pair<int,ii> >g;
vector<int>d;
vector<int>parent;
int v,e,w;

bool bellman_ford(int src){

    //calculating the minimum ditances
    d[src]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
                int u=g[j].second.first;
                int v=g[j].second.second;
                int wt=g[j].first;
                if(d[u]!=INT_MAX && d[v]>d[u]+wt){
                    d[v]=d[u]+wt;
                    parent[v]=u;
                }
        }
    }
    //checking for negative weight cycles
    for(int i=0;i<e;i++){
        int u,v,wt;
        u=g[i].second.first;
        v=g[i].second.second;
        wt=g[i].first;
        if(d[u]!=INT_MAX && d[v]>d[u]+wt){
            cout<<"The given graph contains negative weight cycles \n";
            return false;
        }
    }


}

void print(){
    for(int u=0;u<v;u++){
        cout<<"distance = "<<setw(2)<<d[u]<<" parent = "<<setw(2)<<parent[u]<<"\n";
    }

}


int main(){
cin>>v>>e;
d.assign(v,INT_MAX);
parent.assign(v,-1);
for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b>>w;
    g.push_back({w,{a,b}});
}
bool a=bellman_ford(0);
if(a)
     print();
return 0;
}
