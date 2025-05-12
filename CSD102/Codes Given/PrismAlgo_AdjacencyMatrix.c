//Prim's Algorithm

#include <stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 9

void main()
{
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {0, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0},
                     };
    primMST(graph);
}

void primMST(int graph[V][V])
{
     int i, v, parent[V];
     int key[V];
     bool mstSet[V];
     for (i = 0; i < V; i++)
     {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i]=0;
     }
     key[0] = 0;
     parent[0] = -1;
     for (i = 0; i < V-1; i++)
     {
        	int u = minKey(key, mstSet);
        	mstSet[u] = true;
       	for ( v = 0; v < V; v++)
          		if (graph[u][v]!=0 && mstSet[v] == false && graph[u][v] <  key[v])
             		{
			parent[v]  = u;
             			key[v] = graph[u][v];
             		}
     }
     printMST(parent, V, graph);
}

int minKey(int key[ ], bool mstSet[ ])
{
   int v;
   int min = INT_MAX;
   int min_index;
   for ( v = 0; v < V; v++)
   {
            if (mstSet[v] == false && key[v] < min)
            {
	min = key[v];
         	min_index = v;
            }
   }
   return min_index;
}

int printMST(int parent[ ], int n, int graph[V][V])
{
   int i;
   printf("Edge   Weight\n");
   for ( i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}