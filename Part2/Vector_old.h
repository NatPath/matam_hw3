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
//Assumes there is an assignment (=) for the type T
    Vector<T>(const Vector<T>& v):size(v.size){
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

//Assumes there is an assignment (=) for the type T
     static Vector<T> Diagonal(int size,int index_of_value, T value){
        Vector<T> new_vector(size,0);
        if (index_of_value<size){
            new_vector[index_of_value]=value;
        }
        return new_vector;
    }

//print function for Vector
    void print() const{
        std::cout<<elements[0];
        for (int i=1;i<size;i++){
            std::cout<<", "<<elements[i];
        }
        std::cout<<"\n";

    }
//assignment operator
//Assumes there is an assignment (=) for the type T
    Vector<T>& operator=(const Vector<T> vector_a){
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
    //returns a reference to the element at a given index 
    T& operator[](int index)const{
        return elements[index];        
    }


/**
 * transpose - gets a pointer to vectors as rows and returns pointer to vectors as columns 
**/
//Assumes there is an assignment (=) for the type T
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
/*  ??same functionality as operator[]??
    T& getReference(int index){ // returns reference to element at given index
        return elements[index];
    }

    T get(int index){ // returns element at given index
        return elements[index];
    }
*/
/**
 * ARITHMETIC OPERATORS
 * */
//Assumes there is "+="" operator for the type T
    Vector<T>& operator+=(const Vector<T> to_add){
        for (int i=0;i<to_add.size;i++){
            elements[i]+=to_add[i];
        }
        return *this;
    }

//Assumes there is "-="" operator for the type T
    Vector<T>& operator-=(const Vector<T> to_subtract){
        for (int i=0;i<to_subtract.size;i++){
            elements[i]-=to_subtract[i];
        }
        return *this;
    }
//Assumes there is "-"" operator for the type T
    Vector<T> operator-()const{
        Vector<T> new_vector(size);
        for (int i=0; i<size;i++){
            new_vector.elements[i]=-elements[i];
        }
        return new_vector;
    }

/** 
 * BOOLEAN OPERATORS
 * Gets an element of type T (compare) to compare with all the elements of the vector
    Returns a Vector of booleans indicating which elements (i) of the Vector are  i(OPERATOR)compare 
    Assumptions on type T: 
        Must have assignment operator
        Must have == operator which returns a booleans
 **/
    Vector<bool> operator==(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            new_vector[i] = (elements[i] == compare);
        }
        return new_vector;
    }

     Vector<bool> operator!=(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            new_vector[i] = (elements[i] != compare);
        }
        return new_vector;
    }

    Vector<bool> operator<(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            //new_vector.getReference(i) = (elements[i] < compare);
            new_vector[i] = (elements[i] < compare);
        }
        return new_vector;
    }

     Vector<bool> operator>(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            //new_vector.getReference(i) = (elements[i] > compare);
            new_vector[i] = (elements[i] > compare);
        }
        return new_vector;
    }

    Vector<bool> operator<=(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            //new_vector.getReference(i) = (elements[i] <= compare);
            new_vector[i] = (elements[i] <= compare);
        }
        return new_vector;
    }

     Vector<bool> operator>=(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            //new_vector.getReference(i) = (elements[i] >= compare);
            new_vector[i] = (elements[i] >= compare);
        }
        return new_vector;
    }

    

};

#endif 