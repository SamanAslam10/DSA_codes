#include <iostream>
#include <queue>

using namespace std;

#define V 5
void BFStraversal(int graph[V][V], int start)
{
    bool visited[V] = {false};
    queue<int> q ;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(int i = 0 ; i < V ; i ++)
        {
            if(graph[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
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
    int start = 0;
    BFStraversal(graph , start );
    return 0;
}