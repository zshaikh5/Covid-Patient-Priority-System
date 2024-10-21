//Zaina Shaikh 
//File name: covid_queue.cpp 
//This is the implementation for the CovidQueue class 

#include "covid_queue.h"
#include "comparator.h"
#include "patient.h"

bool CovidQueue::Empty() const
{
    return pq.empty(); 
} 

void CovidQueue::Push(const Patient& new_patient)
{
    pq.push(new_patient); 
}

void CovidQueue::Pop()
{
    pq.pop(); 
} 

const Patient& CovidQueue::Top()
{
    return pq.top(); 
}