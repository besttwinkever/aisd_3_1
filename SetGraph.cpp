#include "SetGraph.h"

SetGraph::SetGraph(int vertexCount)
{
    adjLists.resize(vertexCount);
    prevAdjLists.resize(vertexCount);
}

SetGraph::SetGraph(const IGraph& graph)
{
    adjLists.resize(graph.VerticesCount());
    prevAdjLists.resize(graph.VerticesCount());
    for (int i = 0; i < adjLists.size(); ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);
        for (int j = 0; j < nextVertices.size(); ++j) {
            adjLists[i].insert(nextVertices[j]);
        }
        std::vector<int> prevVertices = graph.GetPrevVertices(i);
        for (int j = 0; j < prevVertices.size(); ++j) {
            prevAdjLists[i].insert(prevVertices[j]);
        }
    }
}

void SetGraph::AddEdge(int from, int to)
{
    adjLists[from].insert(to);
    prevAdjLists[to].insert(from);
}

int SetGraph::VerticesCount() const
{
    return adjLists.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    std::vector<int> nextVertices;
    for (auto it = adjLists[vertex].begin(); it != adjLists[vertex].end(); ++it) {
        nextVertices.push_back(*it);
    }
    return nextVertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevVertices;
    for (auto it = prevAdjLists[vertex].begin(); it != prevAdjLists[vertex].end(); ++it) {
        prevVertices.push_back(*it);
    }
    return prevVertices;
}