#include "Graph.hpp"
#include <vector>
#include <iostream>

using namespace std;
    
namespace ariel{

    // Constructor
    Graph::Graph(){}

    // Function to get the matrix
    const vector<vector<int>>& Graph::getAdjacencyMatrix() const {return adjacencyMatrix;}

    // Function to check if the graph is weighted (contains weights other than 0 and 1).
    bool Graph::isWeightedGraph() const {
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = 0; j < getAdjacencyMatrix().size(); ++j) {
                if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1) {
                    return true; // Found a weight other than 0 or 1
                }   
            }
        }  
        return false; // No weights other than 0 and 1 found
    }

    // Function to check if a square matrix is square (number of rows equals number of columns).
    bool Graph::isSquare(const vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        for (size_t i = 0; i < numRows; ++i) {
            if (matrix[i].size() != numRows) {
                return false; // Number of columns is not equal to the number of rows
            }
        }
        return true; // Number of rows and columns are equal
    }

    // Function to load a graph into the object.
    // The graph must be represented as a 2D vector of integers.
    void Graph::loadGraph(const vector<vector<int>>& graph) {
        if (!isSquare(graph)) {
            throw std::invalid_argument("Error: Graph size is not square."); // Throw a runtime_error exception
        }
        adjacencyMatrix = graph;
        if(adjacencyMatrix.size() == 0){throw std::invalid_argument("Error: It is impossible to infer things about the graph, because no vertices were inserted.");}
    }

    // Function to print the graph as a neighborhood matrix.
    void Graph::printGraph() const {
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = 0; j < getAdjacencyMatrix().size(); ++j) {cout << adjacencyMatrix[i][j] << " ";}
            cout << endl;
        }
    }

    // Function to check if the graph with negative weighted.
    bool Graph::hasNegativeWeights() const {
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = 0; j < getAdjacencyMatrix().size(); ++j) {
                if (adjacencyMatrix[i][j] < 0) {
                    return true; // Found a negative weight
                }
            }
        }
        return false; // No negative weights found
    }

    // Function to check if the graph is directed (symmetric)
    bool Graph::isDirected() const {
        // Check if the adjacency matrix is symmetric
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = i + 1; j < getAdjacencyMatrix().size(); ++j) {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                    return true; // Graph is directed
                }
            }
        }
        return false; // Graph is undirected
    }

};