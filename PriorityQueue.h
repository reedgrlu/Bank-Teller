/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */



/* None of the provided code (basecode) may be modified. */



#pragma once

#include "Node.h"
// #include "EmptyDataCollectionException.h"

#include <cstdio>
#include <iostream>

using namespace std;


template <class T>
class PriorityQueue {

    private:
        // singly-linked list
        Node<T> * head;
        int len;
        Node<T> * newNode;

        /* You may add private methods to this class */


    public:
        // Desc: Default Constructor. (O(1))
        PriorityQueue();
 

        // Desc: Copy Constructor. (O(N))
        PriorityQueue(const PriorityQueue& rhs);


        // Desc: Destructor. (O(N))
        ~PriorityQueue();


        // Desc: Returns true if Priority Queue empty. (O(1))
        bool isEmpty() const;


        // Desc: Returns length of the Priority Queue. (O(1))
        int getLength() const;


        // Desc: Inserts x in sorted order. (O(N))
        //  Pre: Priority Queue is sorted.
        // Post: Priority Queue remains sorted.
        void enqueue(const T& x);
    

        // Desc: Removes the element with "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        void dequeue() throw(EmptyDataCollectionException);


        // Desc: Returns the element with the "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        // Post: Priority Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);

}; // PriorityQueue


// Desc: Default Constructor. (O(1))
        template <class T>
        PriorityQueue<T>::PriorityQueue(){
            head = NULL;
            newNode = NULL;
            len = 0;
        }
 

        // Desc: Copy Constructor. (O(N))
        template <class T>
        PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhs){
            len = rhs.len;
            
            // empty PQ
            if(len == 0){
                head = NULL;
                newNode = NULL;
            };
            
            //copy non-empty PQ
            Node<T> * curr = rhs.head;
            for(int i = 0; i < len; i++){
                newNode = new Node<T>;
                newNode->data = curr->data;
                curr = curr->next;

                //assign the first node as head
                if(i == 0){
                    head = newNode;
                };
            };



        }


        // Desc: Destructor. (O(N))
        template <class T>
        PriorityQueue<T>::~PriorityQueue(){
            for(int i = 0; i < len; i++){
                delete newNode;
            };

        }


        // Desc: Returns true if Priority Queue empty. (O(1))
        template <class T>
        bool PriorityQueue<T>::isEmpty() const{
            if(len == 0){
                return true;
            }else{
                return false;
            };
        }


        // Desc: Returns length of the Priority Queue. (O(1))
        template <class T>
        int PriorityQueue<T>::getLength() const{
            return len;
        }


        // Desc: Inserts x in sorted order. (O(N))
        //  Pre: Priority Queue is sorted.
        // Post: Priority Queue remains sorted.
        template <class T>
        void PriorityQueue<T>::enqueue(const T& x){
            newNode = new Node<T>;
            newNode->data = x;
            newNode->next = NULL;

            Node<T> * curr;
            curr = head;


            // empty list
            if (head == NULL) {
		        head = newNode;
                len++;
		        return;
	        };

            //insert in front of list
            if(head->data > newNode->data){
                newNode->next = head;
                head = newNode;
                len++;
                return;    
            };
            

            //cycle through linked-list to find where to insert x;
            while(curr->next != NULL){
                if(curr->next->data < newNode->data){
                    curr = curr->next;
                }else if(curr->next->data >= newNode->data){
                    
                    if(curr->next->data > newNode->data){
                        newNode->next = curr->next;
                        curr->next = newNode;
                        len++;
                        return;
                    }else{
                        // if two objects with same data, put the new object behind the existing one
                        newNode->next = curr->next->next;
                        curr->next->next = newNode;
                        len++;
                        return;
                    };
                };
            };
            
            //insert at end of list
            if(curr->next == NULL){
                curr->next = newNode;
                len++;
                return;
            };
            
        }
    

        // Desc: Removes the element with "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        template <class T>
        void PriorityQueue<T>::dequeue() throw(EmptyDataCollectionException){
            //throw exception if empty priority queue
            try{
                if(isEmpty()){
                    throw EmptyDataCollectionException("Empty Priority Queue");
                };

            }catch(EmptyDataCollectionException& e){
                cerr << e.what() << endl;
                return;
            };
            
            Node<T> * oldHead = head;
            head = head->next;
            oldHead->next = NULL;
            delete oldHead;
            len--;
        }


        // Desc: Returns the element with the "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        // Post: Priority Queue is unchanged.
        template <class T>
        T& PriorityQueue<T>::peek() const throw(EmptyDataCollectionException){
            //throw exception if empty priority queue
            try{
                if(isEmpty()){
                    throw EmptyDataCollectionException("Empty Priority Queue");
                };

            }catch(EmptyDataCollectionException& e){
                cerr << e.what() << endl;
            };

            return head->data;
            // return head->data;
        }