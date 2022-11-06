#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
//Sharp & Walkup

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
//vector<vector<double>> type_system;

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
		int accuracy_temp;
		if (isdigit(accuracy.at(0))) accuracy_temp = stoi(accuracy);
		else continue;

		Move p = {index_temp, name, type, category, PP_temp, power_temp, accuracy_temp};
		if (power_temp != '—' && accuracy_temp != '—') { 
			movedex.push_back(p);
		}
	}
}

int main() {
	load_pokedex();
	load_movedex();

	//Now output all all of the data you loaded above.
	cout << "Loading pokemon from file . . .\n";
	for (auto x : pokedex) {
		cout << "Pokedex Entry " << x.index << ": " << x.name << " hp: " << x.hp << " attack: " << x.attack << " defense: " << x.defense << " speed: " << x.speed << " special: " << x.special << " type1: " << x.type1 << " type2: " << x.type2 << endl;
	}
	
	cout << "Loading moves from file . . .\n";
	for (auto x : movedex) {
		cout << "Move Index " << x.index << ": " << x.name << "  type: " << x.type << " category: " << x.category << " PP: " << x.PP << " power: " << x.power << " accuracy: " << x.accuracy << "%" << endl;
	}

	return 0;
}
