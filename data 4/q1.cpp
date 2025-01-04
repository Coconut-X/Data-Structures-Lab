#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class graph {
public:
    vector<vector<int>> adjList;
    vector<bool> visited;

    graph(int n) {
        
        adjList.resize(n);
        visited.resize(n, false);
    }

    void addEdge(int x, int y) {

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    void dfs(int s) {

        visited[s] = true;
        for (int neighbor : adjList[s]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }

    void criticalConnections() {
        vector<pair<int, int>> edges;

        for (int i = 0; i < adjList.size(); i++) {
            for (int neighbor : adjList[i]) {
                if (i < neighbor) // to avoid duplicates
                    edges.push_back({i, neighbor});
            }
        }

        for (auto edge : edges) {
            int x = edge.first, y = edge.second;

            adjList[x].erase(find(adjList[x].begin(), adjList[x].end(), y));
            adjList[y].erase(find(adjList[y].begin(), adjList[y].end(), x));

            fill(visited.begin(), visited.end(), false);

            dfs(0);
            bool isConnected = true;
            for (bool nodeVisited : visited) 
            {
                if (!nodeVisited) 
                {
                    isConnected = false;
                    break;
                }
            }

            if (!isConnected) 
            {
                cout << x << " - " << y << endl;
            }

            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
    }
};

int main() {
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "Critical Connections: " << endl;
    g.criticalConnections();

    return 0;
}
