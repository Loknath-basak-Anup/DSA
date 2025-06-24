
#include <bits/stdc++.h>

using namespace std;

#define MAX 100

class Graph {
private:
    int adj[MAX][MAX];
    int V;

public:

    Graph() {
        cout << "Enter number of vertices: ";
        cin >> V;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge() {
        int u, v;
        cout << "Enter two vertices (u v): ";
        cin >> u >> v;

        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertices!" << endl;
            return;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
        cout << "Edge added between " << u << " and " << v << endl;
    }

    void findMinNumberEdges() {
        int start, end;
        cout << "Enter start and end vertices (u v): ";
        cin >> start >> end;

        if (start >= V || end >= V || start < 0 || end < 0) {
            cout << "Invalid vertices!" << endl;
            return;
        }

        int distance[MAX];
        bool visited[MAX];
        for (int i = 0; i < V; i++) {
            distance[i] = INT_MAX;
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;
        distance[start] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < V; i++) {
                if (adj[current][i] && !visited[i]) {
                    visited[i] = true;
                    distance[i] = distance[current] + 1;
                    q.push(i);
                }
            }
        }

        if (distance[end] == INT_MAX)
            cout << "No path found between " << start << " and " << end << endl;
        else
            cout << "Minimum number of edges between (" << start << ", " << end << "): " << distance[end] << endl;
    }

    void menu() {
        int choice;
        do {
            cout << "\n--- Graph Menu ---\n";
            cout << "1. Add Edge\n";
            cout << "2. Find Min Number of Edges (BFS)\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addEdge();
                    break;
                case 2:
                    findMinNumberEdges();
                    break;
                case 3:
                    cout << "Exiting program..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }

        } while (choice != 3);
    }
};

int main() {
    Graph g;
    g.menu();
    return 0;
}
