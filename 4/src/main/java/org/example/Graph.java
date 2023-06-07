package org.example;

import java.util.*;

public abstract class Graph<T> implements Treeable<T> {
    public abstract boolean isEmpty();
    public abstract int verticesCount();
    public abstract boolean containsVertex(T data);
    public abstract List<Vertex<T>> getNeighbours(T data);
    public abstract void addVertex(T data);
    public abstract void removeVertex(T data);
    public abstract void clear();
    public abstract void addEdge(T data1, T data2);
    public abstract void removeEdge(T data1, T data2);

    protected class Vertex<t> {
        private final t data;

        public Vertex(t data) {
            this.data = data;
        }

        public t getData() {
            return data;
        }

        @SuppressWarnings("unchecked")
        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null || getClass() != obj.getClass()) {
                return false;
            }

            Vertex<?> other = (Vertex<?>) obj;
            return data.equals(other.data);
        }

        @Override
        public int hashCode() {
            return data.hashCode();
        }

        @Override
        public String toString() {
            return data.toString();
        }
    }
}
