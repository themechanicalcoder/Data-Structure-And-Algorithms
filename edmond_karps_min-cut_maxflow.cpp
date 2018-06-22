#include<bits/stdc++.h>
using namespace std;
#define V 6
int rgraph[V][V];
int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
vector<int >parent;
vector<int >vis;
int s,t;

//checking the nodes connected to s
void dfs(int s){
    vis.assign(V,0);
    for(int i=0;i<V;i++){
       if(!vis[i] && rgraph[s][i]){
        vis[i]=1;
        dfs(i);
       }
    }



}


bool bfs(){

    parent.assign(V,-1);
    vis.assign(V,0);
    vis[s]=1;
    queue<int >q;
    q.push(s);
    while(!q.empty()){
        int  u=q.front();
        q.pop();

        for(int v=0;v<V;v++){
            if(vis[v]==0 && rgraph[u][v]>0){
                q.push(v);
                vis[v]=1;
                parent[v]=u;

            }
        }
    }

return (vis[t]==1);
}



int karps(){
    int max_flow=0;

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            rgraph[i][j]=graph[i][j];}
    }

    while(bfs()){
        int path_flow=INT_MAX;
        int v;

        for(v=t;v!=s;v=parent[v]){
            int u=parent[v];

            path_flow=min(path_flow,rgraph[u][v]);
        }

        for(v=t;v!=s;v=parent[v]){
            int u=parent[v];
            rgraph[u][v]-=path_flow;//subtraction the path_flow
            rgraph[v][u]+=path_flow;//reversing the direction from v-u
            //remembering tip the particle after reaching a node can flow either to
            //the neighbour or can return back
        }

        max_flow+=path_flow;
    }
//if a node i is connected to s and its neighbour is not connected implies
//that the edge i-j is the bridge
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            if(vis[i] &&!vis[j] && graph[i][j])
                cout<<i<<" - "<<j<<"\n";
    }

return max_flow;
}



int main(){
 s=0,t=5;


cout<<"Max_flow = "<<karps()<<"\n";

return 0;
}
