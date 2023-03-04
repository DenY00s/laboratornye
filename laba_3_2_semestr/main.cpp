#include <iostream>
#include <fstream>
//1.
void f()
{
	static int count = 0; // static, heap, static
	count++;
	std::cout << count << std::endl;
}
//2.
class Log
{
private:
	static std::ofstream m_out;

public:
	Log()
	{
		std::cout << "Constr" << std::endl;
	}
	static void SETLOGPATH(const std::string& path)
	{
		m_out.open(path);
	}
	static void Write(const std::string& msg)
	{
		std::cout << msg << std::endl;
		m_out << msg;
	}
	~Log()
	{
		std::cout << "Destr" << std::endl;
	}
};
std::ofstream Log::m_out;
int main()
{
	Log::SETLOGPATH("log.txt");
	Log::Write("Hello,world!");


	return 0;
}