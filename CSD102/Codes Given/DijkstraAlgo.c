//Dijkstra's Algorithm

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
                                 {8, 0, 0, 0, 0, 2, 0, 1, 6},
                                 {0, 11, 0, 0, 0, 0, 1, 0, 7},
                                 {0, 0, 2, 0, 0, 0, 6, 7, 0},
                     };
    dijkstra(graph,0);
}

void dijkstra(int graph[ ][V], int source)
{
     int i, v;
     int distance[V];
     bool sptSet[V];
     for (i = 0; i < V; i++)
     {
        distance[i] = INT_MAX;
        sptSet[i] = false;
     }
     distance[0] = 0;
     for (i = 0; i < V-1; i++)
     {
        	int u = minDistance(distance, sptSet);
        	sptSet[u] = true;
       	for ( v = 0; v < V; v++)
	{
          		if (graph[u][v]!=0 && sptSet[v] == false && distance[u]+graph[u][v] <  distance[v])
             			distance[v] = distance[u]+graph[u][v];
	}     
     }
     print(distance);
}

int minDistance(int distance[ ], bool sptSet[ ])
{
   int v;
   int min = INT_MAX;
   int min_index;
   for ( v = 0; v < V; v++)
   {
            if (sptSet[v] == false && distance[v] < min)
            {
	min = distance[v];
         	min_index = v;
            }
   }
   return min_index;
}

int print(int distance[ ])
{
   int i;
   printf("Vertex \t Distance from Source\n");
   for ( i = 0; i < V; i++)
      printf("%d \t %d \n", i, distance[i]);
}