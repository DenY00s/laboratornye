#include < iostream>
#include <vector>

struct String
{
private:
	size_t m_size;
	char* m_str = nullptr;
	
public:
	// Конструктор по умолчанию
	String() = default;
	// Запрещенный конструктор
	String(int c, size_t size) = delete;
	// Конструктор (неявное преобразование типов из int в char)
	String(char c, size_t size) :m_size(size), m_str(new char[size+1])
	{
		std::cout << "Constructor #1" << std::endl;
		std::fill(m_str, m_str + m_size, c);
		m_str[m_size] = 0;
	}
	// Список инициализации членов класса
	String(char* str) : m_size(strlen(str)), m_str(new char[m_size+1])
	{
		std::cout << "Constructor #2" << std::endl;
		std::copy(str, str + m_size, m_str);
		m_str[m_size] = 0;
	}
	// Конструктор копирования + делегирующий конструктор
	String(const String& other) :String(other.m_str)
	{
		std::cout << "Copy constructor" << std::endl;
	}
	String& operator=(String temp)
	{
		std::cout << "Copy assigment operator" << std::endl;
		// Rule Copy and Swap
		std::swap(m_size, temp.m_size);
		std::swap(m_str, temp.m_str);
		return *this;
	}
	String& operator+=(const String temp)
	{
		m_size = m_size + temp.m_size;
		m_str = new char[m_size + 1];
		std::strcpy(m_str, std::strcat(m_str, temp.m_str));
		return *this;
	}
	String operator+(const String temp)
	{
		size_t newSize = temp.m_size;
		char* newStr = new char[m_size + newSize + 1];
		for (size_t i = 0; i < m_size; i++)
		{
			newStr[i] = m_str[i];
		}
		for (size_t i = 0; i < newSize; i++)
		{
			newStr[m_size + i] = temp.m_str[i];
		}
		delete m_str;
		m_str = newStr;
		m_size += newSize;
		newStr[m_size] = '\0';
		return m_str;
	}
	bool operator>(const char* temp)
	{
		bool flag = false;
		if (m_str > temp)
			flag = true;
		return flag;
	}
	bool operator<(const char* temp)
	{
		bool flag = false;
		if (m_str < temp)
			flag = true;
		return flag;
	}
	bool operator==(const char* temp)
	{
		bool flag = false;
		if (m_str == temp)
			flag = true;
		return flag;
	}
	int find(char c)
	{
		for (int i = 0; i < m_size; i++)
			if (m_str[i] == c)
			{
				return i;
			}
	}
	int length(String temp)
	{
		return temp.m_size;
	}
	char& operator[](int index)
	{
		if (index < 0 || index > m_size)
		{
			throw("WRONG INDEX");
		}
		return m_str[index];
	}
	char* c_str()
	{
		char* new_mas = new char[m_size];
		for (int i = 0; i < m_size; i++)
			new_mas[i] = m_str[i];
		return new_mas;
	}
	char& at(int index)
	{
		if (0 <= index && index < m_size)
			return m_str[index];
		else
		{
			throw("WRONG INDEX");
		}
	}
	~String()
	{
		std::cout << "destructor" << std::endl;
		if (m_str != nullptr)
			delete[] m_str;
	}
	size_t Size() const //constant method
	{
		return m_size;
	}
	void Print() const
	{
		for (int i = 0; i < m_size; i++)
			std::cout << m_str[i];
	}
	friend std::ostream& operator << (std::ostream& out, String& s);
	friend std::istream& operator >> (std::istream& in, String& s);
};
std::istream& operator >> (std::istream& in, String& s)
{
	size_t newSize = 0;

	char c[100] = { '\0' };

	in.getline(c, 100);

	for (size_t i = 0; i < 100; i++)
	{
		if (c[i] != '\0') {
			newSize++;
		}
	}
	char* newStr = new char[s.m_size + newSize];

	for (size_t i = 0; i < s.m_size; i++)
	{
		newStr[i] = s.m_str[i];
	}

	for (size_t i = 0; i < newSize; i++)
	{
		newStr[s.m_size + i] = c[i];
	}

	delete s.m_str;

	s.m_str = newStr;

	s.m_size = s.m_size + newSize;

	return in;
}
std::ostream& operator << (std::ostream& out, String& s)
{
	char* c = s.c_str();
	for (size_t i = 0; i < s.m_size; i++) {
		out << c[i];
	}

	return out;
}

int main()
{
	String s1("Hello, world!");
	String s2("test");
	String s3("111");
	std::cout << s2[3] << std::endl;
	s2[3] = 'k';
	s3 = s1;
	std::cout << s2;
	std::cout << s2.find('e');

	
	return 0;

}