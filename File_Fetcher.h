#pragma once
#include <iostream>
#include <list>
#include <iterator> 
#include "Interface.h"
#include "Year2_Program_Selection.h"
using namespace std;

class Interface;
class File_Fetcher {
private:
    // Some Private Variables and Functions
    
public:
    // some Public variables and Functions
    list<string> usernames;
    list<string> passwords;
    list<string> preferences;
    list<string> available_choices;
    list<int>    available_seats;
    list<list<int>>    student_data;
    list<list<string>> student_course;
    list<list<int>>    student_gpa;
    File_Fetcher();
    ~File_Fetcher();
	Interface* the_interface;
    Year2_Program_Selection* the_year2_program_selection;
};
