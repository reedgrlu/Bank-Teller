
#include "Queue.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main () {
	Queue<Event> bankLine;	//bankline
	PriorityQueue<Event> eventPQ; //event priority Queue

	bool tellerAvailable = true;	//teller availability
	

	int arrive, len;	// declare input variables
	while(cin >> arrive >> len){
		Event inputEvent(arrival, arrive, len);
		eventPQ.enqueue(inputEvent);
	};

	cout << "Simulation Begins" << endl;
	int total = eventPQ.getLength();
	double waitTime = 0;
	while(!eventPQ.isEmpty()){
		Event newEvent = eventPQ.peek();
		int currTime = newEvent.getTime();
		

		if(newEvent.getType() == arrival){
			//process arrival event
			eventPQ.dequeue();
			Event customer = newEvent;
			
			if(bankLine.isEmpty() && tellerAvailable){
				int departTime = currTime + customer.getLength();
				Event newDepartEvent(departure, departTime, 0);
				eventPQ.enqueue(newDepartEvent);
				tellerAvailable = false;
				
				cout << "Processing an arrival event at time:" << setw(5) << currTime << endl;
			}else{
				cout << "Processing an arrival event at time:" << setw(5) << currTime << endl;
			
				bankLine.enqueue(customer);
			};



		}else if(newEvent.getType() == departure){
			//process departure event
			eventPQ.dequeue();

			cout << "Processing a departure event at time:" << setw(4) << currTime << endl;
			if(!bankLine.isEmpty()){
				Event nextCustomer = bankLine.peek();
				bankLine.dequeue();

				waitTime += (currTime - nextCustomer.getTime());

				int departTime = currTime + nextCustomer.getLength();
				Event newDepartEvent(departure, departTime, 0);
				eventPQ.enqueue(newDepartEvent);				
			}else{
				tellerAvailable = true;
			};
		};

	};
	cout << "Simulation Ends" << endl << endl;

	cout << "Final Statistics:  " << endl;
	cout << "    Total number of people processed:  " << total << endl;

	double avgWaitTime = waitTime / total;
	cout << "    Average amount of time spent waiting: " << avgWaitTime << endl; 
	
	return 0;
} // main



//process arrival event function

