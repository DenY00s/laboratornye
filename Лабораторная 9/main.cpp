#include <iostream>

class Circle {
private:
    unsigned int m_radius;
public:
    Circle(double radius) : m_radius(radius) {}

    double getRadius() {
        return m_radius;
    }

    double getLength() {
        return 2 * acos(-1) * m_radius;
    }
};

int main() {
    Circle circle(1);

    std::cout << circle.getLength() << std::endl;
}