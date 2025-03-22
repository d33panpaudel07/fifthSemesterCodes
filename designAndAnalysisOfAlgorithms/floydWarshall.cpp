#include <iostream>
#include <climits>
using namespace std;

void floydWarshall(int **graph, int V);

int main()
{
    cout << "-------------------- Floyd Warshall --------------------" << endl;
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
            string input;
            cout << "Enter weight from vertex " << i << " to vertex " << j << " (or 'x' if no direct edge): ";
            cin >> input;
            if (input == "x")
                graph[i][j] = INT_MAX; // Use INT_MAX for no direct edge
            else
                graph[i][j] = stoi(input);
        }
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}

void floydWarshall(int **graph, int V)
{
    // Create a 2D array to store the shortest distances
    int **dist = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        dist[i] = new int[V];
        for (int j = 0; j < V; ++j)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
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

    // Print shortest distances
    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INT_MAX)
                cout << "x\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}
