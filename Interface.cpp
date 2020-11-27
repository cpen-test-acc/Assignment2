#include "Interface.h"
#include "File_Fetcher.h"
#include "rt.h"
#include <iostream>
using namespace std;

class File_Fetcher;
Interface::Interface() {
	is_president = false;
};
Interface::~Interface() {
	delete the_file_fetcher;
};
void Interface::accept_username_password() {
	MOVE_CURSOR(0, 0);
	cout << "enter username ";
	cin >> username;
	MOVE_CURSOR(0, 1);
	cout << "enter password ";
	cin >> password;
	while (!verify_login(username, password)) {
		display_login_result(false);
		MOVE_CURSOR(0, 0);
		cout << "enter username ";
		cin >> username;
		MOVE_CURSOR(0, 1);
		cout << "enter password ";
		cin >> password;
	}
	display_login_result(true);
	display_menu_items(is_president);
}
bool Interface::verify_login(string username, string password) {
	list<string>::iterator it;

	// search for username
	it = find(the_file_fetcher->usernames.begin(), the_file_fetcher->usernames.end(), username);
	if (it != the_file_fetcher->usernames.end()) {
		// search for password
		it = find(the_file_fetcher->passwords.begin(), the_file_fetcher->passwords.end(), password);
		if (it != the_file_fetcher->passwords.end()){
			if (username == "santa") {
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
	if (is_president == false) {
		MOVE_CURSOR(0, 0);
		printf("                                            ");
		MOVE_CURSOR(0, 1);
		printf("                                            ");
		MOVE_CURSOR(0, 2);
		printf("                                            ");
		MOVE_CURSOR(0, 3);
		printf("                                            ");
		MOVE_CURSOR(0, 0);
		printf("Choose 1 to change year 2 program preference");
		cin >> selection;
	} 
	else{
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