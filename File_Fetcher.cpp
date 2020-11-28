#include "File_Fetcher.h"
#include "Interface.h"

File_Fetcher::File_Fetcher() {
	usernames = { "santa", "jackyruth", "G", "Samiha","allison"};
	passwords = { "ono", "northwestpassage", "Sohnvi","Hassan","yao"};
}
File_Fetcher::~File_Fetcher() {
	delete the_interface;
}
