// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задача №6
//«Операции над вектором»

//Изучите основные операции над вектором и продемонстрируйте их работу :

//1.push_back☺, erase, insert
//2.emplace_back
//3.resize☺, reserve☺, shrink_to_fit☺, capacity☺
//4.clear☺
//5.оператор присваивания☺ и[]☺

//Узнайте размер вектора и будьте готовы объяснить, почему именно так.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    vector <int> myVector = { 0,45,3,53,2,54 };// память под вектор выделяется в стеке но вектор хранит свои элементы в хипе
    myVector.reserve(100);//количество элементов находимых в capacity (создастся массив на 100 элементов)
    
    myVector[0] = 1000;// операция присваивания
    cout << "Количество элементов в векторе " << myVector.size() << endl;
    cout << "capacity вектора " << myVector.capacity() << endl;
    for (int i = 0;i < myVector.size();i++)
    {
        cout << myVector[i] << endl;// вектор это по сути прописанный нами динамический массив, к нему можно обращаться, как и к обычному массиву, указав индекс элемента массива

    }
    myVector.shrink_to_fit();//освобождается неиспользованная память (выделили память под более маленький массив скопировали данные и старый массив удалили)
    cout << "Количество элементов в векторе " << myVector.size() << endl;
    cout << "capacity вектора " << myVector.capacity() << endl;
    for (int i = 0;i < myVector.size();i++)
    {
        cout << myVector[i] << endl;// вектор это по сути прописанный нами динамический массив, к нему можно обращаться, как и к обычному массиву, указав индекс элемента массива

    }

    myVector.clear();
    cout << "clear() количество элементов в векторе " << myVector.size() << endl;//этод метод убирает все элементы
    for (int i = 0;i < myVector.size();i++)
    {
        cout << myVector[i] << endl;// вектор это по сути прописанный нами динамический массив, к нему можно обращаться, как и к обычному массиву, указав индекс элемента массива

    }
    myVector = { 7,13,23,12,43,5,65,34,234,53,5,3,5,1,0,90,89 };
    myVector.push_back(3);
    myVector.push_back(90);//метод pushback добавляет элемент в конец массива
    cout << "Количество элементов в векторе " << myVector.size() << endl;
    cout << "capacity вектора " << myVector.capacity() << endl;//capacity-size() = количество свободных ячеек;
    for (int i = 0;i < myVector.size();i++)
    {
        cout << myVector[i] << endl;// вектор это по сути прописанный нами динамический массив, к нему можно обращаться, как и к обычному массиву, указав индекс элемента массива

    }
    myVector.resize(8); //изменили размер вектора
    cout << "Количество элементов в векторе " << myVector.size() << endl;
    cout << "capacity вектора " << myVector.capacity() << endl;//capacity-size() = количество свободных ячеек;
    for (int i = 0;i < myVector.size();i++)
    {
        cout << myVector[i] << endl;// вектор это по сути прописанный нами динамический массив, к нему можно обращаться, как и к обычному массиву, указав индекс элемента массива

    }
    myVector.emplace_back(6);// метод emplace_back делает тоже самое что и push_back,только в отличии от push_back, который добавляет копию объекта emplace_back создает объект непосредственно в конце вектора, без лишнего копирования
    cout << "Количество элементов в векторе " << myVector.size() << endl;
    cout << "capacity вектора " << myVector.capacity() << endl;//capacity-size() = количество свободных ячеек;
    for (int i = 0;i < myVector.size();i++)
    {
        cout << myVector[i] << endl;// вектор это по сути прописанный нами динамический массив, к нему можно обращаться, как и к обычному массиву, указав индекс элемента массива

    }
    cout << "--------------" << endl;
    vector<int> my2Vector = { 9,4,2,43,23,3,54,32,60,92,8 };
    vector<int>::iterator it;
    it = my2Vector.begin();//возвращает итератор такого типа, какого требуется
   
    *it = 1000;//теперь мы можем работать с первым элементом, однако чтобы работать с остальными элементами нужно знать арифметику указателей и еще кое-что
    
    cout << *it << endl;
    cout << "--------------" << endl;
    it += 2;
    *it = 9;
    cout << *it << endl;//пример работы с 3 эл-том
    cout << "--------------" << endl;
    vector<int> my3Vector = { 7,4,2,43,23,3,84,32,60,92,8 };
    for (vector<int>::iterator i = my3Vector.begin();i != my3Vector.end();i++)
    {
        cout << *i << endl;
    }
    cout << endl << "insert" << endl << endl;
    vector<int>::iterator k = my3Vector.begin();
    advance(k, 5);
    my3Vector.insert(k, 999);//6 элемент поменяется на указанное значение за счет перескока итератора
    for (vector<int>::iterator i = my3Vector.begin();i != my3Vector.end();i++)
    {
        cout << *i << endl;
    }
    cout << endl << "erase" << endl << endl;
    vector<int>::iterator ke = my3Vector.begin();
    advance(ke, 2);
    my3Vector.erase(ke);//3-й эл-т убираем из массива
    for (vector<int>::iterator i = my3Vector.begin();i != my3Vector.end();i++)
    {
        cout << *i << endl;
    }
    

    return 0;
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
