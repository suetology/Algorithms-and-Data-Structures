package org.example;

import java.util.*;

public class AdjacencyListGraph<T> extends Graph<T> {
    private final Map<Vertex<T>, List<Vertex<T>>> adjacencyVertices = new HashMap<>();

    @Override
    public boolean isEmpty() {
        return adjacencyVertices.isEmpty();
    }

    @Override
    public boolean containsVertex(T data) {
        Vertex<T> vertex = new Vertex<T>(data);
        return adjacencyVertices.containsKey(vertex);
    }

    @Override
    public int verticesCount() {
        return adjacencyVertices.size();
    }

    @Override
    public List<Vertex<T>> getNeighbours(T data) {
        Vertex<T> vertex = new Vertex<T>(data);
        if (!adjacencyVertices.containsKey(vertex))
            throw new IllegalArgumentException("Graph does not contain such vertex");

        return adjacencyVertices.get(vertex);
    }

    @Override
    public void addVertex(T data) {
        Vertex<T> vertex = new Vertex<T>(data);
        if (adjacencyVertices.containsKey(vertex))
            throw new IllegalArgumentException("Graph already contains node with data");

        adjacencyVertices.put(vertex, new ArrayList<>());
    }

    @Override
    public void removeVertex(T data) {
        Vertex<T> vertex = new Vertex<T>(data);
        adjacencyVertices.remove(vertex);
        adjacencyVertices.values().forEach(e -> e.remove(vertex));
    }

    @Override
    public void clear() {
        adjacencyVertices.values().forEach(e -> e.clear());
        adjacencyVertices.clear();
    }

    @Override
    public void addEdge(T data1, T data2) {
        Vertex<T> vertex1 = new Vertex<T>(data1);
        Vertex<T> vertex2 = new Vertex<T>(data2);

        List<Vertex<T>> l1 = adjacencyVertices.get(vertex1);
        List<Vertex<T>> l2 = adjacencyVertices.get(vertex2);

        if (l1 == null || l2 == null)
            throw new IllegalArgumentException("Graph does not contain some of the data");

        l1.add(vertex2);
        l2.add(vertex1);
    }

    @Override
    public void removeEdge(T data1, T data2) {
        Vertex<T> vertex1 = new Vertex<T>(data1);
        Vertex<T> vertex2 = new Vertex<T>(data2);

        List<Vertex<T>> l1 = adjacencyVertices.get(vertex1);
        List<Vertex<T>> l2 = adjacencyVertices.get(vertex2);

        if (l1 == null || l2 == null)
            throw new IllegalArgumentException("Graph does not contain such edge");

        l1.remove(vertex2);
        l2.remove(vertex1);
    }

    @Override
    public Tree<T> toTree(T rootData) {
        Vertex<T> vertex = new Vertex<T>(rootData);
        if (!adjacencyVertices.containsKey(vertex))
            return null;

        Tree<T> tree = new Tree<>();
        Set<T> visited = new LinkedHashSet<>();
        Stack<T> stack = new Stack<>();
        stack.push(rootData);
        while (!stack.isEmpty()) {
            T data = stack.pop();
            if (!visited.contains(data)) {
                visited.add(data);
                if (!tree.contains(data))
                    tree.add(data);
                for (Vertex<T> v : getNeighbours(data)) {
                    stack.push(v.getData());
                    if (!tree.contains(v.getData()))
                        tree.addAsChild(data, v.getData());
                }
            }
        }

        return tree;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        adjacencyVertices.forEach((vertex, verticesList) -> {
            sb.append(vertex.toString()).append(": ");
            for (Vertex<T> v : verticesList)
                sb.append(v.toString()).append(" ");
            sb.append('\n');
        });
        return sb.toString();
    }
}
