//NOTE TO STUDENTS - you can delete this whole file and start from scratch if you want
//Partners- Walkup & Giordano

#include "map.h"
#include <unistd.h>
#include <chrono>
#include <cstdlib>
#include <cmath>
//Don't use cout or cin, that's why this is commented out
#include <iostream>
using namespace std::chrono;
using hrc = std::chrono::high_resolution_clock;

const unsigned int TIMEOUT = 10; //Milliseconds to wait for a getch to finish
const int UP = 65; //Key code for up arrow
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;

void turn_on_ncurses() {
	initscr();//Start curses mode
	start_color(); //Enable Colors if possible
	init_pair(1, COLOR_GREEN, COLOR_BLACK); //Set up some color pairs, 
	init_pair(2, COLOR_CYAN, COLOR_BLACK); //ASTEROID
	init_pair(3, COLOR_BLACK, COLOR_WHITE); //Spaceship
	init_pair(5, COLOR_YELLOW, COLOR_BLACK); //Stars
	init_pair(6, COLOR_RED, COLOR_BLACK); //Alien
	init_pair(7, COLOR_CYAN, COLOR_GREEN); //Planet
	init_pair(8, COLOR_YELLOW, COLOR_WHITE); //SPACE_SHEEP
	clear();
	noecho();
	cbreak();
	timeout(TIMEOUT); //Set a max delay for key entry
}
void turn_off_ncurses(){
	clear();
	endwin(); // End curses mode
	system("clear");
}

void game_startup() {
	turn_off_ncurses();
	cout << "Welcome to the Space Game!\n";
	cout << endl;
	cout << "This unique space game allows the player to perform two tasks. The UI consists of the game map of outer space, containing numerous stars, planets, asteroids, space sheep, and aliens. The stars, planets, and asteroids are a unique decoration of the game map of outer space. The alien and space sheep are considered to be the antagonists of the space game. Two different challenges are available for the player to go through. One challenge involves battling with the alien. The other challenge involves challenging our space sheep. Each challenge gives the player the opportunity to win, if not, a possible number of times. There may be a small chance of losing one or both challenges. However, there's always at least some time in the world for the player to try again!\n";
	cout << endl;
	cout << "When the player enters the game, a space ship represents the player character. The spaceship is shown by the '^' symbol. The character will start at the middle of the screen. The player has the option to navigate the space ship through the map to get to places. Some characters in the game; asteroids and planets, serve only as a decoration and have no part in interaction. The planets are represented by the 'P' symbol and the asteroids are represented by the 'o' symbol. Although the stars also serve as a decoration, the player will end up being blocked by the '*' symbol, representing the star. Aliens are represented by the 'A' symbol, and they are one of the characters that players can battle. When the spaceship (the player is controlling) hovers over the 'A' symbol, the player has entered the battle with the alien. The alien's health starts off lower than the player's health, in order for the player to gain the advantage of winning the game.\n";
	cout << endl;
	cout << "On the second challenge, the player challenges our space sheep, which is one of the antagonists of the game with the alien. This challenge sort of comes with a twist, ensuring that the player rolls dice of the same number with the space sheep in order to win the puzzle. The odds are slim on defeating the space sheep, but the player has infinitely many chances to win the puzzle.\n";
	cout << endl;
	cout << "There are two features in this game.\n";
	cout << "Feature 1 involves battling with our alien!\n";
	cout << "Feature 2 involves challenging our space sheep!\n";
	cout << "In feature 1, you are in a face-to-face combat with the alien!\n";
	cout << "In order to defeat the alien, your health must be higher than the alien's health and the alien's health must be fully depleted!\n";
	cout << "In feature 2, you are rolling dice with the space sheep and hoping for the odds to win against it!\n";
	cout << "In order to defeat the space sheep, you must roll a number higher than the one the space sheep has.\n";
	cout << "If you roll a number higher than what the space sheep has, you win the challenge!\n";
	cout << "If you roll a number lower than what the space sheep has, you lose the challenge and must try again to win!\n";
	cout << endl;
	cout << "Are you ready for yout challenges? Press 'a' and 'enter' to enter the game map!\n";
	cout << endl;
	cout << "To quit the game at anytime, press 'Ctrl' (Control) and 'C' to quit.\n";
	cout << endl;
	turn_on_ncurses();
}

