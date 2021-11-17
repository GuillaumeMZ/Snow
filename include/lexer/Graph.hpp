#pragma once

#include <vector>

/**
 * Represents a directed graph.
 * @tparam NodeType Which type represents a node
 * @tparam EdgeType Which type represents an edge
 */
template<typename NodeType, typename EdgeType>
class Graph
{
    public:
        template<typename... Ts>
        void emplaceNode(Ts&&... args);

    private:
        void reorganizeMatrixAdd();

        std::vector<NodeType> _nodes; //should change this later to a better data structure
        std::vector<EdgeType> _relations;
};

template<typename NodeType, typename EdgeType>
template<typename... Ts>
void Graph<NodeType, EdgeType>::emplaceNode(Ts&&... args)
{
    //Adding the node inside the nodes list
    _nodes.emplace_back(std::forward<Ts>(args)...);

    //Resizing the adjacency matrix and making some space for the new node
    _relations.resize(_nodes.size() * _nodes.size());

    //Now we need to shift the existing relations inside the adjacency matrix
    reorganizeMatrixAdd();
}

template<typename NodeType, typename EdgeType>
void Graph<NodeType, EdgeType>::reorganizeMatrixAdd()
{
    /* for instance
     * 1 1 1 2 2 2 3 3 3
     * becomes 1 1 1 4 2 2 2 4 3 3 3 4 (4 4 4 4)
     * */
}