#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


//the success of version 1 made the developers want to try version 2.
int main()
{
	//float xvel;
	//float yvel;

	float windowx = 1280;
	float windowy = 1024;
	float deceleration = 0.98;
	
	sf::RenderWindow window(sf::VideoMode(windowx,windowy), "six is bigger than eight");
	window.setFramerateLimit(60);

	sf::Texture ufotexture;
	if (!ufotexture.loadFromFile("ufo1.png")){
		cout << "ERROR ERROR SOMETHING WRONG" << endl;
		return 0;
	}
	
	sf::Sprite ufo;
	ufo.setTexture(ufotexture);
	ufo.setScale(0.1f, 0.1f);
	ufo.setPosition(windowx/2, windowy/2);
	sf::FloatRect bounds = ufo.getGlobalBounds();

	sf::Vector2<float> velocity;
	velocity.x = 0;
	velocity.y = 0;
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				cout << "YOU WANT TO CLOSE ME? SCREW YOU" << endl;
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				velocity.y -= 5;
				}
				
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
					velocity.y += 5;
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				velocity.x -= 5;
				}
				
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
					velocity.x += 5;
				}
				cout << "KEY PRESSED UH OHHH" << endl;
				
			}
		}
		bounds = ufo.getGlobalBounds();
		if (bounds.left < -bounds.width/2){
			ufo.setPosition(windowx - bounds.width/2, bounds.top);
		}
		else if (bounds.left > windowx - bounds.width/2){
			ufo.setPosition(-bounds.width/2, bounds.top);
		}
		if (bounds.top < -bounds.height/2){
			ufo.setPosition(bounds.left, windowy -bounds.height/2);
		}
		else if (bounds.top > windowy -bounds.height/2){
			ufo.setPosition(bounds.left, -bounds.height/2);
		}
		
		velocity.x = velocity.x * deceleration;
		velocity.y = velocity.y * deceleration;
		
		ufo.move(velocity.x,velocity.y);

		window.clear(sf::Color::Black);
		window.draw(ufo);
		window.display();
	}
	cout << "window is closing because you're bad" << endl;
	return 0;
}
