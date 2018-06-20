#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	float mousex;
	float mousey;
	float radius = 50;
	
	sf::RenderWindow window(sf::VideoMode(800,600), "seven is bigger than nine");
	/* sf::Window window;
	 * window.create((sf::VideoMode(800,600), "seven is bigger than nine");
	 */
	 window.setFramerateLimit(60);
	
	sf::Texture texture;
	if (!texture.loadFromFile("beach.jpeg")){
		cout << "ERROR ERROR SOMETHING WRONG" << endl;
		return 0;
	}
	
	texture.setRepeated(true);
	/*
	sf::Sprite sprite;
	sprite.setTexture(texture);
	*/
	
	sf::CircleShape shape(radius);
	shape.setTexture(&texture);
	
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				cout << "YOU WANT TO CLOSE ME? SCREW YOU" << endl;
				window.close();
			}
			else if (event.type == sf::Event::MouseMoved){
				    mousex = event.mouseMove.x;
					mousey = event.mouseMove.y;
			}
		}
		
		shape.setPosition(mousex - radius, mousey - radius);
		shape.setTextureRect(sf::IntRect(mousex- radius, mousey-radius, radius * 2, radius * 2));
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.display();
	}
	cout << "window is closing because you're bad" << endl;
	return 0;
}
