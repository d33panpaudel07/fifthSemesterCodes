#include <iostream>
#include <climits>

using namespace std;
void floydWarshall(int **graph, int V);

int main()
{
    int V;

    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    // Create a 2D array to represent the graph and initialize it with adjacency matrix
    int **graph = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; ++j)
        {
            cout << "Enter the weight from vertex " << i << " to vertex " << j << " (or INT_MAX if no direct edge): ";
            cin >> graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm and display the results
    floydWarshall(graph, V);

    return 0;
}

void floydWarshall(int **graph, int V)
{
    // Create a 2D array to store the shortest distances between every pair of vertices
    int **dist = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        dist[i] = new int[V];
        for (int j = 0; j < V; ++j)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply the Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}