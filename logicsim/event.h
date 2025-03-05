#ifndef EVENT_H
#define EVENT_H
#include "wire.h"
#include "../heap.h"
struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    // Comparison function for creating a min-heap based on event time
    bool operator()(Event* a, Event* b) const {
        return a->time > b->time;  // Larger time means lower priority in min-heap
    }
} EventLess;
#endif
