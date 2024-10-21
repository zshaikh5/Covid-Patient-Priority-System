//Zaina Shaikh 
//File name: main.cpp
//The main is responsible for reading patient data from a file and outputting the list of patients prioritized for the vaccine 

#include "covid_queue.h"
#include "comparator.h"
#include <sstream>
#include <fstream>
#include <iostream>

int main()
{
    int vaccine_num;
    std::cout << "Enter the number of vaccines: ";
    cin >> vaccine_num;

    //Checks if the input is valid. 
    if (vaccine_num <= 0) 
    {
        cerr << "Invalid input. Please enter a valid positive integer." << endl;
        return -1; 
    }

    //Creates an instance of the CovidQueue. 
    CovidQueue covid_queue;
    ifstream input_file("patients.txt");
    if (!input_file.is_open()) 
    {
        std::cerr << "Error: Could not open " << "patients.txt" << std::endl;
        return -1;
    }

    std::string line;
    while (getline(input_file, line)) 
    {
        std::stringstream stream(line);
        std::string input_name;
        std::string input_age;
        std::string input_illnesses;

        //Get name, age, and illnesses from stream. 
        getline(stream, input_name, ',');  
        getline(stream, input_age, ','); 
        getline(stream, input_illnesses);  

        //Formats by removing additional spaces. 
        input_age.erase(0, input_age.find_first_not_of(' '));
        input_age.erase(input_age.find_last_not_of(' ') + 1);
        input_illnesses.erase(0, input_illnesses.find_first_not_of(' '));
        input_illnesses.erase(input_illnesses.find_last_not_of(' ') + 1);

        //Conversion from string to int. 
        int age = 0;
        try 
        {
            age = std::stoi(input_age);
        } 
        catch (const std::invalid_argument& a) 
        {
            continue;
        }
        for (char& ch : input_illnesses) 
        {
            ch = std::toupper(ch);
        } 
        bool is_illness = (input_illnesses == "YES");

        //Check patients age for vaccination 
        if (age >= 5) {
            Patient patient(input_name, age, is_illness);
            covid_queue.Push(patient);
        }
        else 
        {
            cerr << "Ages of the patients must be positive integers above the age of 5" << endl;
        }
    }
    input_file.close();

    //Outputs the names of patients 
    cout << "Patients prioritized for vaccination:" << endl;
    while (vaccine_num > 0 && !covid_queue.Empty()) 
    {
        std::cout << covid_queue.Top().get_name() << endl;
        covid_queue.Pop();
        vaccine_num--;
    }
    return 0;
}