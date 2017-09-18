#include <stdio.h>
#include <Windows.h>

void touchFile(char* file_name) {
	HANDLE h_file;
	h_file = CreateFile(file_name,				// name of the file
						GENERIC_WRITE,			// open for writing
						0,						// do not share with other users
						NULL,					// default security
						OPEN_ALWAYS,			// open existing file or create a new file if it does not exist
						FILE_ATTRIBUTE_NORMAL,	// normal file
						NULL);					// no attributes for template file


	// Get current time
	FILETIME ft;
	SYSTEMTIME st;
	GetSystemTime(&st);
	SystemTimeToFileTime(&st, &ft);

	// Change the modified time of the file
	SetFileTime(h_file, NULL, NULL, &ft);

	CloseHandle(h_file);
}

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++)
		touchFile(argv[i]);
	return 0;
}