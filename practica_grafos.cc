#include <iostream>

using namespace std;

const int kMaxNodes = 6;

struct Graph
{
    int matrix[kMaxNodes][kMaxNodes];
    int size;
};

void InitializeGraph(Graph &graph, int size)
{
    graph.size = size;

    for (int i = 0; i < size; i++)
    {
       for (int j = 0; j < size; j++)
       {
        graph.matrix[i][j] = 0;
       }
       
    }
    
}

void AddEdge(Graph &graph, int from, int to)
{
    graph.matrix[from][to]=1;
    graph.matrix[to][from]=1;
}

bool HasEdge(Graph &graph, int from, int to)
{
    if (graph.matrix[from][to] == 1)
    {
        return true;
    }
    
}

int Degree(const Graph &graph, int node)
{
    int count = 0;
    for (int j = 0; j < graph.size; j++)
    {
        if (graph.matrix[node][j]==1)
        {
            count ++;
        }
        
    }
    
    return count;
}

void RemoveEdge(Graph &graph, int from, int to)
{
    graph.matrix[from][to]=0;
    graph.matrix[to][from]=0;
}


int main()
{

}