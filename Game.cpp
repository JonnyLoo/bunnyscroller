#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(1280, 800), "bunny");

	sf::Texture bunny1;
	bunny1.loadFromFile("bunny1.png");
	bunny1.setSmooth(true);

	sf::Texture background1;
	background1.loadFromFile("background1.png");

	// sf::Texture background2;
	// background1.loadFromFile("background2.png");

	sf::Sprite sprite;
	sprite.setTexture(bunny1);
	sprite.setPosition(sf::Vector2f(10, window.getSize().y - 155));

	sf::Sprite b1;
	b1.setTexture(background1);
	b1.setScale(1280 / b1.getLocalBounds().width, 800 / b1.getLocalBounds().height);

	// sf::Sprite b2;
	// b2.setTexture(background2);

	bool facingRight = true;

	while(window.isOpen()) {

		sf::Event event;
		while(window.pollEvent(event)) {

			if(event.type == sf::Event::Closed) {

				window.close();
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

			if(facingRight) {

				facingRight = !facingRight;
				sprite.setScale(-1, 1);
			}
			sprite.move(-3, 0);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

			if(!facingRight) {

				facingRight = !facingRight;
				sprite.setScale(1, 1);
			}
			sprite.move(3, 0);
		}

		window.clear(sf::Color::Black);
		window.draw(b1);
		//window.draw(b2);
		window.draw(sprite);
		window.display();
	}

	return 0;
}