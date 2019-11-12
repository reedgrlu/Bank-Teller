#include <cstdio>
#include "Event.h"


//Desc: default constructor
Event::Event(){
    type = arrival;
    time = 0;
    length = 0;
}

//Desc: constructor
Event::Event(EventType et, int t, int len){
    type = et;
    time = t;
    length = len;
}

//Desc: return event type
EventType Event::getType(){
    return type;
}

//Desc: set event type  
void Event::setType(EventType et){
    type = et;
}

//Desc: return event time
int Event::getTime() const{
    return time;
}

//Desc: set event time
void Event::setTime(int t){
    time = t;
}

//Desc: return event length
int Event::getLength() const{
    return length;
}

//Desc: set event length
void Event::setLength(int len){
    length = len;
}


bool Event::operator<(const Event &r) const {
    if(this->time < r.getTime()){
        return true;
    }else{
        return false;
    };
}
        
bool Event::operator>(const Event &r) const { 
    if(this->time > r.getTime()){
        return true;
    }else{
        return false;
    };

}
        
bool Event::operator<=(const Event &r) const {
    if(this->time <= r.getTime()){
        return true;
    }else{
        return false;
    }; 
}
        
bool Event::operator>=(const Event &r) const { 
    if(this->time >= r.getTime()){
        return true;
    }else{
        return false;
    };
}