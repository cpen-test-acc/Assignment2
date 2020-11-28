#include "File_Fetcher.h"
#include "Interface.h"

File_Fetcher::File_Fetcher() {
	usernames   = { "santa", "jacky",  "G", "Samiha","allison"};
	passwords   = { "ono"  , "jiang" , "Sohnvi","Hassan","yao"};
	preferences = { "na", "engineering physics", "electrical engineering", "computer engineering", "not picked" };
	available_choices = { "engineering physics", "electrical engineering", "computer engineering", "chemical engineering", "biomedical engineering" };
	available_seats = { 3, 12, 45, 32, 11};
	student_data = { {0,1}, {1,0}, {1,0}, {0,1}, {1,0} }; // an example of student data that can be used to make decisions, in this case: 1 = transgression on record, 0 = no transgressions
}
File_Fetcher::~File_Fetcher() {
	delete the_interface;
	delete the_year2_program_selection;
}
