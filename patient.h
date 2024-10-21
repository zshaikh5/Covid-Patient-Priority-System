//Zaina Shaikh 
//File name: patient.h 
//This class represents a Patient with attributes such as name, age, and precondition illness.
//It provides constructors to initialize these attributes and getters to access them.

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <queue>
using namespace std; 

class Patient
{
    public:
        //constructors 
        Patient(string patient_name, int patient_age, bool condition); 

        //getters
        string get_name() const; 
        int get_age() const; 
        bool get_precondition_illness() const; 

    private:
        //private data members 
        string name_; 
        int age_; 
        bool precondition_illness_;
};
#endif