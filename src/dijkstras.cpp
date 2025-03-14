#include "../src/dijkstras.h"
#include <algorithm>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int V = G.numVertices;
    vector<int> distances(V, INF);
    previous.assign(V, -1); // Stores the previous node for path reconstruction

    // Min heap: (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Initialize source
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the popped node's distance is greater, it's outdated
        if (dist > distances[u]) continue;

        // Relax edges
        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u; // Track path
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}


vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    if (distances[destination] == INF) return path; // No path

    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}


void print_path(const vector<int>& path, int total) {
    if (path.empty()) {
        cout << "No path found" << endl;
        return;
    }
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) cout << " ";
    }
    cout << "\nTotal cost: " << total << endl;
}
