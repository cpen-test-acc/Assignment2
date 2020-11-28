#include "File_Fetcher.h"
#include "rt.h"
#include <iostream>
#include "Year2_Program_Selection.h"

using namespace std;

class File_Fetcher;
Year2_Program_Selection::Year2_Program_Selection() {
};

Year2_Program_Selection::~Year2_Program_Selection() {
};

void Year2_Program_Selection::search_year2_preference(int student_id, File_Fetcher* pfile) {
	auto it = pfile->preferences.begin();
	advance(it, student_id);
	prev_pref = *it;
}

void Year2_Program_Selection::display_previous_preference(File_Fetcher* pfiles) {
	MOVE_CURSOR(0, 0);
	printf("                                                         ");
	MOVE_CURSOR(0, 1);
	printf("                                                         ");
	MOVE_CURSOR(0, 2);
	printf("                                                         ");
	MOVE_CURSOR(0, 3);
	printf("                                                         ");
	MOVE_CURSOR(0, 0);
	cout << "Using the change year 2 program preferences" << endl;
	cout << "Previous preference: " << prev_pref << endl;
	cout << "Select new preference from list below" << endl;
	int i = 0;
	for (auto v : pfiles->available_choices) {
		std::cout << v << "(" + to_string(i) + ")" << "\t";
		i++;
	}
	cin >> new_pref;
}
void Year2_Program_Selection::accept_year2_preference(File_Fetcher* pfiles) {

}

void Year2_Program_Selection::search_year2_data(File_Fetcher* pfiles) {
	// one example of program data that can be used for acceptance consideration
	auto it = pfiles->available_seats.begin();
	advance(it, new_pref);
	num_available_seats = *it;
}

void Year2_Program_Selection::search_student_data(int student_id, File_Fetcher* pfiles) {
	auto it = pfiles->student_data.begin();
	advance(it, student_id);
	list <int> temp_array = *it;
	auto it2 = temp_array.begin();
	student_yr2_eligibility = *it2;
	advance(it2, 1);
	student_transgression_record = *it2;
}

void Year2_Program_Selection::display_student_data() {
	MOVE_CURSOR(0, 0);
	printf("                                                                                                                                                                          ");
	MOVE_CURSOR(0, 1);
	printf("                                                                                                                                                                          ");
	MOVE_CURSOR(0, 2);
	printf("                                                                                                                                                                          ");
	MOVE_CURSOR(0, 3);
	printf("                                                                                                                                                                          ");
	MOVE_CURSOR(0, 4);
	printf("                                                                                                                                                                          ");
	MOVE_CURSOR(0, 4);
	cout << "Here student data is presented to be checked" << endl;
	cout << "In this demo, only two such student data is presented" << endl;
	cout << "Student year 2 eligibility: " << to_string(student_yr2_eligibility) << endl;
	cout << "Student transgression record: " << to_string(student_transgression_record) << endl;
}

void Year2_Program_Selection::check_year2_standing() {
	// Here, you would usually grab the course prereqs and the gpa in order to determine year 2 eligibility
	// For this demo, we assign it right away
	student_yr2_eligibility = student_yr2_eligibility;
}