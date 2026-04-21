#include <iostream>

using namespace std;

#define V 5
int VisistedA[V] = {0};
int graph[5][5]= 
    {
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 0}, 
        {1, 0, 0, 0, 1}, 
        {0, 1, 0, 0, 0}, 
        {0, 0, 1, 0, 0}  
    };

void DFS(int start)
{
    if(VisistedA[start] == 0)
    {
        printf("%d%s" , start , " ");
        VisistedA[start] = 1;

        for(int v = 0 ; v < V ; v ++)
        {
            if(graph[start][v] == 1 && VisistedA[v] != 1)
            {
                DFS(v);
            }
        }
    }
}
int main()
{ 
    DFS(0);
    return 0;
}