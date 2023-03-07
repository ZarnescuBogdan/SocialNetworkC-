//
// Created by Bogdan Zarnescu on 11.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_ARRAY_H
#define SDA_PROFIECT_FINAL_ARRAY_H

#include <iostream>

using namespace std;

template<class T> class Array {
private:
    int defaultCapacity = 15;
    int capacity;
    int size;
    T* entities;
    void resize() {
        this->capacity += this->defaultCapacity;
        T* newEntities = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            newEntities[i] = this->entities[i];
        }
        delete[] this->entities;
        this->entities = newEntities;
    }
public:
    typedef T *iterator;
    /**
     * Array constructor.
     */
    Array() {
        this->capacity = this->defaultCapacity;
        this->size = 0;
        this->entities = new T[this->capacity];
    }

    /**
     * Array copy-constructor.
     * @param array array to be coppied
     */
    Array(const Array<T> &array) {
        this->capacity = array.capacity;
        this->size = array.size;
        T* newEntities = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            newEntities[i] = array[i];
        }
        this->entities = newEntities;
    }

    /**
     * Array destructor.
     */
    ~Array() {
        this->capacity = this->defaultCapacity;
        this->size = 0;
        if(!this->empty()) {
            delete[] entities;
        }
        this->entities = new T[this->size];
    }

    /**
     * Gets the array size.
     * @return array size
     */
    int arraySize() {
        return this->size;
    }

    /**
     * Gets the array capacity.
     * @return array capacity
     */
    int arrayCapacity() {
        return this->capacity;
    }

    /**
     * Checks if the array is empty.
     * @return true or false
     */
    bool empty() {
        if(this->size == 0) {
            return true;
        } else
            return false;
    }

    /**
     * Adds an element at the end of the array.
     * @param entity type T
     */
    void pushBack(T entity) {
        if(this->size == this->capacity) {
            resize();
        }
        this->entities[this->size++] = entity;
    }

    /**
     * Adds an element at the specified index of the array.
     * @param index type integer
     * @param entity type T
     */
    void insert(int index, T entity) {
        if(index > this->size || index < 0) {
            cout << "Invalid index!";
        }
        if(this->size == this->capacity) {
            resize();
        }
        T* newEntities = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            newEntities[i] = this->entities[i];
        }
        delete[] this->entities;
        for(int i = this->size; i > index; i--) {
            newEntities[i] = newEntities[i - 1];
        }
        this->size++;
        newEntities[index] = entity;
        this->entities = newEntities;
    }

    /**
     * Returns and deletes the last element in the array.
     * @return last element in the array
     */
    T popBack() {
        if(empty()) {
            cout << "The array is empty!";
        }
        T entity;
        this->size--;
        entity = this->entities[this->size];
        T* newEntities = new T[this->size];
        for(int i = 0; i < this->size; i++) {
            newEntities[i] = entities[i];
        }
        delete[] this->entities;
        this->entities = newEntities;
        return entity;
    }

    /**
     * Deletes the element form specified index in the array.
     * @param index type integer
     */
    void eraseIndex(int index) {
        if(empty()) {
            cout << "The array is empty!";
        }
        if(index < 0 || index >= this->size) {
            cout << "Invalid index!";
        }
        T* newEntities = new T[size];
        for(int i = 0; i < this->size; i++) {
            newEntities[i] = this->entities[i];
        }
        delete[] this->entities;
        for(int i = index; i < this->size - 1; i++) {
            newEntities[i] = newEntities[i + 1];
        }
        this->size--;
        this->entities = newEntities;
    }

    /**
     * Deletes an array.
     */
    void eraseAll() {
        delete[] this->entities;
        this->capacity = this->defaultCapacity;
        this->size = 0;
        this->entities = new T[this->size];
    }

    /**
     * Show all elements in the array.
     */
    void showAll() {
        for(int i = 0; i < this->size; i++) {
            cout << this->entities[i] << " ";
        }
    }

    /**
     * Override operator[].
     * @param index type integer
     * @return value from array
     */
    T& operator[](int index) const {
        return this->entities[index];
    }

    /**
     * Override operator=.
     * @param array type Array<T>
     * @return
     */
    Array<T> &operator=(const Array<T> &array) {
        this->capacity = array.capacity;
        this->size = array.size;
        delete[] this->entities;
        this->entities = new T[this->capacity];
        for(int i = 0; i < this->size; i++) {
            this->entities[i] = array.entities[i];
        }
        return *this;
    }
};

#endif //SDA_PROFIECT_FINAL_ARRAY_H
