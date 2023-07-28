#include <iostream>
using namespace std;

int visited[20]={0}, dis[20]={0}, n;

void dijkstras(int source, int cost[20][20]){
    int i,j,min,u,w;
    for (i=1; i <= n; i++){
        visited[i]=0;
        dis[i] = cost[source][i];
    }
    visited[source]=1;
    dis[source]=0;
    for (j=2,min=999;j<=n;j++){
        for (i=1;i<=n;i++){
            if (!visited[i]){
                if (dis[i] < min){
                    min = dis[i];
                    u = i;
                }
            }
        }
        visited[u] = 1;
        for (w=1;w<=n;w++){
            if (cost[u][w]!= 999 && visited[w] == 0){
                if (dis[w] > cost[u][w] + dis[u])
                    dis[w] = cost[u][w] + dis[u];
            }
        }
    }
}

int main()
{
    int i, j, n, source, cost[20][20];
    cout << "Enter no. of vertices:";
    cin >> n;
    cout <<"Enter the cost  matrix(999 for infinity)\n";
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            cin >> cost[i][j];
        }
    }
    cout <<"Enter the source node:";
    cin >>source;
    dijkstras(source, cost);
    for (i=1;i<=n;i++)
        if (i!=source)
            cout << "\nShortest path from" << source << "to" << i << "is" << dis[i];
}
