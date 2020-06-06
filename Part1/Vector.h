#ifndef _VECTOR_H_
#define _VECTOR_H_

#define DEFAULT_SIZE 10

#include <iostream>

template <class T>
class Vector{
    T* elements;
    int size;

    public:
    Vector():elements(new T[DEFAULT_SIZE]),size(DEFAULT_SIZE){};//default constructor
    explicit Vector(int size):elements(new T[size]),size(size){};
    Vector(int size,T element):elements(new T[size]),size(size){
       for (int i=0;i<size;i++){
           elements[i]=element;
       } 
    };
    Vector<T>(const Vector<T>& v):size(v.size){//copy constructor
        elements=new T[v.size];
        for (int i=0; i<v.size;i++){
            elements[i]=v.elements[i];
        }
    }
    ~Vector(){
        delete[] elements;
    }

    int getSize() const{
        return size;
    }

    static Vector<T> Identity(int size,int index_of_one){
        Vector new_vector(size,0);
        if (index_of_one<size){
            new_vector.elements[index_of_one]=1;
        }
        return new_vector;
    }

    void print() const{
        std::cout<<elements[0];
        for (int i=1;i<size;i++){
            std::cout<<", "<<elements[i];
        }
        std::cout<<"\n";

    }
    Vector<T>& operator=(const Vector<T> vector_a){//assignment operator
        if (this==&vector_a){
            return *this;
        }
        delete[] elements;
        size=vector_a.size;
        elements= new T[vector_a.size];
        for (int i=0;i<size;i++){
            elements[i]=vector_a.elements[i];
        }
        return *this;
    }
    T operator[](int index)const{
        return elements[index];        
    }

    bool findMember(T element) const{ //returns true iff given element exists in vector
        for(int i = 0; i<size; i++){
            if(elements[i] == element){
                return true;
            }
        }
        return false;
    }

    bool findOtherThan(T element) const{ //returns true iff vector contains an element other than the given one
        for(int i = 0; i<size; i++){
            if(elements[i] != element){
                return true;
            }
        }
        return false;
    }

    static Vector<T>* transpose(const Vector<T>* original, int original_row_num){
        int new_row_num = original[0].getSize();
        Vector<T>* transposed = new Vector<T>[new_row_num];
        for(int i = 0; i<new_row_num; i++){
            Vector<T> current_row = Vector<T>(original_row_num);
            for(int j = 0; j<original_row_num; j++){
                current_row.elements[j] = original[j].elements[i];
            }
            transposed[i] = current_row;
        }
        return transposed;
    
    }

    T& getReference(int index){ // returns reference to element at given index
        return elements[index];
    }

    T get(int index){ // returns element at given index
        return elements[index];
    }

};


#endif 