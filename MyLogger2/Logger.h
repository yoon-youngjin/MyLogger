#pragma once

#include <stdio.h>
#include <ctime>
#include "FileManager.h"


enum LogPriority
{
	//우선순위 trace -> debug -> info -> error -> critical순
	TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
private:
	static LogPriority priority;
	
public:
	// 우선순위를 설정하여 설정한 우선순위보다 낮을경우 출력 or 파일입력 x
	static void SetPriority(LogPriority new_priority)
	{
		priority = new_priority;
	}
	//mode 1 : 출력,파일저장 , mode 2 : 출력, mode 3 : 파일 저장
	template<typename... Args>
	static void Trace(const char* message, const char* filename, const int linenum,int mode, Args... args)
	{
		switch (mode) {
		case 1: {
			log("T: ", TracePriority, message, filename, linenum, args...);
			break;
		}
		case 2: {
			log1("T: ", TracePriority, message, filename, linenum, args...);
			break;
		}
		case 3: {
			log2("T: ", TracePriority, message, filename, linenum, args...);
			break;

		}
		default: {
			log("T: ", TracePriority, message, filename, linenum, args...);
			break;
		}
		}
		
	
		
	}

	template<typename... Args>
	static void Debug(const char* message, const char* filename, const int linenum, Args... args)
	{
		log("D: ", DebugPriority, message, filename, linenum, args...);
	}

	template<typename... Args>
	static void Info(const char* message, const char* filename,const int linenum, Args... args)
	{
		log("I: ", InfoPriority, message,filename, linenum, args...);
	}

	template<typename... Args>
	static void Warn(const char* message, const char* filename, const int linenum, Args... args)
	{
		log("W: ", WarnPriority, message, filename, linenum, args...);
	}

	template<typename... Args>
	static void Error(const char* message, const char* filename, const int linenum, Args... args)
	{
		log("E: ", ErrorPriority, message, filename, linenum, args...);
	}

	template<typename... Args>
	static void Critical(const char* message, const char* filename, const int linenum, Args... args)
	{
		log("C: ", CriticalPriority, message, filename, linenum, args...);
	}

private :

	

	template<typename... Args>
	static void log1(const char* message_priority_str, LogPriority message_priority, const char* message, const char* filename, const int linenum, Args... args)
	{
		if (priority <= message_priority)
		{
			std::time_t current_time = std::time(NULL);
			std::tm* timestamp = std::localtime(&current_time);

			int year = timestamp->tm_year + 1900;
			int month = timestamp->tm_mon + 1;
			int day = timestamp->tm_mday;
			int hour = timestamp->tm_hour;
			int min = timestamp->tm_min;
			int sec = timestamp->tm_sec;

			printf(message_priority_str);
			printf("%d%d%d%d%d%d ", year, month, day, hour, min, sec);
			printf("FILEPATH : %s ", filename);
			printf("LINE : %d ", linenum);


			printf(message, args...);
			printf("\n");
		}
	}
	template<typename... Args>
	static void log2(const char* message_priority_str, LogPriority message_priority, const char* message, const char* filename, const int linenum, Args... args)
	{
		if (priority <= message_priority)
		{
			std::time_t current_time = std::time(NULL);
			std::tm* timestamp = std::localtime(&current_time);

			int year = timestamp->tm_year + 1900;
			int month = timestamp->tm_mon + 1;
			int day = timestamp->tm_mday;
			int hour = timestamp->tm_hour;
			int min = timestamp->tm_min;
			int sec = timestamp->tm_sec;

			if (FileManager::file)
			{

				fprintf(FileManager::file, message_priority_str);
				fprintf(FileManager::file, "%d%d%d%d%d%d", year, month, day, hour, min, sec);
				fprintf(FileManager::file, "FILEPATH : %s ", filename);
				fprintf(FileManager::file, "LINE : %d ", linenum);

				fprintf(FileManager::file, message, args...);
				fprintf(FileManager::file, "\n");
			}
		}
	}

	

	template<typename... Args>
	static void log(const char* message_priority_str, LogPriority message_priority, const char* message, const char* filename,const int linenum, Args... args)
	{
		if (priority <= message_priority)
		{
			std::time_t current_time = std::time(NULL);
			std::tm* timestamp = std::localtime(&current_time);

			int year = timestamp->tm_year + 1900;
			int month = timestamp->tm_mon + 1;
			int day = timestamp->tm_mday;
			int hour = timestamp->tm_hour;
			int min = timestamp->tm_min;
			int sec = timestamp->tm_sec;

			printf(message_priority_str );
			printf("%d%d%d%d%d%d ", year, month, day, hour, min, sec);
			printf("FILEPATH : %s ",filename);
			printf("LINE : %d ", linenum);
			

			printf(message, args...);
			printf("\n");

			if (FileManager::file)
			{
				
				fprintf(FileManager::file, message_priority_str);
				fprintf(FileManager::file, "%d%d%d%d%d%d ", year, month, day, hour, min, sec);
				fprintf(FileManager::file, "FILEPATH : %s ", filename);
				fprintf(FileManager::file, "LINE : %d ", linenum);

				fprintf(FileManager::file, message, args...);
				fprintf(FileManager::file, "\n");
			}
		}
	}
	

	
};

LogPriority Logger::priority = InfoPriority;


