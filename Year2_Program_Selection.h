#include <iostream>
#include <list>
#include <iterator> 
#include "File_Fetcher.h"
#pragma once
using namespace std;

class File_Fetcher;
class Year2_Program_Selection {
	private:
	public:
		string prev_pref;
		string s_new_pref;
		int new_pref;
		int num_available_seats;
		int student_transgression_record;
		list<string> student_courses;
		list<int>    student_grades;
		Year2_Program_Selection();
		~Year2_Program_Selection();

		void search_year2_preference(int student_id, File_Fetcher* pfile);
		void search_year2_data(File_Fetcher* pfile);
		void search_student_data(int student_id, File_Fetcher* pfile);
		void search_student_course(int student_id, File_Fetcher* pfile);
		void display_previous_preference(File_Fetcher* pfiles);
		void display_student_data(File_Fetcher* pfiles);
		bool check_year2_standing();
		bool check_preference_acceptance();
		void accept_year2_preference();
		void update_student_course();
		void update_year2_data(File_Fetcher* pfiles);
		void update_year2_preference(int student_id, File_Fetcher* pfile);

};