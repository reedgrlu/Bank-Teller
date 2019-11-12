

// Class Invariant:  FIFO order
 

/* None of the provided code (basecode) may be modified. */


#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <cstdio>

using namespace std;

template <class T>
class Queue {
    private:

        static unsigned const INITIAL_SIZE = 6;
        T * arr;

        unsigned size;        // number of elements in the queue
        unsigned capacity;    // number of slots in the array
        unsigned frontindex;  // index the topmost element
        unsigned backindex;   // index where the next element will be placed


        
    public:

        // Desc: Constructor. (O(1))
        Queue();

        // Desc: Destructor
        ~Queue();

        // Desc: Returns true if Queue is empty. (O(1))
        bool isEmpty() const;

   
        // Desc: Inserts x at the "back" of this Queue. (O(1))
        void enqueue(const T& x);

   
        // Desc: Removes the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        void dequeue() throw(EmptyDataCollectionException);
   

        // Desc: Returns the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        // Post: Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);  



        /* you may add more methods */


};


// Desc: Constructor. (O(1))
template <class T>
Queue<T>::Queue() {
    size = 0;
    capacity = INITIAL_SIZE;
    frontindex = 0;
    backindex = 0;

    arr = new T[INITIAL_SIZE];

} // constructor

// Desc: Destructor
template <class T>
Queue<T>::~Queue(){
    delete [] arr;
};

// Desc: Returns true if Queue is empty. (O(1))
template <class T>
bool Queue<T>::isEmpty() const {
    if(size == 0){
        return true;
    }else{
        return false;
    };
} // isEmpty



// Desc: Inserts x at the "back" of this Queue. (O(1))
template <class T>
void Queue<T>::enqueue(const T& x) {
    //if reached capacity and front index overlap with backindex, create new dynamic array with double the capacity
    if(size == capacity && frontindex == backindex){
        T * newArr;
        newArr = new T[2*capacity];

        //copy all elements of arr to newArr
        for(int i = 0; i < capacity; i++){
            newArr[i] = arr[(frontindex + i) % capacity];
        };
        
        delete [] arr;   //recycle old Array
        arr = newArr;   //assign pointer arr to newArr
        frontindex = 0;     //frontindex becomes 0
        backindex = size;   //backindex becomes orginal size
        capacity = capacity*2;  //double original capacity  
    };

    size++;
    arr[backindex] = x;
    backindex = (backindex + 1) % capacity;  
} // enqueue



// Desc: Removes the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
template <class T>
void Queue<T>::dequeue() throw(EmptyDataCollectionException) {
    //if queue is empty, throw exception
    try{
        if(isEmpty()){
            throw EmptyDataCollectionException("Empty Queue");
        };

    }catch(EmptyDataCollectionException& e){
        cerr << e.what() << endl;
    };
    
    
    //if size of queue is less than a quarter for the capacity and th current capacity is not the initial capacity, create new array with half the current capacity
    if(size < (capacity/4) && capacity != INITIAL_SIZE){
        T * newArr;
        newArr = new T[capacity/2];

        //copy all current queue elements into new array
        for(int i = 0; i < size; i++){
            newArr[i] = arr[frontindex + i];
        };

        frontindex = 0;     //front index becomes 0
        backindex = size;   //back index is original value of size

        delete [] arr;      //recycle old array
        arr = newArr;       //assign arr to point to new array
        capacity = capacity/2;  //halve the original capacity
    };

    size--;
    frontindex = (frontindex + 1) % capacity;
} // dequeue



// Desc: Returns the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
// Post: Queue is unchanged.
template <class T>
T& Queue<T>::peek() const throw(EmptyDataCollectionException) {
    //throw exception if empty queue
    try{
        if(isEmpty()){
            throw EmptyDataCollectionException("Empty Queue");
        };

    }catch(EmptyDataCollectionException& e){
        cerr << e.what() << endl;
    };
    return arr[frontindex];
} // peek


