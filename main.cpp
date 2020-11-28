#include "Interface.h"
#include "File_Fetcher.h"

//From 2nd account
int main() {
	File_Fetcher fetcher;
	Interface intf;

	intf.Add_File_Fetcher(&fetcher);
	intf.accept_username_password();

	intf.Del_File_Fetcher();
	return 0;
}