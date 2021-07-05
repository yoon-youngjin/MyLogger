#pragma once
#include <ctime>

class FileManager {
public:
	static const char* filepath;
	static FILE* file;

public:

	
	static void EnableFileOutput()
	{
		filepath = "log.txt";
		enable_file_output();
	}
	static void EnableFileOutput(const char* new_filepath)
	{
		filepath = new_filepath;
		enable_file_output();
	}
	static void CloseFileOutput()
	{
		free_file();
	}
	static void RemoveFile(const char* filepath) {


		const char* path = filepath;
		
		int nResult = remove(path);
		if (nResult == 0) {
			printf("파일 삭제 성공");
		}
			else {
			perror("파일 삭제 실패");
		}
	}
private :
	static void enable_file_output()
	{
		if (file != 0)
		{
			fclose(file);
		}

		file = fopen(filepath, "a");


		if (file == 0)
		{
			printf("Logger: Failed to open file at %s", filepath);
		}
	}

	static void free_file()
	{

		fclose(file);
		file = 0;


	}
};

const char* FileManager::filepath = 0;
FILE* FileManager::file = 0;
