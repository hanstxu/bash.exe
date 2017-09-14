#include <stdio.h>   // for printf
#include <windows.h> // FindFirstFile, FindNextFile, FindClose, etc.
#include <tchar.h>   // for TCHAR
#include <string>    // for basic_string

typedef std::basic_string<TCHAR> tstring;
#define MAX_ROW_SIZE 80
#define EXTRA_SPACE 3

int main() {
	WIN32_FIND_DATA find_file_data;
	HANDLE find_handle;
	tstring file_name;
	unsigned int max_name_size = 10;

	find_handle = FindFirstFile(L"*", &find_file_data);
	file_name = tstring(find_file_data.cFileName);
	if (file_name.size() > max_name_size)
		max_name_size = file_name.size();

	while (FindNextFile(find_handle, &find_file_data) != 0) {
		file_name = tstring(find_file_data.cFileName);
		if (file_name.size() > max_name_size)
			max_name_size = file_name.size();
	}

	FindClose(find_handle);

	unsigned int curr_size = 0;
	find_handle = FindFirstFile(L"*", &find_file_data);
	file_name = tstring(find_file_data.cFileName);
	printf("%-*ls", max_name_size + EXTRA_SPACE, file_name.c_str());
	curr_size += max_name_size + EXTRA_SPACE;

	while (FindNextFile(find_handle, &find_file_data) != 0) {
		if (curr_size + max_name_size + EXTRA_SPACE > MAX_ROW_SIZE) {
			curr_size = 0;
			printf("\n");
		}
		file_name = tstring(find_file_data.cFileName);
		printf("%-*ls", max_name_size + EXTRA_SPACE, file_name.c_str());
		curr_size += max_name_size + EXTRA_SPACE;
	}

	FindClose(find_handle);
	return 0;
}