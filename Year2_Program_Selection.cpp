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
	auto it = pfiles->available_choices.begin();
	advance(it, new_pref);
	s_new_pref = *it;
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
	student_transgression_record = *it;
}

void Year2_Program_Selection::search_student_course(int student_id, File_Fetcher* pfiles) {
	auto it = pfiles->student_course.begin();
	advance(it, student_id);
	student_courses = *it;
	auto it2 = pfiles->student_gpa.begin();
	advance(it2, student_id);
	student_grades = *it2;
}

void Year2_Program_Selection::display_student_data(File_Fetcher* pfiles) {
	int garbage;
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
	MOVE_CURSOR(0, 0);
	auto it = pfiles->available_choices.begin();
	advance(it, new_pref);
	cout << "You are applying for: " << *it << endl;
	cout << "Here student data is presented to be checked" << endl << endl;
	cout << "Student transgression record: " << to_string(student_transgression_record) << endl << endl;
	cout << "Courses: ";

	auto it_courses = student_courses.begin();
	auto it_grades = student_grades.begin();
	for (int i = 0; i < student_courses.size(); i++) {
		advance(it_courses, i);
		advance(it_grades, i);
		cout << *it_courses << " " << to_string(*it_grades) << "%" << "\t";
	}
	cout << endl;
	cout << "Please verify student info as correct (y/n)" << endl;

	// Fixing the student data is not implemented
	cin  >> garbage;
}

bool Year2_Program_Selection::check_year2_standing() {
	int sum = 0;
	// Here check that the average gpa is passing and there are no transgression on record
	for (auto it = student_grades.begin(); it != student_grades.end(); ++it) {
		sum += *it;
	}
	cout << "Checking that student has year 2 standing" << endl;
	if (((sum / student_grades.size()) < 50) | (student_transgression_record)) {
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
		MOVE_CURSOR(0, 0);
		printf("Cannot apply to year 2 program as you do not have year 2 standing");
		while (1);
		return false;
	}
	return true;
}
bool Year2_Program_Selection::check_preference_acceptance() {
//	"engineering physics"
	if (new_pref == 0) {
		// here goes the requirements for this program
		auto it = find(student_courses.begin(), student_courses.end(), "PHYS102"); // PHYS102 is a pre-req, must be > 65%
		if (it != student_courses.end()) {
			int course_id = distance(student_courses.begin(), it);
			auto it2 = student_grades.begin();
			advance(it2, course_id);
			if (*it2 > 65) {
				return true;
			}
		}
	}
// "electrical engineering"
	else if (new_pref == 1) {
		// here goes the requirements for this program ( not implemented )
	}
//	"computer engineering"
	else if (new_pref == 2) {
		// here goes the requirements for this program ( not implemented )
	}
//  "chemical engineering"
	else if (new_pref == 3) {
		// here goes the requirements for this program ( not implemented )
	}
//  "biomedical engineering"
	else if (new_pref == 4) {
		// here goes the requirements for this program ( not implemented )
	}
	return false;
}
void Year2_Program_Selection::accept_year2_preference() {
	int garbage;
	cout << endl << endl << endl;
	cout << "You are accepted to " << s_new_pref << " because you have 2nd year standing and met all requirements for the program" << endl;
}

void Year2_Program_Selection::update_student_course() {
	cout << "update student courses with year 2 program courses" << endl;
	auto it = student_courses.begin();
	student_courses.insert(it,"MATH246");


}
void Year2_Program_Selection::update_year2_data(File_Fetcher* pfiles) {
	cout << "updated the 2nd year program data such as available seats" << endl;
	auto it = pfiles->available_seats.begin();
	advance(it, new_pref);
	*it += 1;
}

void Year2_Program_Selection::update_year2_preference(int student_id, File_Fetcher* pfiles) {
	cout << "Put change in preference on record" << endl;
	auto it = pfiles->preferences.begin();
	advance(it, student_id);
	*it = s_new_pref;
}