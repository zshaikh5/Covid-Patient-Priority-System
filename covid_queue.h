//Zaina Shaikh 
//File name: covid_queue.h 
//This class represents a priority queue for managing patients in a COVID-19 queue.

#ifndef COVID_QUEUE_H_
#define COVID_QUEUE_H_
#include "patient.h"
#include "comparator.h"
#include <iostream>
#include <queue>

class CovidQueue
{
public:
    //functions 
    bool Empty() const; 
    void Push(const Patient& new_patient); 
    void Pop(); 
    const Patient& Top(); 

private:
    priority_queue<Patient, vector<Patient>, PatientComparator> pq;  
};
#endif