#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >g;
vector<vector<int> >g_rev;

vector<int >v;

stack<int>s;

class graph{
    public:


        graph(int n){

            g.assign(n,vector<int>());
            g_rev.assign(n,vector<int>());
            v.assign(n,0);
        }
        void addEdge(int a,int b){

            g[a].push_back(b);
            //g[b].push_back(a);
        }

        void dfs_util(int u){

            v[u]=1;

            for(auto it=g[u].begin();it!=g[u].end();it++){
                if(!v[*it]){
                    dfs_util(*it);
                }
            }

                s.push(u);

        }

        void dfs(int n){


            for(int i=0;i<n;i++){

                if(!v[i]){
                    dfs_util(i);}

            }



            }



        void get_transpose(int n){


            for(int i=0;i<n;i++){


                    for(auto it=g[i].begin();it!=g[i].end();it++){
                        g_rev[*it].push_back(i);}
            }



        }
        void kasaraju_dfs_util(int u){
            v[u]=1;
            cout<<u<<" ";
            for(auto it=g_rev[u].begin();it!=g_rev[u].end();it++)
                if(!v[*it]){
                    kasaraju_dfs_util(*it);}

            //cout<<"\n";

        }
        void kasaraju(int n){
            v.assign(n,0);
            while(!s.empty()){
            int u=s.top();
            s.pop();
            if(!v[u]){
                kasaraju_dfs_util(u);
                cout<<"\n";

            }

        }
        }




};


int main(){
int n=5;
    graph g(n);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    g.dfs(n);

    g.get_transpose(n);

    g.kasaraju(n); return 0;

}

