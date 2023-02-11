//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Atext
{
private:

	string m_text;
	double m_duration;

public:
	Atext(string text, double duration)
	{
		m_text = text;
		m_duration = duration;
	}
	~Atext()
	{

	}

	string getText(double ctime)
	{
		string ctext;
		double t0 = m_duration / m_text.size();
		int k = int(ctime) / int(t0);
		for (size_t i = 0; i < k; i++)
		{
			if (i > m_text.size())
				break;
			ctext += m_text[i];

		}
		return ctext;
	}

};
class Window
{
private:

	sf::RenderWindow* m_window;
	sf::Clock m_timer;

public:
	Window(const int& width, const int& height, const string& caption)
	{
		m_window = new sf::RenderWindow(sf::VideoMode(width, height), caption);
	}
	~Window()
	{
		if (m_window != nullptr)
			delete m_window;

	}
	void Run()
	{
		m_timer.restart();

		Atext atext = Atext("hello world", 13);

		sf::Font font;
		if (!font.loadFromFile("d:/projects/sfml_sample-main/orange_juice_2.0.ttf"))
			cout << "You can't load from file";

		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window->close();
			}
			sf::Time time = m_timer.getElapsedTime();

			m_window->clear();
			sf::Text text;
			text.setString(atext.getText(double(time.asSeconds())));
			text.setFont(font);
			text.setFillColor(sf::Color::Red);
			text.setPosition(0, 0);

			m_window->draw(text);
			m_window->display();
		}
	}


};

int main()
{
	Window window(800, 600, "Animated text");
	window.Run();
	return 0;

}