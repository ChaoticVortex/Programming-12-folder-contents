#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
#define PI 3.14159265
float windowx = 1280;
float windowy = 1024;
float deceleration = 0.97;

class Asteroid{
public:
	Asteroid();
	sf::Vector2 <float> position;
	sf::Vector2 <float> velocity;
	sf::Sprite object;
	static int count;
	~Asteroid();
};

Asteroid::Asteroid(){
	// DOES NOT INITIALIZE THE POSITION
	count++;
	//sf::Vector2 <float> position = new sf::Vector2 <float>;
	//sf::Vector2 <float> velocity = new sf::Vector2 <float>;
	int side = rand() % 4; 
	/* top = 1
	 * bottom = 2
	 * left = 3
	 * right = 4
	 */
	if (side < 2){
		this -> position.x = rand()% int(windowx);
		if (side == 0){
			this -> position.y = 0;
		}
		else{
			this -> position.y = windowy;
		}
	}
	else{
		this -> position.y = rand()% int(windowy);
		if (side == 2)
			this -> position.x = 0;
		else
			this -> position.x = windowx;
	}

	this -> object.setScale(0.2f, 0.2f);
	sf::FloatRect localBounds = this -> object.getLocalBounds();
	this -> object.setOrigin(localBounds.width/2.0, localBounds.height/2.0);
	this -> velocity.x = 1;
	this -> velocity.y = 1;
}

Asteroid::~Asteroid(){
	count--;
}


int Asteroid::count = 0;



sf::Vector2<float> thrust(sf::Sprite object, sf::Vector2<float> velocity, float totalvelocity){
	velocity.y -= sin((object.getRotation()+90)*PI/180) * totalvelocity;
	velocity.x -= cos((object.getRotation()+90)*PI/180) * totalvelocity;
	return velocity;
}

void decelerate(sf::Vector2<float>*velocity){
	velocity->x = velocity->x * deceleration;
	velocity->y = velocity->y * deceleration;
	return;
}

void move(sf::Vector2<float> *position, sf::Vector2<float>*velocity){
	position->x += velocity->x;
	position->y += velocity->y;
	return;
}

bool boundsCheck(sf::Vector2<float> * position){
	bool unchanged = true;
	if (position->x < 0){
		position->x = windowx;
		unchanged = false;
	}
	else if (position->x > windowx){
		position->x = 0;
		unchanged = false;
	}
	if (position->y < 0){
		position->y = windowy;
		unchanged = false;
	}
	else if (position->y > windowy){
		position->y = 0;
		unchanged = false;
	}
	return unchanged;
}

//the success of version 1 made the developers want to try version 2.
int main()
{
	//float xvel;
	//float yvel;
	
	srand(time(NULL));

	float totalvelocity = 5;
	float anglechange = 8;
	
	sf::RenderWindow window(sf::VideoMode(windowx,windowy), "six is bigger than eight");
	window.setFramerateLimit(60);

	sf::Texture ufotexture;
	if (!ufotexture.loadFromFile("ufo1.png")){
		cout << "ERROR ERROR SOMETHING WRONG" << endl;
		return 0;
	}
	sf::Texture asteroidtexture;
	if (!asteroidtexture.loadFromFile("asteroid.png")){
		cout << "ERROR ERROR SOMETHING WRONG" << endl;
		return 0;
	}
	
	sf::Sprite ufo;
	ufo.setTexture(ufotexture);
	ufo.setScale(0.1f, 0.1f);
	ufo.setRotation(0);
	sf::FloatRect localBounds = ufo.getLocalBounds();
	ufo.setOrigin(localBounds.width/2.0, localBounds.height/2.0);
	

	sf::Vector2<float> position;
	position.x = windowx/2;
	position.y = windowy/2;
	
	sf::Vector2<float> velocity;
	velocity.x = 0;
	velocity.y = 0;
	
	Asteroid* xd = new Asteroid;

	xd -> object.setTexture(asteroidtexture);
	/*
	xd -> object.setScale(0.2f, 0.2f);
	localBounds = xd -> object.getLocalBounds();
	xd -> object.setOrigin(localBounds.width/2.0, localBounds.height/2.0);
	xd -> velocity.x = 1;
	xd -> velocity.y = 1;
	*/
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
					velocity = thrust(ufo, velocity, totalvelocity);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) or sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				ufo.rotate(-anglechange);
				}
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) or sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				ufo.rotate(anglechange);
				}
				
			}
		}
		
		
		
		decelerate(&velocity);
		move(&position, &velocity);
		boundsCheck(&position);

		
		
		move(&(xd -> position), &(xd -> velocity));
		boundsCheck(&(xd ->position));
		
		
		ufo.setPosition(position);
		xd -> object.setPosition(xd->position);



		window.clear(sf::Color::Black);
		window.draw(ufo);
		window.draw(xd -> object);
		window.display();
	}
	cout << "window is closing because you're bad" << endl;
	return 0;
}
