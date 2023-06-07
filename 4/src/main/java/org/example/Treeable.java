package org.example;

public interface Treeable<T> {
    Tree<T> toTree(T rootData);
}
