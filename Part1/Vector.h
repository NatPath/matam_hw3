#ifndef _VECTOR_H_
#define _VECTOR_H_

#define DEFAULT_SIZE 10

#include <iostream>

template <class T>
class Vector{
    T* elems;
    int size;

    public:
    Vector():elems(new T[DEFAULT_SIZE]),size(DEFAULT_SIZE){};//default constructor
    explicit Vector(int size):elems(new T[size]),size(size){};
    Vector(int size,T elem):elems(new T[size]),size(size){
       for (int i=0;i<size;i++){
           elems[i]=elem;
       } 
    };
    Vector<T>(const Vector<T>& v):size(v.size){//copy constructor
        elems=new T[v.size];
        for (int i=0; i<v.size;i++){
            elems[i]=v.elems[i];
        }
    }
    ~Vector(){
        delete[] elems;
    }

    static Vector<T> Identity(int size,int index_of_one){
        Vector new_vector(size,0);
        if (index_of_one<size){
            new_vector.elems[index_of_one]=1;
        }
        return new_vector;
    }

    void print() const{
        std::cout<<elems[0];
        for (int i=1;i<size;i++){
            std::cout<<", "<<elems[i];
        }
    }
};


#endif 