#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertexCount)
{
    edges.resize(vertexCount);
}

ArcGraph::ArcGraph(const IGraph& graph)
{
    edges.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);
        for (int j = 0; j < nextVertices.size(); ++j) {
            edges.push_back(std::make_pair(i, nextVertices[j]));
        }
    }
}

void ArcGraph::AddEdge(int from, int to)
{
    edges.push_back(std::make_pair(from, to));
}

int ArcGraph::VerticesCount() const
{
    return edges.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    std::vector<int> nextVertices;
    for (int i = 0; i < edges.size(); ++i) {
        if (edges[i].first == vertex) {
            nextVertices.push_back(edges[i].second);
        }
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevVertices;
    for (int i = 0; i < edges.size(); ++i) {
        if (edges[i].second == vertex) {
            prevVertices.push_back(edges[i].first);
        }
    }
    return prevVertices;
}