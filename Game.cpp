#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

	const int gravity = 2;

	sf::RenderWindow window(sf::VideoMode(1280, 800), "bunny");

	sf::View view1(sf::Vector2f(400, 400), sf::Vector2f(1200, 800));

	sf::Texture bunnies[4];
	bunnies[0].loadFromFile("bunny1.png");
	bunnies[1].loadFromFile("bunny2.png");
	bunnies[2].loadFromFile("bunny3.png");
	bunnies[3].loadFromFile("bunny4.png");
	bunnies[0].setSmooth(true);
	bunnies[1].setSmooth(true);
	bunnies[2].setSmooth(true);
	bunnies[3].setSmooth(true);

	sf::Texture background1;
	background1.loadFromFile("background1.png");

	sf::Texture background2;
	background2.loadFromFile("background2.png");

	sf::Sprite sprite;
	sprite.setTexture(bunnies[0]);
	sprite.setPosition(sf::Vector2f(10, window.getSize().y - 155));

	sf::Sprite b1;
	b1.setTexture(background1);
	b1.setScale(1280 / b1.getLocalBounds().width, 800 / b1.getLocalBounds().height);
	sf::Sprite b1_2;
	b1_2.setTexture(background1);
	b1_2.setScale(1280 / b1_2.getLocalBounds().width, 800 / b1_2.getLocalBounds().height);
	b1_2.setPosition(sf::Vector2f(1280, 0));
	sf::Sprite b1_b;
	b1_b.setTexture(background1);
	b1_b.setScale(1280 / b1_b.getLocalBounds().width, 800 / b1_b.getLocalBounds().height);
	b1_b.setPosition(sf::Vector2f(-1280, 0));

	b1.setColor(sf::Color(255, 255, 255, 250));
	b1_2.setColor(sf::Color(255, 255, 255, 250));
	b1_b.setColor(sf::Color(255, 255, 255, 250));

	sf::Sprite b2;
	b2.setTexture(background2);
	b2.setScale(1280 / b2.getLocalBounds().width, 800 / b2.getLocalBounds().height);
	sf::Sprite b2_2;
	b2_2.setTexture(background2);
	b2_2.setScale(1280 / b2_2.getLocalBounds().width, 800 / b2_2.getLocalBounds().height);
	b2_2.setPosition(sf::Vector2f(1280, 0));
	sf::Sprite b2_b;
	b2_b.setTexture(background2);
	b2_b.setScale(1280 / b2_b.getLocalBounds().width, 800 / b2_b.getLocalBounds().height);
	b2_b.setPosition(sf::Vector2f(-1280, 0));

	bool facingRight = true;
	bool animated = false;
	int anim_count = 0;
	int anim_speed = 0;

	bool onGround = true;
	bool jumping = false;
	int yVel = 0;

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
			sprite.move(-8, 0);
			b1.move(-2, 0);
			b1_2.move(-2, 0);
			b1_b.move(-2, 0);
			b2.move(-3, 0);
			b2_2.move(-3, 0);
			b2_b.move(-3, 0);
			animated = true;
		}

		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

			if(!facingRight) {

				facingRight = !facingRight;
				sprite.setScale(1, 1);
			}
			sprite.move(8, 0);
			b1.move(2, 0);
			b1_2.move(2, 0);
			b1_b.move(2, 0);
			b2.move(3, 0);
			b2_2.move(3, 0);
			b2_b.move(3, 0);
			animated = true;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			if(onGround) {

				yVel = -25;
				onGround = false;
				jumping = true;
			}
		}

		yVel += gravity;

		if(!jumping) {

			yVel = 0;
		}

		if(sprite.getPosition().y + yVel > (window.getSize().y - 155)) {

			onGround = true;
			jumping = false;
		}

		sprite.move(0, yVel);

		if(animated) {

			anim_speed++;
			if(anim_speed == 5) {

				anim_speed = 0;
				anim_count++;
			}

			if(anim_count > 3) {

				anim_count = 0;
			}
			sprite.setTexture(bunnies[anim_count]);
		}

		animated = false;

		view1.setCenter(sprite.getPosition().x, 400);

		window.clear(sf::Color::Black);
		window.setView(view1);
		window.draw(b1);
		window.draw(b1_2);
		window.draw(b1_b);
		window.draw(b2);
		window.draw(b2_2);
		window.draw(b2_b);
		window.draw(sprite);
		window.display();
	}

	return 0;
}