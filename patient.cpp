//Zaina Shaikh 
//File name: patient.cpp
//This is the implementation for the patient class  

#include "patient.h"
#include <iostream>
#include <queue>
 
Patient::Patient(string patient_name, int patient_age, bool condition)
{
    name_ = std::move(patient_name);
    age_ = patient_age; 
    precondition_illness_ = condition; 
}

string Patient::get_name() const
{
    return name_; 
} 

int Patient::get_age() const
{
    return age_; 
} 
        
bool Patient::get_precondition_illness() const
{
    return precondition_illness_; 
} 