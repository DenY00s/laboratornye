#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>

class KinematicSolver {
private:
    double L1, L2;

public:
    KinematicSolver(double L1, double L2) : L1(L1), L2(L2) {}

    std::pair<double, double> solve(double x, double y) {
        double d = std::sqrt(x * x + y * y);
        double alpha = std::atan2(y, x);

        double cos_beta = (d * d - L1 * L1 - L2 * L2) / (2 * L1 * L2);
        double beta = std::atan2(std::sqrt(1 - cos_beta * cos_beta), cos_beta);

        double gamma = std::atan2(L2 * std::sin(beta), L1 + L2 * std::cos(beta));

        alpha = alpha - gamma;
        beta = M_PI - beta;

        return std::make_pair(alpha * 180.0 / M_PI, beta * 180.0 / M_PI);
    }
};

int main() {
    const double L1 = 100.0;
    const double L2 = 80.0;

    KinematicSolver solver(L1, L2);

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Kinematic Solver", sf::Style::Fullscreen);

    sf::RectangleShape link1(sf::Vector2f(L1, 5));
    sf::RectangleShape link2(sf::Vector2f(L2, 5));
    sf::CircleShape endEffector(10);

    link1.setOrigin(0, 2.5);
    link2.setOrigin(0, 2.5);
    endEffector.setOrigin(10, 10);

    link1.setFillColor(sf::Color::Blue);
    link2.setFillColor(sf::Color::Red);
    endEffector.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        double mouseX = sf::Mouse::getPosition(window).x - window.getSize().x / 2;
        double mouseY = sf::Mouse::getPosition(window).y - window.getSize().y / 2;

        auto angles = solver.solve(mouseX, mouseY);
        double alpha = angles.first;
        double beta = angles.second;

        link1.setRotation(alpha);
        link2.setRotation(alpha + beta);

        sf::Vector2f link1End = link1.getTransform().transformPoint(link1.getPoint(1));
        link2.setPosition(link1End);
        endEffector.setPosition(link2.getTransform().transformPoint(link2.getPoint(1)));

        window.clear(sf::Color::White);

        // Смещаем робота в центр окна
        sf::Transform transform;
        transform.translate(window.getSize().x / 2, window.getSize().y / 2);
        window.draw(link1, transform);
        window.draw(link2, transform);
        window.draw(endEffector, transform);

        window.display();
    }

    return 0;
}