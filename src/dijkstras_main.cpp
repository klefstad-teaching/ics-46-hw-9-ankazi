#include "../src/dijkstras.h"

int main() {
	Graph G;
	file_to_graph("src/large.txt", G);

	int source = 0; // node 0
	int destination = 6; // shortest path to node 6
	
	vector<int> previous;
	vector<int> distances = dijkstra_shortest_path(G, source, previous);
	
	vector<int> path = extract_shortest_path(distances, previous, destination);
	print_path(path, distances[destination]);

	return 0;
}