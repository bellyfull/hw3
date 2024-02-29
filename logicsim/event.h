#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess { // managing the order of events using time data member
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(Event* A, Event* B) {
            return A->time < B->time; // if A is smaller, it means it happened earlier and thus should return true if event came earlier
        } //root node will be earliest event
} EventLess;
	
#endif
