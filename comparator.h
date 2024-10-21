//Zaina Shaikh 
//File name: comparator.h 
//This class defines a comparator used to determine the priority order of patients in the CovidQueue.

#ifndef COMPARATOR_H_
#define COMPARATOR_H_
#include "covid_queue.h"
#include "patient.h"

class PatientComparator
{
    public:
        //Overloaded function call operator to compare two patients.
        bool operator()(const Patient& p1, const Patient& p2)
        {
            //Comparing patients based on precondition illness and age.
            if (!p1.get_precondition_illness() && p2.get_precondition_illness()) 
            {
                return true;
            } 
            else if (p1.get_precondition_illness() && !p2.get_precondition_illness()) 
            {
                return false; 
            }

            if (p1.get_age() < p2.get_age())
            {
                return true; 
            }
            else
            {
                return false; 
            }  
        }
};
#endif 