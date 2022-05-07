#include "weightedGraphType.h"

using namespace std;

int main()
{
	weightedGraphType wGraph(50); //create a weighted graph and initialize it
	wGraph.createWeightedGraph();

	//for loop to iterate through all the vertices to find the shortest distance
	for (int v = 0; v < 5; v++) 
	{
		wGraph.shortestPath(v); //generates the shortest path from the vertex to all other vertices
		wGraph.printShortestDistance(v); //prints out the shortest distances from the vertex
		cout << endl;
	}

	return 0;
}