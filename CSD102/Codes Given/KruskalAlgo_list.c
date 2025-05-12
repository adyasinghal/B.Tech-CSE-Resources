#include <stdio.h>

// Structure to represent a connected, undirected and weighted graph
struct Graph
{
    
    int V;
    int E;
    struct Edge* edge;
};

// Structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};



// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};

// Function to find set (Representative of set) of an element i
int find(struct subset subsets[], int i)
{
   
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        {
		subsets[xroot].parent = yroot;
		subsets[yroot].rank++;
	}

    else if (subsets[xroot].rank > subsets[yroot].rank)
       { 
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}

    else
    {
        	subsets[yroot].parent = xroot;
        	subsets[xroot].rank++;
    }
}

int myComp(struct Edge* a, struct Edge* b)
{
    struct Edge* a1 = a;
    struct Edge* b1 = b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph)
{
    int v;
    int V = graph->V;
    struct Edge result[V];  // This will store the resultant MST
    int e = 0;  
    int i = 0;  

    
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    // Allocate memory for creating V subsets
    struct subset *subsets =(struct subset*) malloc( V * sizeof(struct subset) );

  
  // Create V subsets with single elements
    for ( v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    
}

void main()
{
    int V = 4;
    int E = 5;  
    struct Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

}