//Function allowing the player to attack the alien. 
void alienbattle(int& player_hp) {
	turn_off_ncurses();
	int alien_hp = 50;
	char s;
		cout << "You are now battling an alien. Press 'a' to fight!\n";

	//Calculations of alien and player hp
	while (alien_hp > 0 && player_hp > 0) {
	int attack1 = rand() % 10 + 1;
	int attack2 = rand() % 5 + 1;
		cout << "Player health: " << player_hp << endl; 
		cout << "Alien HP: " << alien_hp << endl;
		cin >> s;

	//Player battling alien. 	
		player_hp = player_hp - attack2;
		alien_hp = alien_hp - attack1;

		if (player_hp < 10) cout << "Your health is very low!\n";
	}
	//End of the match
	if (alien_hp <= 0) {
		player_hp = player_hp + 1; //Player's health increases after defeating ana alien.
		cout << "You have defeated the alien! Your HP is now: " << player_hp << endl;
		cout << "If you wish to continue the game, press 'a' to do so.\n";
	}
		turn_on_ncurses();
	
	}

	void space_sheep(int& player_hp ) {
		turn_off_ncurses();
		int space_sheep_hp = 1;
		char s;
		cout << "You have encountered the space sheep!\n";
		cout << "Press 'a' to roll the dice, and see if you can pass!\n";
		while (space_sheep_hp > 0) {
		int roll_1 = rand() % 6 + 1;
		int roll_2 = rand() % 6 + 1;
		cin >> s;
		//int roll_3 = rand() % 6 + 1;
		//int roll_4 = rand() % 6 + 1;
		//int roll_5 = rand() % 6 + 1;
		//int roll_6 = rand() % 6 + 1;

		if (roll_1 > roll_2) { 
			cout << "You have rolled a: " << roll_1 << ".\n"; 
			cout << "The space sheep has rolled a: " << roll_2 << ".\n";
			space_sheep_hp = 0;
			cout << "You have passed the space sheep!\n";
		if (roll_2 > roll_1) {
			cout << "You have rolled a: " << roll_1 << ".\n";
			cout << "The space sheep has rolled a: " << roll_2 << ".\n";
			cout << "The space sheep has defeated you! Try again!\n";
		}
		}
	}
	turn_on_ncurses();
	}

int main() {
	game_startup();
#ifndef MADE_USING_MAKEFILE
	static_assert(0, "Compile this code using 'make' not 'compile.");
#endif
	srand(time(0));
	hrc::time_point old_time = hrc::now(); //Get the current time
	turn_on_ncurses(); //Turn on full screen mode
	Map map;
	int x = Map::SIZE / 2, y = Map::SIZE / 2; //Start in middle of the world
	int player_hp = 100;
	while (true) {
		
		int ch = getch(); // Wait for user input, with TIMEOUT delay
		if (ch == 'q' || ch == 'Q') break;
		else if (ch == RIGHT) {
			x++;
			if (map.get(x,y) == Map::STARS) x--; //This is how you bounce
			if (x >= int(Map::SIZE)) x = Map::SIZE - 1; //Clamp value
		} else if (ch == LEFT) {
			x--;
			if (map.get(x,y) == Map::STARS) x++; //This is how you bounce
			if (x < 0) x = 0;
		} else if (ch == UP) {
			y--;
			if (map.get(x,y) == Map::STARS) y++; //This is how you bounce
			if (y < 0) y = 0;
		} else if (ch == DOWN) {
			y++;
			if (map.get(x,y) == Map::STARS) y--; //This is how you bounce
			if (y >= int(Map::SIZE)) y = Map::SIZE - 1; //Clamp value
		} else if (ch == ERR) { //No keystroke
			; //Do nothing
		}
		  if (map.get(x,y) == Map::ALIEN) alienbattle(player_hp);//Allows player to fight with the alien.
		if (map.get(x,y) == Map::SPACE_SHEEP) space_sheep(player_hp);//Allows player to challenge the space sheep.   


		//clear(); //Uncomment these lines if the code is drawing garbage
		map.set(x,y,Map::SPACESHIP);
		map.draw(x, y);
		mvprintw(Map::DISPLAY + 1, 0, "X: %i Y: %i\n", x, y);
		usleep(10000); //pause for 10000 us
		//refresh(); //Uncomment these lines if the code is drawing garbage
		hrc::time_point new_time = hrc::now();
		duration<double> time_span = duration_cast<duration<double>>(new_time - old_time);
		mvprintw(Map::DISPLAY + 2, 0, "FPS: %5.1f\n", 1 / time_span.count());
		old_time = new_time;
	
	}
	//Exit NCURSES
	turn_off_ncurses();
}
