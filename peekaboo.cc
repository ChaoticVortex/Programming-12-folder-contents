#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	
	//TO DO: Show entire texture but blurred except for circle of focus
	float mousex;
	float mousey;
	float radius = 150;
	
	int chlength = 15;
	int chwidth = 2;
	float chdist = 10;
	sf::Color chcolor = sf::Color(50, 255, 50);
	
	sf::RenderWindow window(sf::VideoMode(1280,1024), "seven is bigger than nine");
	/* sf::Window window;
	 * window.create((sf::VideoMode(800,600), "seven is bigger than nine");
	 */
	 window.setFramerateLimit(60);
	 window.setMouseCursorVisible(false);
	
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
	
	sf::RectangleShape chleft(sf::Vector2f(chlength, chwidth));
	sf::RectangleShape chright(sf::Vector2f(chlength, chwidth));
	sf::RectangleShape chup(sf::Vector2f(chlength, chwidth));
	sf::RectangleShape chdown(sf::Vector2f(chlength, chwidth));
	
	chup.rotate(90);
	chdown.rotate(90);
	
	chleft.setFillColor(chcolor);
	chright.setFillColor(chcolor);
	chup.setFillColor(chcolor);
	chdown.setFillColor(chcolor);
	
	
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
		

		chleft.setPosition(mousex - (chdist + chlength), mousey - chwidth/2);
		chright.setPosition(mousex + chdist, mousey - chwidth/2);
		chup.setPosition(mousex + chwidth/2 , mousey - (chdist + chlength));
		chdown.setPosition(mousex + chwidth/2  , mousey + chdist);
		
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(chleft);
		window.draw(chright);
		window.draw(chup);
		window.draw(chdown);
		window.display();
	}
	cout << "window is closing because you're bad" << endl;
	return 0;
}

