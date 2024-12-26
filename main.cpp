#include <iostream>
#include <queue>
#include <cassert>

#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void BFS(const IGraph& graph, int vertex, std::vector<int>& outputVector)
{
	outputVector.clear();
	std::vector<bool> visited(graph.VerticesCount(), false);
	std::queue<int> bfsQueue;
	bfsQueue.push(vertex);
	visited[vertex] = true;
	while (!bfsQueue.empty()) {
		int current = bfsQueue.front();
		bfsQueue.pop();
		outputVector.push_back(current);
		std::vector<int> adjList = graph.GetNextVertices(current);
		for (int i = 0; i < adjList.size(); ++i) {
			if (!visited[adjList[i]]) {
				bfsQueue.push(adjList[i]);
				visited[adjList[i]] = true;
			}
		}
	}
}

void TestGraph(IGraph& graph, std::vector<int>& rightVector)
{
	std::vector<int> currentVector = {};
	BFS(graph, 0, currentVector);
	assert(currentVector == rightVector);
}

int main() {

	std::vector<int> rightVector = {0, 1, 3, 4, 2, 5, 6};
    IGraph* g = new ListGraph(7);
	g->AddEdge(0, 1);
	g->AddEdge(0, 3);
	g->AddEdge(0, 4);
	g->AddEdge(1, 2);
	g->AddEdge(1, 3);
	g->AddEdge(2, 5);
	g->AddEdge(3, 4);
	g->AddEdge(3, 5);
	g->AddEdge(3, 6);
	g->AddEdge(4, 6);
	g->AddEdge(6, 5);

	ListGraph listGraph = ListGraph(*g);
	std::cout << "Testing ListGraph" << std::endl;
	TestGraph(listGraph, rightVector);

	MatrixGraph matrixGraph = MatrixGraph(*g);
	std::cout << "Testing MatrixGraph" << std::endl;
	TestGraph(matrixGraph, rightVector);

	SetGraph setGraph = SetGraph(*g);
	std::cout << "Testing SetGraph" << std::endl;
	TestGraph(setGraph, rightVector);

	ArcGraph arcGraph = ArcGraph(*g);
	std::cout << "Testing ArcGraph" << std::endl;
	TestGraph(arcGraph, rightVector);

	delete g;
    return 0;
}