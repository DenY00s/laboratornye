#include <iostream>
#include <fstream>
#include "log.hpp"
#include <ctime>

#define N 10
int main()
{
	

	Log::SetLogPath("log.txt");
	Log::Write(LogLevel::INFO, "Hi, world!");
	Log::Write(LogLevel::ERROR, "No  errors");
	Log::Write(LogLevel::INFO, "Congrats");
	Log::Write(LogLevel::DEBUG, "Program is ended");

	return 0;
}