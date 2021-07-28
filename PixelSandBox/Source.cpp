#pragma once
#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>
#include "glm/gtx/matrix_transform_2d.hpp"
#include <thread>
#include <vector>
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "glm/glm.hpp"
#include <array>
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Pixel.h"


#include "Grid.h"
#include "Cell.h";

using vec2 = glm::vec2;
using vec3 = glm::vec3;
using ivec2 = glm::ivec2;



void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}


void printToScreen(Grid& grid) {
	std::string s;
	for (int y = size-1; y >= 0; y--)
	{
		for (int x = 0; x < size; x++)
		{
			auto& cell = grid.at(x,y);
			if (cell.getPixel() == nullptr) {
				s += " ";
			}
			else {
				s += "O";
			}
		}
		s += '\n';
	}
	std::cout << s;
	std::flush(std::cout);

}

/*
void main() {


	std::vector<std::unique_ptr<Pixel>> pixels;
	

	Grid grid(size);

	pixels.push_back(std::make_unique<Pixel>(&grid.at(size/2,size/2), Water));

	pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2,size / 2+1), Water));
	pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2 + 1,1), Fire));
	pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2 + 1,0), Fire));

	while (true) {
		for (int i = 0; i < 1; i++) {
			for (auto& pixel : pixels) {
				pixel->update();
			}
		}
		clear();
		printToScreen(grid);
		Sleep(10);
		int j = 0;


	}

}*/




auto shapes = std::vector<std::unique_ptr<sf::Shape>>();



float randF(float m) {
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r* m;
}

vec2 randVec2(float m) {
	return vec2(randF(m), randF(m));
}


int MultipleRectangleFloorScene()
{
	sf::RenderWindow window(sf::VideoMode(1000, 900), "Multiple Rectangle and Floor");


	sf::Text fpsText = sf::Text();
	auto worldImage = sf::Image();
	worldImage.create(1000, 900, sf::Color::Black);


	sf::Texture worldTexture = sf::Texture();
	worldTexture.create(1000, 900);

	worldTexture.loadFromImage(worldImage);


	auto shape = sf::RectangleShape({ 1000,900 });
	shape.setTexture(&worldTexture);
	//shape.setFillColor(sf::Color::Red);
	shape.setSize({ 1000,900 });
	shape.setPosition({ 0, 0 });

	



	std::vector<std::unique_ptr<Pixel>> pixels;


	Grid grid(size);
	/*for (size_t x = 0; x < 900/5; x++)
	{
		for (size_t y = 0; y < 900/5; y++)
		{
			if (rand() % 89 == 0) {
				pixels.push_back(std::make_unique<Pixel>(&grid.at(x, y), Water));
			}
		}
	}
	*/

	/*for (size_t i = 0; i < 10; i++)
		pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2, i), Fire, randVec2(0.4f)));
		*/
	pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2, size / 2), Water, randVec2(0.4f)));



	//pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2, size / 2), Water));
	//pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2, size / 2 + 1), Water));
	//pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2 + 1, 1), Fire));
	//pixels.push_back(std::make_unique<Pixel>(&grid.at(size / 2 + 1, 0), Fire));




	sf::Clock clock;
	float lastTime = 0;
	while (window.isOpen())
	{
		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / (currentTime - lastTime);
		lastTime = currentTime;

		fpsText.setString("FPS: " + std::to_string(fps));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (int i = 0; i < 1; i++) {
			for (auto& pixel : pixels) {
				pixel->update();

				if (pixel->getCell()->getPosition().x == 3 && pixel->getCell()->getPosition().y == 4) {
					int asdfd = 0;
				}
			}
		}

		for (auto& pixel : pixels) {
			auto cell = pixel->getCell();
			auto pos = cell->getPosition();
			const int s = 5;
			for (size_t x = 0; x < s; x++)
			{
				for (size_t y = 0; y < s; y++)
				{
					int yy = 900 - s - pos.y * s + y;
					worldImage.setPixel(pos.x*s + x, 900 - s - pos.y*s + y, sf::Color::Blue);
				}
			}

			cell = pixel->getPrevCell();
			if (cell != nullptr) {
				pos = cell->getPosition();
				for (size_t x = 0; x < s; x++)
				{
					for (size_t y = 0; y < s; y++)
					{
						worldImage.setPixel(pos.x * s + x, 900 - s - pos.y * s + y, sf::Color::Black);
					}
				}
			}
			
		}





		worldTexture.update(worldImage);
		window.draw(shape);

		Sleep(10);


		/*for (size_t i = 0; i < bodies.size(); i++)
		{
			shapes[i]->setPosition({ bodies[i].position.x, bodies[i].position.y });
			shapes[i]->setRotation(glm::degrees(bodies[i].angle));
			window.draw(*shapes[i]);
		}*/

		window.draw(fpsText);
		window.display();
		window.clear();
	}

	return 0;
}


void main() {
	MultipleRectangleFloorScene();
}