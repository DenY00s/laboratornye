#include <iostream>

template <typename T>
class Stack
{
private:
	T *ptr;
	int size;
	int topindex;
public:
	Stack(int s)
	{
		size = s;
		try
		{
		ptr = new T[size];
		}
		catch (std::bad_alloc& prob)
		{
			std::cerr << "Error: " << prob.what() << std::endl;
		}
		topindex = -1;
	}
	int getSize()
	{
		return size;
	}
	bool empty()
	{
		return topindex == -1;
	}
	void push(T value)
	{
		if (topindex == size - 1)
		{
			throw std::overflow_error("Stack is full");
		}
		ptr[++topindex] = value;
	}
	T pop()
	{
		if (empty())
		{
			throw std::out_of_range("Stack is empty");
		}
		return ptr[topindex--];
	}
	T top()
	{
		if (empty())
		{
			throw std::logic_error("Stack is empty");
		}
		return ptr[topindex];
	}
	~Stack()
	{
		delete[] ptr;
	}
};
int main()
{
	try
	{

	}
	catch (const std::overflow_error& err)
	{
		std::cerr << "overflow_error" << err.what() << std::endl;
	}
	catch (const std::bad_alloc& err)
	{
		std::cerr << "Error: " << err.what() << std::endl;
	}
	catch (const std::logic_error& err)
	{
		std::cerr << "logic_error" << err.what() << std::endl;
	}
	catch (std::out_of_range& err)
	{
		std::cerr << "out_of_range" << err.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Something went wrong" << std::endl;
	}
	Stack <int> steck(4);
	steck.push(1);
	steck.push(9);
	steck.push(3);
	steck.push(4);
	try
	{
		
	}
	catch (const std::overflow_error& err)
	{
		std::cerr << "Stack is full" << err.what() << std::endl;
	}
	catch (const std::bad_alloc& err)
	{
		std::cerr << "Error: " << err.what() << std::endl;
	}
	catch (const std::logic_error& err)
	{
		std::cerr << "Stack is empty" << err.what() << std::endl;
	}
	catch (std::out_of_range& err)
	{
		std::cerr << "Stack is empty" << err.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Something went wrong" << std::endl;
	}
	std::cout << steck.pop() << std::endl;
	std::cout << steck.top() << std::endl;
	std::cout << steck.empty() << std::endl;
	std::cout << steck.pop() << std::endl;
	std::cout << steck.pop() << std::endl;
	std::cout << steck.pop() << std::endl;
	std::cout << steck.empty() << std::endl;
	try
	{
		std::cout << steck.pop() << std::endl;
	}
	catch (const std::overflow_error& err)
	{
		std::cerr << "Stack is full" << err.what() << std::endl;
	}
	catch (const std::bad_alloc& err)
	{
		std::cerr << "Error: " << err.what() << std::endl;
	}
	catch (const std::logic_error& err)
	{
		std::cerr << "Stack is empty" << err.what() << std::endl;
	}
	catch (std::out_of_range& err)
	{
		std::cerr << "Stack is empty" << err.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Something went wrong" << std::endl;
	}
	



}