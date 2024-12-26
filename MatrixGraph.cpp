#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertexCount)
{
    adjMatrix.resize(vertexCount);
    prevAdjMatrix.resize(vertexCount);
    for (int i = 0; i < vertexCount; ++i) {
        adjMatrix[i].resize(vertexCount, 0);
        prevAdjMatrix[i].resize(vertexCount, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph)
{
    adjMatrix.resize(graph.VerticesCount());
    prevAdjMatrix.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        adjMatrix[i].resize(graph.VerticesCount(), 0);
        prevAdjMatrix[i].resize(graph.VerticesCount(), 0);
    }
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);
        for (int j = 0; j < nextVertices.size(); ++j) {
            adjMatrix[i][nextVertices[j]] = 1;
        }
        std::vector<int> prevVertices = graph.GetPrevVertices(i);
        for (int j = 0; j < prevVertices.size(); ++j) {
            prevAdjMatrix[i][prevVertices[j]] = 1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to)
{
    adjMatrix[from][to] = 1;
    prevAdjMatrix[to][from] = 1;
}

int MatrixGraph::VerticesCount() const
{
    return adjMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    std::vector<int> nextVertices;
    for (int i = 0; i < adjMatrix[vertex].size(); ++i) {
        if (adjMatrix[vertex][i] == 1) {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevVertices;
    for (int i = 0; i < prevAdjMatrix[vertex].size(); ++i) {
        if (prevAdjMatrix[vertex][i] == 1) {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}