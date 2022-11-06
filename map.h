#pragma once
#include <vector>
#include <string>
#include <random>
#include <ncurses.h>
using namespace std; //Boo hiss

class Map {
	vector<vector<char>> map;
	public:
	static const char SPACESHIP     = '^';
	static const char ALIEN  = 'A';
	static const char STARS     = '*';
	static const char ASTEROID    = 'o';
	static const char OPEN     = ' ';
	static const char TREASURE = '$';
	static const char PLANET = 'P';
	static const char SPACE_SHEEP = 'S';
	static const size_t SIZE = 100; //World is a 100x100 map
	static const size_t DISPLAY = 20; //Show a 20x20 area at a time
	//Randomly generate map
	void init_map() {
		random_device rd;     // only used once to initialise (seed) engine
		mt19937 gen(rd());    // random-number engine used (Mersenne-Twister in this case)
		uniform_int_distribution<int> d100(1,100);
		map.clear();
		map.resize(SIZE); //100 rows tall
		for (auto &v : map) v.resize(SIZE,'.'); //100 columns wide
		for (size_t i = 0; i < SIZE; i++) {
			for (size_t j = 0; j < SIZE; j++) {
				//Line the map with walls
				if (i == 0 or j == 0 or i == SIZE-1 or j == SIZE-1) 
					map.at(i).at(j) = STARS;
				else if (i == SIZE/2 and j == SIZE/2) 
					map.at(i).at(j) = SPACESHIP;
				else {
					//10% of alien
					if (d100(gen) <= 10) {
						map.at(i).at(j) = ALIEN;
					}
					else if (d100(gen) <= 6) { //6% stars
						map.at(i).at(j) = STARS;
					}
					else if (d100(gen) <= 15) { //15% asteroids
						map.at(i).at(j) = ASTEROID;
					}
					else if (d100(gen) <= 10) { //10% planets
						map.at(i).at(j) = PLANET;
					}
					else if (d100(gen) <= 2) {
						map.at(i).at(j) = SPACE_SHEEP;
					} 
					else if (d100(gen) <= 50) { //20% chance of asteroids near other asteroids
						if (map.at(i-1).at(j) == ASTEROID or map.at(i+1).at(j) == ASTEROID or map.at(i).at(j-1) == ASTEROID or map.at(i).at(j+1) == ASTEROID)
							map.at(i).at(j) = ASTEROID;
					}
				}
			}
		}
	}
	//Draw the DISPLAY tiles around coordinate (x,y)
	void draw(int x, int y) {
		int start_x = x - DISPLAY/2;
		int end_x = x + DISPLAY/2;
		int start_y = y - DISPLAY/2;
		int end_y = y + DISPLAY/2;

		//Bounds check to handle the edges
		if (start_x < 0) {
			end_x = end_x - start_x;
			start_x = 0;
		}
		if (end_x > int(SIZE-1)) {
			start_x = start_x - (end_x - (SIZE-1));
			end_x = SIZE-1;
		}
		if (start_y < 0) {
			end_y = end_y - start_y;
			start_y = 0;
		}
		if (end_y > int(SIZE-1)) {
			start_y = start_y - (end_y - (SIZE-1));
			end_y = SIZE-1;
		}

		//Now draw the map using NCURSES
		for (int i = start_y; i <= end_y; i++) {
			for (int j = start_x; j <= end_x; j++) {
				//if (i == cursor_x && j == cursor_y)
				//	attron(A_UNDERLINE | A_BOLD);
				int color = 1; //Open
				if (map.at(i).at(j) == STARS)
					color = 5;
				else if (map.at(i).at(j) == ASTEROID)
					color = 2;
				else if (map.at(i).at(j) == SPACESHIP)
					color = 3;
				else if (map.at(i).at(j) == TREASURE)
					color = 4;
				else if (map.at(i).at(j) == ALIEN)
					color = 6;
				else if (map.at(i).at(j) == PLANET)
					color = 7;
				else if (map.at(i).at(j) == SPACE_SHEEP)
					color = 8;

				attron(COLOR_PAIR(color));
				mvaddch(i-start_y,j-start_x,map.at(i).at(j));
				attroff(COLOR_PAIR(color));
				//attroff(A_UNDERLINE | A_BOLD);
			}
		}
	}
	void set(int x, int y, char c) {
		for (int i = 0; i <SIZE; i++){
			for (int j=0;j<SIZE;j++){
				if (map.at(i).at(j)==c)map.at(i).at(j)='.';
			}
		}
		map.at(y).at(x) = c;
	}
	char get(int x, int y) {
		return map.at(y).at(x);
	}
	Map() {
		init_map();
	}
};
