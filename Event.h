/*
 * Event.h
 *
 * Class Definition: a class object that holds one of two types of events,
 *                   and the time and duration of each event
 *
 * Created on: March 2, 2019
 * Author: Reed Lu
 */
#pragma once 


typedef enum etype { arrival, departure } EventType;


// Desc:  Represents a simulation event
class Event {
    private:
        EventType type;
        int time;
        int length;


    public:
        //Desc: default constructor
        Event();

        //Desc: constructor
        Event(EventType et, int t, int len);

        //Desc: return event type
        EventType getType();

        //Desc: set event type
        void setType(EventType et);

        //Desc: return event time
        int getTime() const;

        //Desc: set event time
        void setTime(int t);

        //Desc: return event length
        int getLength() const;

        //Desc: set event length
        void setLength(int len);





        // Desc:  Comparators
        bool operator<(const Event &r) const;
        bool operator>(const Event &r) const;
        bool operator<=(const Event &r) const;
        bool operator>=(const Event &r) const;

}; // Event

