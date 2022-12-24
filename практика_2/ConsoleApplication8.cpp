// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
std::string bigsum(std::string A, std::string B)
{
    while (A.length() != B.length())
    {
        if (A.length() < B.length())
            A = "0" + A;
        else
            B = "0" + B;

    }
    std::string C;
    A = '0' + A;
    B = '0' + B;
    int sum, r = 0, i;
    for (int i = A.length() - 1;i > -1;i--)
    {
        sum = A[i] - '0' + B[i] - '0' + r;
        r = sum / 10;
        C = char(sum % 10 + '0') + C;

    }
    if (C[0] == '0')
        C.erase(0, 1);
    return C;
}
std::string Umn(std::string a, std::string b)
{
    std::string c = a + b;

    for (int i = 0; i < a.length() + b.length(); i++)
    {
        c[i] = '0';
    }

    std::string Result = c;

    std::string D = c;

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            int c1 = a[a.length() - i - 1] - 48;
            int c2 = b[b.length() - j - 1] - 48;

            int mult = c1 * c2;

            c[c.length() - j - i - 1] = char(mult % 10 + 48);
            c[c.length() - j - i - 2] = char(mult / 10 + 48);


            while (Result.length() > c.length())
            {
                c = '0' + c;
            }

            Result = bigsum(Result, c);

            c = D;
        }

    }
    if (Result[0] == '0')
    {
        Result.erase(0, 1);
    }
    return Result;
}

int main()
{
    std::string A, B, E;
    getline(std::cin, A);
    getline(std::cin, E);
    getline(std::cin, B);
    
    if (E == "Сумма" || E == "+")
    {
        std::cout << bigsum(A, B);

    }

    if (E == "умножить" || E == "*")
    {

        std::cout << Umn(A, B);
    }


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
