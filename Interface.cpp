#include "Interface.h"
#include "File_Fetcher.h"
#include "rt.h"
#include <iostream>
#include "Year2_Program_Selection.h"
using namespace std;

class File_Fetcher;
class Year2_Program_Selection;
Interface::Interface() {
	is_president = false;
	yr2_pgm_sel = new Year2_Program_Selection();
};

Interface::~Interface() {
	delete the_file_fetcher;
	delete yr2_pgm_sel;
};

void Interface::accept_username_password() {
	//MOVE_CURSOR(0, 0);
	//cout << "enter username ";
	//cin >> username;
	//MOVE_CURSOR(0, 1);
	//cout << "enter password ";
	//cin >> password;
	//while (!verify_login(username, password)) {
	//	display_login_result(false);
	//	MOVE_CURSOR(0, 0);
	//	cout << "enter username ";
	//	cin >> username;
	//	MOVE_CURSOR(0, 1);
	//	cout << "enter password ";
	//	cin >> password;
	//}
	person_id = 1; // jacky used for testing
	display_login_result(true);
	display_menu_items(is_president);
}

bool Interface::verify_login(string username, string password) {
	list<string>::iterator it;

	// search for username
	it = find(the_file_fetcher->usernames.begin(), the_file_fetcher->usernames.end(), username);
	if (it != the_file_fetcher->usernames.end()) {
		person_id = distance(the_file_fetcher->usernames.begin(), it);
		// search for password
		it = find(the_file_fetcher->passwords.begin(), the_file_fetcher->passwords.end(), password);
		if (it != the_file_fetcher->passwords.end()){
			if (person_id == 0) {
				is_president = true;
			}
			return true;
		}
	}

	return false;
}

void Interface::Add_File_Fetcher(File_Fetcher* pfile_fetcher) {
	the_file_fetcher = pfile_fetcher;
	the_file_fetcher->the_interface = this;
}

void Interface::Del_File_Fetcher() {
	if (the_file_fetcher != NULL) {
		the_file_fetcher->the_interface = NULL;
		the_file_fetcher = NULL;
	}
}

void Interface::display_login_result(bool rslt) {
	if (rslt == false) {
		MOVE_CURSOR(0, 0);
		printf("                                            ");
		MOVE_CURSOR(0, 1);
		printf("                                            ");
		MOVE_CURSOR(0, 2);
		printf("                                            ");
		MOVE_CURSOR(0, 2);
		cout << "Login Failed, Try Again" << endl;
	}
	else {
		MOVE_CURSOR(0, 0);
		printf("                                            ");
		MOVE_CURSOR(0, 1);
		printf("                                            ");
		MOVE_CURSOR(0, 2);
		printf("                                            ");
		MOVE_CURSOR(0, 2);
		cout << "Login Successful!       " << endl;
	}
}

void Interface::display_menu_items(bool is_president) {
	int selection = -1;
	while (selection != 1) {
		if (is_president == false) {
			MOVE_CURSOR(0, 0);
			printf("                                               ");
			MOVE_CURSOR(0, 1);
			printf("                                               ");
			MOVE_CURSOR(0, 2);
			printf("                                               ");
			MOVE_CURSOR(0, 3);
			printf("                                               ");
			MOVE_CURSOR(0, 0);
			printf("Choose 1 to change year 2 program preference   ");
			MOVE_CURSOR(0, 1);
			printf("Choose 2 to register courses (not implemented) ");
			MOVE_CURSOR(0, 2);
			printf("Choose 3 to view timetable   (not implemented) ");
			MOVE_CURSOR(0, 3);
			printf("Choose 4 to view grades      (not implemented) ");
			cin >> selection;
			yr2_pgm_sel->search_year2_preference(person_id, the_file_fetcher);
			yr2_pgm_sel->display_previous_preference(the_file_fetcher);
			yr2_pgm_sel->search_year2_data(the_file_fetcher);
			yr2_pgm_sel->search_student_data(person_id, the_file_fetcher);
			yr2_pgm_sel->display_student_data();

		}
		else {
			MOVE_CURSOR(0, 0);
			printf("                                            ");
			MOVE_CURSOR(0, 1);
			printf("                                            ");
			MOVE_CURSOR(0, 2);
			printf("                                            ");
			MOVE_CURSOR(0, 3);
			printf("                                            ");
			MOVE_CURSOR(0, 0);
			printf("Choose 1 to suspend a student               ");
			cin >> selection;
		}
	}
}