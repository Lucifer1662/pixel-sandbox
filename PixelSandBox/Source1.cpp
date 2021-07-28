//#pragma once
//#pragma once
//#define SFML_STATIC
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "glm/gtx/matrix_transform_2d.hpp"
//#include <thread>
//#include <vector>
//
//
//auto shapes = std::vector<std::unique_ptr<sf::Shape>>();
//
//
//
//
//
//int MultipleRectangleFloorScene()
//{
//	sf::RenderWindow window(sf::VideoMode(1000, 900), "Multiple Rectangle and Floor");
//
//
//	sf::Text fpsText = sf::Text();
//	auto worldImage = sf::Image();
//	worldImage.create(1000, 900);
//
//	for (size_t x = 0; x < 1000; x++)
//	{
//		for (size_t y = 0; y < 900; y++)
//		{
//			worldImage.setPixel(x, y, sf::Color::Red);
//		}
//	}
//
//	
//	sf::Texture worldTexture = sf::Texture();
//	worldTexture.create(1000, 900);
//	
//	worldTexture.loadFromImage(worldImage);
//
//
//	auto shape = sf::RectangleShape({ 1000,900 });
//	shape.setTexture(&worldTexture);
//	//shape.setFillColor(sf::Color::Red);
//	shape.setSize({ 1000,900 });
//	shape.setPosition({ 0, 0 });
//
//	worldImage.setPixel(10, 10, sf::Color::Black);
//	for (size_t x = 0; x < 1000; x++)
//	{
//		for (size_t y = 0; y < 900; y++)
//		{
//			worldImage.setPixel(x, y, sf::Color::Blue);
//		}
//	}
//
//
//	sf::Clock clock;
//	float lastTime = 0;
//	while (window.isOpen())
//	{
//		float currentTime = clock.restart().asSeconds();
//		float fps = 1.f / (currentTime - lastTime);
//		lastTime = currentTime;
//
//		fpsText.setString("FPS: " + std::to_string(fps));
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		
//
//		worldTexture.update(worldImage);
//		window.draw(shape);
//
//
//		/*for (size_t i = 0; i < bodies.size(); i++)
//		{
//			shapes[i]->setPosition({ bodies[i].position.x, bodies[i].position.y });
//			shapes[i]->setRotation(glm::degrees(bodies[i].angle));
//			window.draw(*shapes[i]);
//		}*/
//
//		window.draw(fpsText);
//		window.display();
//		window.clear();
//	}
//
//	return 0;
//}
//
//
//void main() {
//	MultipleRectangleFloorScene();
//}