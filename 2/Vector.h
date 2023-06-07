#pragma once

#include <cstring>
#include <string>
#include <stdexcept>
#include <iostream>

template<typename T>
class Vector 
{
private:
	T* mData;
    int mSize;
	int mMaxSize;

public:
	Vector(int size = 0)
    {
        mSize = 0;

        if (size > 1)
            mMaxSize = size;
        else
            mMaxSize = 1;

        mData = (T*)calloc(mMaxSize, sizeof(T));
    }

    Vector(const Vector<T>& other)
    {
        mSize = other.mSize;
        if (other.mSize > 0)
            mMaxSize = other.mSize;
        else
            mMaxSize = 1;

        mData = (T*)malloc(sizeof(T) * mSize);
        mData = (T*)memcpy(mData, other.mData, sizeof(T) * mSize);
    }

	~Vector()
    {
        mSize = 0;
        mMaxSize = 1;
        free(mData);
    }

    Vector<T>& operator=(const Vector<T>& other)
    {
        if (this == &other) 
            return *this;

        this->mMaxSize = other.mMaxSize;
        this->mSize = other.mSize;
        this->mData = (T*)realloc(this->mData, this->mMaxSize * sizeof(T));

        memcpy(this->mData, other.mData, sizeof(T) * this->mSize);

        return *this;
    }

    Vector<T> clone() const
    {
        Vector<T> copy(*this);
        return copy;
    }

	bool isEmpty() const
    {
        return mSize == 0;
    }

	int size() const
    {
        return mSize;
    }

	T& at(int index) const
    {
        if (index < mSize)
            return mData[index];
        else
            throw std::out_of_range("Index is out of vector range");
    }

	T& operator[](int index) const
    {
        return at(index);
    }

	void removeAt(int position)
    {
        if (position >= mSize || position < 0)
            throw std::out_of_range("Index is out of vector range");

        mSize--;

        for (int i = position; i < mSize; i++)
            mData[i] = mData[i + 1];
    }

	void removeAll()
    {
        this->~Vector();
        mData = (T*)calloc(mMaxSize, sizeof(T));
    }

    void popBack()
    {
        if (mSize > 0)
            mSize--;
    }

	void pushBack(T element)
    {
        if (mSize >= mMaxSize)
        {
            mMaxSize *= 2;
            mData = (T*)realloc(mData, mMaxSize * sizeof(T));
        }
        mData[mSize] = element;
        mSize++;
    }

    void pushBack(const Vector<T>& other) 
    {
        int newSize = this->size() + other.size();

        while (newSize > this->mMaxSize)
            this->mMaxSize *= 2;

        this->mData = (T*)realloc(this->mData, this->mMaxSize * sizeof(T));

        int size = other.size();
        for (int i = 0; i < size; i++) 
            this->pushBack(other[i]);
    }

    Vector<T> operator+(const Vector<T>& other) const
    {
        int newSize = this->size() + other.size();
        Vector<T> newVector(newSize);

        for (int i = 0; i < this->size(); i++)
            newVector.pushBack(this->at(i));
        
        for (int i = 0; i < other.size(); i++)
            newVector.pushBack(other.at(i));

        return newVector;
    }

	void insertAt(T element, int position)
    {
        if (position < 0 || position >= mSize)
            throw std::out_of_range("Index is out of vector range");

        if (mSize >= mMaxSize)
        {
            mMaxSize *= 2;
            mData = (T*)realloc(mData, mMaxSize * sizeof(T));
        }
        for (int i = mSize - 1; i >= position; i--)
            mData[i + 1] = mData[i];

        mData[position] = element;
        mSize++;
    }
};