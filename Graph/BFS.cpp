#include <iostream>
#include <queue>

using namespace std;

#define n 5
queue<int> q;
int Visited[n] = {0}; 

void BFS(int i , int A[n][n])
{
    int u = 0;
    printf("%d" , i);
    Visited[i] = 1;
    q.push(i);

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int a = 0 ; a < n ; a ++)
        {
            if(A[u][a] == 1 && Visited[a] == 0 )
            {
                printf("%d" , a);
                Visited[a] = 1;
                q.push(a);
            }
        }
    }
}
int main()
{
    int graph[5][5] = 
    {
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 0}, 
        {1, 0, 0, 0, 1}, 
        {0, 1, 0, 0, 0}, 
        {0, 0, 1, 0, 0}  
    }; 
    BFS(2,graph);
    return 0;
}