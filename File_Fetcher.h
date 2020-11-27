#pragma once
#include <iostream>
#include <list>
#include <iterator> 
#include "Interface.h"
using namespace std;

class Interface;
class File_Fetcher {
private:
    // Some Private Variables and Functions
    
public:
    // some Public variables and Functions
    list<string> usernames;
    list<string> passwords;
    File_Fetcher();
    ~File_Fetcher();
	Interface* the_interface;
};
