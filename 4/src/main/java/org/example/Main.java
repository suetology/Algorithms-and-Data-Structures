package org.example;

public class Main {
    public static void main(String[] args) {
        Graph<Character> graph = new AdjacencyListGraph<>();

        graph.addVertex('A');
        graph.addVertex('B');
        graph.addVertex('S');
        graph.addVertex('G');
        graph.addVertex('H');
        graph.addVertex('F');
        graph.addVertex('C');
        graph.addVertex('D');
        graph.addVertex('E');

        graph.addEdge('B', 'A');
        graph.addEdge('A', 'S');
        graph.addEdge('S', 'G');
        graph.addEdge('G', 'H');
        graph.addEdge('S', 'C');
        graph.addEdge('H', 'E');
        graph.addEdge('G', 'F');
        graph.addEdge('C', 'F');
        graph.addEdge('C', 'D');
        graph.addEdge('C', 'E');

        Tree<Character> tree = graph.toTree('A');

        System.out.println(tree);
    }
}