/*a DAG must contain one vertex with zero incoming edges ;
take out  that vertex and push in queue and cut out the outgoing edges
now the new graph(as it is also a DAG) has same property keep on doing the same and push them once their incoming edges is equal to 0
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int > >g;
vector<int>incEdges;
class graph{
    public:
        graph(int n){
            g.assign(n,vector<int>());
            incEdges.assign(n,0);

        }

        void addEdge(int u,int v){
            g[u].push_back(v);
        }
        void incomingEdges(int n){
            for(int i=0;i<n;i++){
                for(auto it=g[i].begin();it!=g[i].end();it++)
                    incEdges[*it]+=1;
            }
        }
        vector<int> kahns(int n){
            int count=0;
            vector<int >top_order;
            queue<int>q;
            for(int i=0;i<n;i++){
                if(incEdges[i]==0)
                    q.push(i);
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                top_order.push_back(u);
                for(auto it=g[u].begin();it!=g[u].end();it++){
                    incEdges[*it]-=1;
                    if(incEdges[*it]==0)
                        q.push(*it);
                        count+=1;
                }
            }
        if(count!=n)
            return vector<int>();//cycle exists

        return top_order;
        }


};



int main(){
int n=6;
//cin>>n;
    graph obj(n);
    obj.addEdge(5, 2);
    obj.addEdge(5, 0);
    obj.addEdge(4, 0);
    obj.addEdge(4, 1);
    obj.addEdge(2, 3);
    obj.addEdge(3, 1);
    obj.incomingEdges(n);
    auto v=obj.kahns(n);
    if(v.size()==0)
        cout<<"cycle exists";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
}
 return 0;
}
