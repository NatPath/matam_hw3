#ifndef _VECTOR_H_
#define _VECTOR_H_

//an arbitrary default size when a size is not given
#define DEFAULT_SIZE 10

#include <iostream>

/**
 * Vector - 
 *  A Generic class used for representing row vectors.
 * for the purpose of handeling memory and doing simple operations on its elements.
 * IS NOT A REPLACEMENT FOR std::vector 
 * */
template <class T>
class Vector{
    T* elements;
    int size;

    public:
    Vector():elements(new T[DEFAULT_SIZE]),size(DEFAULT_SIZE){};//default constructor
    explicit Vector(int size):elements(new T[size]),size(size){};
    /**
     * Constructor :
     *  makes a vector of size "size" in which all of its elements are element
     * 
     * Assumptions on T:
     * T must have assignment operator
     * */
    Vector(int size,const T& element):elements(new T[size]),size(size){
       for (int i=0;i<size;i++){
           elements[i]=element;
       } 
    };
/**
 * Copy constructor for Vector<T>:
 * Makes a vector of the same size of "to_copy" and the same elements 
 *
 * Assumptions on T:
 * T must have assignment "=" operator 
 * */
    Vector<T>(const Vector<T>& to_copy):size(to_copy.size){
        elements=new T[to_copy.size];
        for (int i=0; i<to_copy.size;i++){
            elements[i]=to_copy.elements[i];
        }
    }
    /**
     * Vector<T> desctructor:
     * frees elements memory
     * 
     * */
    ~Vector(){
        delete[] elements;
    }

    /**
     * getSize:
     * returns the size of the vector
     * */
    int getSize() const{
        return size;
    }

/**
 * Diagonal:
 *  A static Method used for making an "elementry vector".
 * Returns a Vector<T> of size "size" in which all but one of the elements are assigned to the T default.
 *  In The "index_of_value" position, The value will be "value".
 * 
 * Assumptions on T:
 * T must have assignment "=" operator 
 * T must have a default constructor
 * */
     static Vector<T> Diagonal(int size,int index_of_value,const T& value){
        Vector<T> new_vector(size,T());
        if (index_of_value<size){
            new_vector.elements[index_of_value]=value;
        }
        return new_vector;
    }


/**
 * print:
 * A method used for printing the elements of the Vector.
 * Assumptions on T:
 * T must have << operator   
 * */
    void print() const{
        std::cout<<elements[0];
        for (int i=1;i<size;i++){
            std::cout<<", "<<elements[i];
        }
        std::cout<<"\n";

    }
//assignment operator
//Assumes there is an assignment (=) for the type T
//????????? Are we supposed to protect elements in case of failure? ??????
/**
 * operator=:
 * Assignment operator for Vector<T>. 
 * Adjust the Vector size the the same as vector_a and copies all the elements of it.
 * 
 * Assumptions on T:
 * T must have assignment "=" operator 
 * */
    Vector<T>& operator=(const Vector<T>& vector_a){
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
    /**
     * operator[]:
     * returns a reference to an element in the given index 
     * */
    T& operator[](int index) const{
        return elements[index];        
    }


/**
 * transpose:
 *  Gets a pointer to vectors as rows and returns pointer to vectors as columns 
 * 
 * Assumptions on T:
 * T must have assignment "=" operator 
 * 
**/
    static Vector<T>* transpose(const Vector<T>* original, int original_row_num){
        int new_row_num = original[0].getSize();
        Vector<T>* transposed = new Vector<T>[new_row_num];
        try{
            for(int i = 0; i<new_row_num; i++){
                Vector<T> current_row = Vector<T>(original_row_num);
                for(int j = 0; j<original_row_num; j++){
                    current_row.elements[j] = original[j].elements[i];
                }
                transposed[i] = current_row;
            }
        }
        catch(...){
            delete[] transposed;
            throw;
        }
        return transposed;
    
    }
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
            new_vector[i] = (elements[i] < compare);
        }
        return new_vector;
    }

     Vector<bool> operator>(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            new_vector[i] = (elements[i] > compare);
        }
        return new_vector;
    }

    Vector<bool> operator<=(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            new_vector[i] = (elements[i] <= compare);
        }
        return new_vector;
    }

     Vector<bool> operator>=(T compare)const{
        Vector<bool> new_vector(size,false);
        for(int i = 0; i<size; i++){
            new_vector[i] = (elements[i] >= compare);
        }
        return new_vector;
    }

    

};

#endif 