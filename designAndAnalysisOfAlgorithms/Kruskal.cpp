#include <iostream>
#include <climits>
using namespace std;

class Kruskal
{
private:
    int visited[10] = {0}; // Array to keep track of visited vertices

public:
    void kruskal(int w[10][10], int n)
    {
        int min, sum = 0, ne = 0;
        int u, v, a, b;

        while (ne < n - 1)
        {
            min = 999;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (w[i][j] < min)
                    {
                        min = w[i][j];
                        u = a = i;
                        v = b = j;
                    }
                }
            }

            while (visited[u])
                u = visited[u];
            while (visited[v])
                v = visited[v];

            if (u != v)
            {
                ne++;
                sum += min;
                cout << "\nEdge (" << a << " , " << b << ") --> " << min;
                visited[v] = u; // Union the sets
            }

            w[a][b] = w[b][a] = 999;
        }

        cout << "\nCost of minimum spanning tree : " << sum << endl;
    }
};

int main()
{
    int w[10][10], n;

    Kruskal graph;

    cout << "\nProgram to implement Kruskal's Algorithm : \n";
    cout << "\nEnter no. of vertices : ";
    cin >> n;

    cout << "\nEnter the adjacency matrix : \n";
    // Take the adjacency matrix as input
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (w[i][j] == 0)
                w[i][j] = 999;
        }
    }

    graph.kruskal(w, n);

    return 0;
}