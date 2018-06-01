//UVA 10004
#include<bits/stdc++.h>
using namespace std;
vector<vector<int > >g;
vector<int>color;
class graph{
    public:
        graph(int n){
            g.assign(n,vector<int>());
            color.assign(n,-1);

        }

        void addEdge(int u,int v){
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool bipartite_check_util(int src){
            color[src]=1;
            queue<int>q;
            q.push(src);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto it=g[u].begin();it!=g[u].end();it++){
                    if(*it==u)
                        return false;
                    if(color[*it]==-1){
                        color[*it]=1-color[u];
                        q.push(*it);
                    }
                     if(color[*it]==color[u])
                        return false;

                }

            }
        return true ;
        }
        bool bipartite_check(int n){
            color.assign(n,-1);
        for(int i=0;i<n;i++){
                if(color[i]==-1){
                    bool success= bipartite_check_util(i);
                    if(success==false){
                        return false;
                    }

                }
            }

        return true;

        }

};



int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
int v;
while(cin>>v){
    if(v==0)
        return 0;

    graph obj(v);
    int l,a,b;cin>>l;
    for(int i=0;i<l;i++){
        cin>>a>>b;
        obj.addEdge(a,b);
    }
    bool success=obj.bipartite_check(v);
    if(success==true)
        cout<<"BICOLORABLE."<<"\n";
    if(success==false)
        cout<<"NOT BICOLORABLE."<<"\n";



}

 return 0;
}
