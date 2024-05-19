#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>

using namespace std;

namespace ariel{

class Graph{

    private:
        vector<vector<int>> adjacencyMatrix;

    public:
        // Constructor
        Graph();

        // Function to get the matrix
        const vector<vector<int>> &getAdjacencyMatrix() const;

        // Function to check if the graph is weighted (contains weights other than 0 and 1).
        bool isWeightedGraph() const;

        // Function to check if a square matrix is square (number of rows equals number of columns).
        bool isSquare(const vector<vector<int>> &matrix);

        // Function to load a graph into the object.
        // The graph must be represented as a 2D vector of integers.
        void loadGraph(const vector<vector<int>> &graph);

        // Function to print the graph as a neighborhood matrix.
        void printGraph() const;

        // Function to check if the graph with negative weighted.
        bool hasNegativeWeights() const;

        // Function to check if the graph is directed (symmetric)
        bool isDirected() const;
    };
}

#endif // GRAPH_HPP
