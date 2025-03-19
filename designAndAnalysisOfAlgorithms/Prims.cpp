#include <iostream>
#include <climits>

using namespace std;

class Graph
{
private:
    int cost[10][10];
    bool visited[10];
    int mincost;

public:
    Graph()
    {
        mincost = 0;
        for (int i = 0; i < 10; i++)
        {
            visited[i] = false;
            for (int j = 0; j < 10; j++)
            {
                cost[i][j] = INT_MAX;
            }
        }
    }

    void input(int num, int edges)
    {
        cout << "\nEnter the edges in the format (node1 node2 weight):\n";
        for (int i = 0; i < edges; i++)
        {
            int u, v, weight;
            cin >> u >> v >> weight;
            cost[u][v] = weight;
            cost[v][u] = weight; // Since it's an undirected graph
        }
    }

    void display(int num)
    {
        cout << "\nThe cost of adjacency matrix:\n\n";
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j <= num; j++)
            {
                if (cost[i][j] == INT_MAX)
                    cout << "INF\t"; // Use INF to represent no edge
                else
                    cout << cost[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void prims(int num)
    {
        int a, b, u, v, min;
        visited[1] = true;
        int ne = 1; // Edge count in MST

        while (ne < num)
        {
            min = INT_MAX;
            for (int i = 1; i <= num; i++)
            {
                for (int j = 1; j <= num; j++)
                {
                    if (cost[i][j] < min && visited[i] && !visited[j])
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
            cout << "\nEdge " << ne++ << " : (" << a << " - " << b << ") cost: " << min;
            mincost += min;
            visited[b] = true;                 // Mark the new node as visited
            cost[a][b] = cost[b][a] = INT_MAX; // Remove this edge from the graph (mark as processed)
        }
        cout << "\n\nMinimum cost = " << mincost << endl;
    }
};

int main()
{
    int num, edges;
    cout << "-------------------- Prims --------------------" << endl;
    cout << "Enter the number of nodes: ";
    cin >> num;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g;
    g.input(num, edges);
    g.display(num);
    g.prims(num);

    return 0;
}