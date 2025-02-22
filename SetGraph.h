#pragma once
#include "IGraph.h"
#include <unordered_set>

class SetGraph : public IGraph {
public:
	SetGraph(int vertexCount);
	SetGraph(const IGraph& graph);

	void AddEdge(int from, int to) override;
	int VerticesCount() const override;
	std::vector<int> GetNextVertices(int vertex) const override;
	std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::unordered_set<int>> adjLists;
    std::vector<std::unordered_set<int>> prevAdjLists;
};