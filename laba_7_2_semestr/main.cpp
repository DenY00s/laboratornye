#include <iostream>
#include <vector>
enum class Color
{
	Black,
	Gray,
	White,
	Yellow,
	Green,
	Red,
	Blue,
	Cyan,
	LightBlue,
	LightGray,
	Brown,
	Pink,
	Purple

};
class Coordinates
{
public:
	double x;
	double y;
};
class Shape
{
	
protected:
	Coordinates m_pose;
	Color m_color;
public:
	Shape(Coordinates pose, Color color) : m_pose(pose), m_color(color) {}
	virtual double Area()
	{
		return 0;
	}
	virtual void info()
	{
		std::cout << "info";
	}
};
class Triangle : public Shape
{
private:
	Coordinates a_, b_, c_;
public:
	Triangle(Coordinates pose, Color color, Coordinates a, Coordinates b, Coordinates c) : Shape(pose,color), a_(a),b_(b),c_(c) {}
	double Area() override
	{
		return std::abs(0.5 * ((a_.x-c_.x)*(b_.y - c_.y)-(b_.x - c_.x)*(a_.y - c_.y)));
	}
};
class Rectangle : public Shape
{
private:
	Coordinates a_, b_;
	
public:
	Rectangle(Coordinates pose, Color color, Coordinates a, Coordinates b) : Shape(pose, color), a_(a), b_(b) {}
	double Area() override
	{
		return (std::abs(a_.x-b_.x)* std::abs(a_.y - b_.y));
	}
};
class Circle : public Shape
{
private:
	double radius;
public:
	Circle(Coordinates s, Color color, double radius) : Shape(s, color), radius(radius){}
	double Area() override
	{
		return 3.14159265359 * (radius*radius);
	}
};
int main()
{
	Coordinates a1{ 0, 6 };
	Coordinates a2{ 3, 0 };
	Coordinates a3{ 2, 7.2 };
	Coordinates a4{ 9, 5 };
	Coordinates a5{ 20, 3 };
	Coordinates a6{ 71, 3.5 };
	Coordinates a7{ 40, 5 };
	Coordinates a8{ 19, 25 };
	Coordinates a9{ 28, -3 };
	Coordinates a10{ 6, 37 };
	Coordinates a11{ 14, 19.8 };
	Coordinates a12{ 0, 0 };
	std::vector<std::unique_ptr<Shape>> Figures;
	Figures.emplace_back(std::make_unique<Triangle>(a1, Color::Black, a1, a2,a12));
	Figures.emplace_back(std::make_unique<Triangle>(a2, Color::Brown, a7, a8,a12));
	Figures.emplace_back(std::make_unique<Circle>(a3, Color::Green, 15));
	Figures.emplace_back(std::make_unique<Rectangle>(a4, Color::Green, a12, a10));
	std::cout << Figures[0]->Area() << std::endl;
	std::cout << Figures[1]->Area() << std::endl;
	std::cout << Figures[2]->Area() << std::endl;
	std::cout << Figures[3]->Area() << std::endl;

}