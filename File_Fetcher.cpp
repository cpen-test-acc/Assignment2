#include "File_Fetcher.h"
#include "Interface.h"

File_Fetcher::File_Fetcher() {
	usernames = { "jackyruth", "santa"};
	passwords = { "northwestpassage", "ono"};
}
File_Fetcher::~File_Fetcher() {
	delete the_interface;
}
