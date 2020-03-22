
#include<bits/stdc++.h>


#define V 4


#define INF 99999


void printSolution(int dist[][V]);


void printSolution(int dist[][V])
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int g[V][V]){
    int d[V][V],j,k,i;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            d[i][j]=g[i][j];
        }
    }

    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
printSolution(d);
}


int main()
{

    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };


    floydWarshall(graph);
    return 0;
}
