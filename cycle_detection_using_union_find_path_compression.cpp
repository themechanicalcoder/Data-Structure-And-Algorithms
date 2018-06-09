#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<ii >g(5);
vector<int>parent;
vector<int >rank1;
int find(int u){
    if(u!=parent[u])
        parent[u]=find(parent[u]);


return parent[u];

}
void union_set(int x,int y){
    int xset=find(x);
    int yset=find(y);
    if(rank1[xset]<rank1[yset])
        parent[xset]=yset;
    else if(rank1[xset]>rank1[yset])
        parent[yset]=xset;
    else{
        parent[xset]=yset;
        rank1[yset]+=1;
    }


}
bool hasCycle(int n){


    for(int i=0;i<n;i++){

        int xroot=find(g[i].first);
        int yroot=find(g[i].second);

    if(xroot==yroot){
       return true;
    }

     union_set(xroot,yroot);

    }

return false;

}


int main(){
int n=4;
parent.assign(n,-1);
rank1.assign(n,0);

for(int i=0;i<n;i++)
    parent[i]=i;
g[0]={0,1};
g[1]={1,2};
g[2]={2,3};
g[3]={1,3};

if(hasCycle(4))
    cout<<"has cycle";
else
    cout<<"no cycle";


return 0;



}
