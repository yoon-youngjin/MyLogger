#define _CRT_SECURE_NO_WARNINGS

#include"Logger.h"
#include"FileManager.h"
#include <iostream>
#include<thread>
using namespace std;

int main()
{

    

    FileManager::EnableFileOutput("C:\\logs\\log5.txt");

    Logger::SetPriority(DebugPriority);

    
    
    Logger::Trace("log test ", __FILE__, __LINE__,2);
    
    Logger::Debug("log test ", __FILE__, __LINE__,1);
    
    Logger::Info("log test ", __FILE__, __LINE__,2);
    
    Logger::Warn("log test ", __FILE__, __LINE__,1);
    
    Logger::Error("log test ", __FILE__, __LINE__,2);
    
    Logger::Critical("log test ", __FILE__, __LINE__,3);


    fprintf(FileManager::file, "---------------------------------------------------------------------------------------------------------------------------------------------\n");
    FileManager::CloseFileOutput();
    



    //FileManager::RemoveFile("C:\\logs\\log.txt");
  

    return 0;

}

