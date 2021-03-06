#pragma once
#include <iostream>
#include <list>
#include <iterator> 
#include "File_Fetcher.h"
#include "Year2_Program_Selection.h"
using namespace std;

class File_Fetcher;
class Interface{
	private:
		list <string> menu_items;
		string username, password;
		int person_id;
		bool is_president;
		
	public:
		File_Fetcher* the_file_fetcher;
		Year2_Program_Selection* yr2_pgm_sel;
		Interface();
		~Interface();
		bool verify_login(string username, string password);
		void Add_File_Fetcher(File_Fetcher* pfile_fetcher);
		void Del_File_Fetcher();
		void accept_username_password();
		void display_login_result(bool rslt);
		void display_menu_items(bool is_president);
};
	
