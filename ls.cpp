#include <stdio.h>   // for printf
#include <Windows.h> // FindFirstFile, FindNextFile, FindClose, etc.
#include <tchar.h>   // for TCHAR
#include <string>    // for basic_string

typedef std::basic_string<TCHAR> tstring;
#define MAX_ROW_SIZE 80
#define EXTRA_SPACE 3

// colors
#define LIGHT_GRAY 7
#define BLUE 9
#define GREEN 10

bool isDirectory(LPCTSTR file_path) {
	DWORD dwAttrib = GetFileAttributes(file_path);
	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		   (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

void printFileName(LPCTSTR file, unsigned int max_name_size, int color, HANDLE h_output) {
	tstring file_name = tstring(file);
	SetConsoleTextAttribute(h_output, color);
	printf("%-*hs", max_name_size + EXTRA_SPACE, file_name.c_str());
	SetConsoleTextAttribute(h_output, LIGHT_GRAY);
}

int main() {
	WIN32_FIND_DATA find_file_data;
	HANDLE h_find;
	tstring file_name;
	unsigned int max_name_size = 10;

	// Find the length of the longest file name
	h_find = FindFirstFile("*", &find_file_data);
	file_name = tstring(find_file_data.cFileName);
	if (file_name.size() > max_name_size)
		max_name_size = file_name.size();

	while (FindNextFile(h_find, &find_file_data) != 0) {
		file_name = tstring(find_file_data.cFileName);
		if (file_name.size() > max_name_size)
			max_name_size = file_name.size();
	}

	FindClose(h_find);

	// Print out all the files in the directory
	unsigned int curr_size = 0;
	HANDLE h_output = GetStdHandle(STD_OUTPUT_HANDLE);

	h_find = FindFirstFile("*", &find_file_data);
	if (isDirectory(find_file_data.cFileName))
		printFileName(find_file_data.cFileName, max_name_size, BLUE, h_output);
	else
		printFileName(find_file_data.cFileName, max_name_size, GREEN, h_output);
	
	curr_size += max_name_size + EXTRA_SPACE;

	while (FindNextFile(h_find, &find_file_data) != 0) {
		if (curr_size + max_name_size + EXTRA_SPACE > MAX_ROW_SIZE) {
			curr_size = 0;
			printf("\n");
		}
		
		if (isDirectory(find_file_data.cFileName))
			printFileName(find_file_data.cFileName, max_name_size, BLUE, h_output);
		else
			printFileName(find_file_data.cFileName, max_name_size, GREEN, h_output);

		curr_size += max_name_size + EXTRA_SPACE;
	}

	FindClose(h_find);
	CloseHandle(h_output);
	CloseHandle(h_find);
	return 0;
}