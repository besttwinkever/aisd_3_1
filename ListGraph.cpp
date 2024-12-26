#include "ListGraph.h"

ListGraph::ListGraph(int vertexCount)
{
	adjLists.resize(vertexCount);
	prevAdjLists.resize(vertexCount);
}

ListGraph::ListGraph(const IGraph& graph)
{
	adjLists.resize(graph.VerticesCount());
	prevAdjLists.resize(graph.VerticesCount());
	for (int i = 0; i < adjLists.size(); ++i) {
		adjLists[i] = graph.GetNextVertices(i);
		prevAdjLists[i] = graph.GetPrevVertices(i);
	}
}

void ListGraph::AddEdge(int from, int to)
{
	adjLists[from].push_back(to);
	prevAdjLists[to].push_back(from);
}

int ListGraph::VerticesCount() const
{
	return adjLists.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
	return adjLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
	return prevAdjLists[vertex];
}