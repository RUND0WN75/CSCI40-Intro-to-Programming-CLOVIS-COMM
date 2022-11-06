#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Walkup & Sharp

void die(string s = "INVALID INPUT!") {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

//YOU: Make a class to describe a single Pokémon
class Pokemon {
	public:
		int index, hp, attack, defense, speed, special;
		string type1, type2, name;
		Pokemon (int index_2 = 0, string name_2 = "", int hp_2 = 0, int attack_2 = 0, int defense_2 = 0, int speed_2 = 0, int special_2 = 0, string type1_2 = "", string type2_2 = "") {
			index = index_2;
			name = name_2;
			hp = hp_2;
			attack = attack_2;
			defense = defense_2;
			speed = speed_2;
			special = special_2;
			type1 = type1_2;
			type2 = type2_2;
		}
};

//YOU: Make a class to describe a single Move
class Move {
	public:
		int index, PP, power, accuracy;
		string name, type, category;
		Move (int index_2 = 0, string name_2 = "", string type_2 = "", string category_2 = "", int PP_2 = 0, int power_2 = 0, int accuracy_2 = 0) {
			index = index_2;
			name = name_2;
			type = type_2;
			category = category_2;
			PP = PP_2;
			power = power_2;
			accuracy = accuracy_2;
		}
};

//These vectors will hold all of the data you loaded from the files
vector<Pokemon> pokedex;
vector<Move> movedex;

//YOU: Load all the data for Pokémon from two files, usually pokemon.txt and types.txt
//Make sure you use the class you made above 
void load_pokedex() {
	ifstream ins("pokemon.txt");
	while (ins) {
		//Reads in one line at a time. 
		string s;
		getline(ins, s);
		if (!ins) break;
		stringstream sts(s);

		//Takes in an index #
		string index;
		getline(sts, index, '\t');
		int index_temp;
		if (isdigit(index.at(0))) index_temp = stoi(index);
		else continue;

		//Takes in a name
		string name;
		getline(sts, name, '\t');

		//Takes in HP
		string hp;
		getline(sts, hp, '\t');
		int hp_temp;
		if (isdigit(hp.at(0))) hp_temp = stoi(hp);
		else continue;

		//Takes in attack
		string attack;
		getline(sts, attack, '\t');
		int attack_temp;
		if (isdigit(attack.at(0))) attack_temp = stoi(attack);
		else continue;

		//Takes in defense
		string defense;
		getline(sts, defense, '\t');
		int defense_temp;
		if (isdigit(defense.at(0))) defense_temp = stoi(defense);
		else continue;

		//Takes in speed
		string speed;
		getline(sts, speed, '\t');
		int speed_temp;
		if (isdigit(index.at(0))) speed_temp = stoi(speed);
		else continue;

		//Takes in special
		string special;
		getline(sts, special, '\t');
		int special_temp;
		if (isdigit(special.at(0))) special_temp = stoi(special);
		else continue;

		Pokemon p = {index_temp, name, hp_temp, attack_temp, defense_temp, speed_temp, special_temp};
		pokedex.push_back(p);
	}

	//Reads and takes in types for pokemon
	ifstream ins2("types.txt");
	int count = 0;
	while (ins2) {
		if (count > 150) break;
		string s;
		getline(ins2, s);
		if (!ins2) break;
		stringstream sts(s);

		string ph;
		getline(sts, ph, '\t');

		string ph2;
		getline(sts, ph2, '\t');

		string type1;
		getline(sts, type1, '\t');
		pokedex.at(count).type1 = type1;

		string type2;
		getline(sts, type2, '\t');
		pokedex.at(count).type2 = type2;
		count++;
	}
}

void print_battle(Pokemon one, Pokemon two){
	system("clear");
			cout << one.name << " stats: HP- " << one.hp << " Damage done- " << one.attack << endl;
			cout << two.name << " stats: HP- " << two.hp << " Damage done- " << two.attack << endl;
}

int lookup_type(string s) {
	if (s == "Normal") return 0;
	else if (s == "Fighting") return 1;
	else if (s == "Flying") return 2;
	else if (s == "Poison") return 3;
	else if (s == "Ground") return 4;
	else if (s == "Rock") return 5;
	else if (s == "Bug") return 6;
	else if (s == "Ghost") return 7;
	else if (s == "Steel") return 8;
	else if (s == "Fire") return 9;
	else if (s == "Water") return 10;
	else if (s == "Grass") return 11;
	else if (s == "Electric") return 12;
	else if (s == "Psychic") return 13;
	else if (s == "Ice") return 14;
	else if (s == "Dragon") return 15;
	else if (s == "Dark") return 16;
	else if (s == "Fairy") return 17;
	else return -1;
}

//YOU: Do the same, but for the move database
void load_movedex() {

	//Reads one line at a time
	ifstream ins("moves.txt");
	while (ins) {
		string s;
		getline(ins, s);
		if (!ins) break;
		stringstream sts(s);

		//Takes in index #
		string index;
		getline(sts, index, '\t');
		int index_temp;
		if (isdigit(index.at(0))) index_temp = stoi(index);
		else continue;

		//Takes in name
		string name;
		getline(sts, name, '\t');

		//Takes in type
		string type;
		getline(sts, type, '\t');

		//Takes in category
		string category;
		getline(sts, category, '\t');

		//Takes in PP
		string PP;
		getline(sts, PP, '\t');
		int PP_temp;
		if (isdigit(PP.at(0))) PP_temp = stoi(PP);
		else continue;

		//Takes in power
		string power;
		getline(sts, power, '\t');
		int power_temp;
		if (isdigit(power.at(0))) power_temp = stoi(power);
		else continue;

		//Takes in accuracy
		string accuracy;
		getline(sts, accuracy, '\t');
		int accuracy_temp = -1;
		if (isdigit(accuracy.at(0))) accuracy_temp = stoi(accuracy);
		else continue;

		Move p = {index_temp, name, type, category, PP_temp, power_temp, accuracy_temp};
		movedex.push_back(p);
	}
}
vector<vector<float>> type_system;
void load_types(){
	ifstream ins("type_system.txt");
	int count = 0;
	while (ins) {
		vector<float>temp3;
		string s, temp;
		getline(ins, s);
		if (!ins) break;
		stringstream sts(s);
		while(sts){
		getline(sts, temp, '\t');
		float temp2 = 0;
		if (isdigit(temp.at(0))) temp2 = stof(temp);
		temp3.push_back(temp2);
		}
		type_system.push_back(temp3);
	}
}
int main() {
	load_pokedex();
	load_movedex();
	load_types();

	//Random number generator for deciding which pokemon will battle first
	srand(time(NULL));
	//Now output all all of the data you loaded above.
	/*
	   cout << "Loading pokemon from file . . .\n";
	   for (auto x : pokedex) {
	   cout << "Pokedex Entry " << x.index << ": " << x.name << " hp: " << x.hp << " attack: " << x.attack << " defense: " << x.defense << " speed: " << x.speed << " special: " << x.special << " type1: " << x.type1 << " type2: " << x.type2 << endl;
	   }

	   cout << "Loading moves from file . . .\n";
	   cout << "Move Index " << x.index << ": " << x.name << "  type: " << x.type << " category: " << x.category << " PP: " << x.PP << " power: " << x.power << " accuracy: " << x.accuracy << "%" << endl;
	   */



	//DO NOT EDIT ANYTHING ABOVE HERE	

	//----POKEMON BATTLING----



	
	//Intro to the game - DONE
	cout << endl;
	cout << "Welcome to Pokemon!\n"; 
	cout << endl;
	cout << "Please select two pokemon to battle by inputting any two index numbers between 1 to 151: \n";
	int Pokemon1 = 0, Pokemon2 = 0;
	cin >> Pokemon1 >> Pokemon2;
	Pokemon poke1, poke2; //Storing the names of the two pokemon into class objects. 
	//Vetting user input. 
	if (!cin || Pokemon1 < 1 || Pokemon1 > 151 || Pokemon2 < 1 || Pokemon2 > 151) die();
	cout << endl;
	//Outputting what pokemon the user has chosen after inputting two index numbers. 
	cout << "You have chosen:" << endl;
	poke1 = pokedex.at(Pokemon1 - 1); 
	poke2 = pokedex.at(Pokemon2 - 1);
	cout << poke1.name << endl;
	cout << poke2.name << endl;
	//Output what the user has chosen, end each part w/ endline.
	cout << endl;


	//Allowing the user to select four moves for each pokemon - DONE
	const int MAX_moves = 4;
	vector<Move> Pokemon1_moves, Pokemon2_moves; //Stores the four pokemon moves.
	cout << "Select four moves for " << pokedex.at(Pokemon1 - 1).name << " by any index number between 1 to 151. Do not use the sane number twice!\n"; //Pokemon 1
	for (int i = 0; i < MAX_moves; i++) {
		int temp = 0;
		cin >> temp;
		for (Move m : movedex) {
			if (m.index == temp) {
				Pokemon1_moves.push_back(m);
			}
		}
	}
	if (Pokemon1_moves.size() == 0) {
		for (Move m : movedex) {
			if (m.name == "Struggle") {
				Pokemon1_moves.push_back(m);
			}
		}
	}
	cout << endl;
	
	cout << "Select four moves for " << pokedex.at(Pokemon2 - 1).name << " by any index number between 1 to 151. Do not use the same number twice!\n"; //Pokemon 2
	for (int i = 0; i < MAX_moves; i++) {
		int temp = 0;
		cin >> temp;	
		//Need to vet the input, assign the move 'struggle' to the pokemon if the user doesn't select a move. - DONE
		for (Move m : movedex) {
			if (m.index == temp) {
				Pokemon2_moves.push_back(m);
			}
		}
	}
	if (Pokemon2_moves.size() == 0) {
		for (Move m : movedex) {
			if (m.name == "Struggle") {
				Pokemon2_moves.push_back(m);
			}
		}
	}


	//Deciding which pokemon will go first, based on speed. Highest speed goes first. If both speeds are the same, do a coin flip using the rand(). - DONE 
	//Pokemon speed;
	int random = 0;
	bool p1turn = true;
	if (poke1.speed > poke2.speed) {
		p1turn = true;
	}
	if (poke1.speed < poke2.speed) {
		p1turn = false;
	}
	if (poke1.speed == poke2.speed) {
		random == rand() % 2;
		p1turn = random;
	}

	cout << endl;


	//Allows user to select a move for the active pokemon.
	//The user's active pokemon will be the one with the highest speed, or whichever wins the coin toss. 
	double STAB = 1;	
	//Output the active pokemon and the list of moves for the pokemon to choose from. 
	string name = "";
	if (p1turn) name = poke1.name;
	else name = poke2.name;
	cout << "To begin the battle, select a move for " << name << ". Here are your options:\n";
		cin.clear();
		cin.ignore(5000,'\n');
	//Checking to make sure there's no case sensitivity. 
	auto vec2 = movedex;
	for (int i = 0; i < vec2.size();i++){
		for(int j = 0; j < vec2.at(i).name.size(); j++){
			vec2.at(i).name.at(j) = toupper(vec2.at(i).name.at(j));
			cout<<vec2.at(i).name.at(j);
		}
	}
	cout << endl;

	while (poke1.hp > 0 && poke2.hp > 0) {
		//Player 1 turn's to attack. 
		print_battle(poke1,poke2);
		if (p1turn == true) {
			string temp;
			Move temp1;
			//Output list of moves.
			for (auto c : Pokemon1_moves) {
				cout << c.name << endl;
			}
			getline(cin, temp);
			for (int i = 0; i < temp.size(); i++)
				temp.at(i) =toupper(temp.at(i));
			for (auto c : vec2) {
				if (c.name == temp) {
					temp1 = c;
					break;
				}
			}
			//If the user inputs a move that matches the type of pokemon they have, STAB is activated. 
			if (poke1.type1 == Pokemon1_moves.at(0).type || poke1.type2 == Pokemon1_moves.at(0).type) {
				STAB = 1.5;
			}

			poke2.hp -= (temp1.power * poke1.attack)/poke2.defense * STAB * type_system.at(lookup_type(temp1.type)).at(lookup_type(poke2.type1));
			print_battle(poke1,poke2);
			cout << endl;
			temp1.PP--;
			p1turn = false;
		}

		//Player 2's turn to attack. 
		else if (p1turn == false) {
			string temp;
			Move temp2;
			for (auto c : Pokemon2_moves) {
				cout << c.name << endl;
			}
			getline(cin, temp);
			for (int i = 0; i < temp.size(); i++)
				temp.at(i) =toupper(temp.at(i));
			for (auto c : vec2) {
				cout<<c.name<<endl;
				if (c.name == temp) {
					temp2 = c;
					break;
				}
			}
			poke1.hp -= (temp2.power * poke2.attack)/poke1.defense * STAB * type_system.at(lookup_type(temp2.type)).at(lookup_type(poke1.type2));
			print_battle(poke1,poke2);
			cout << endl;
			temp2.PP--;
			p1turn = true;
		}
		if (poke1.hp <= 0) {
			cout << "Game over!\n";
			cout << endl;
			cout << "Winner: " << poke2.name << endl;
			cout << "Loser: " << poke1.name << endl;
			break;
		}
		else if (poke2.hp <= 0) {
			cout << "Game over!\n";
			cout << endl;
			cout << "Winner: " << poke1.name << endl;
			cout << "Loser: " << poke2.name << endl;
			break;
		}
	}
	
	cout << endl;
	return 0;
}

