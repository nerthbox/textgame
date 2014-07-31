#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <cstdlib>

using namespace std;
// Classes

// Holds Players base information
class playerInfo{
private:
	int
	level,
		xp,
		xp2LvlUp;
	
public:
	string 
	name;
	playerInfo();
	void getName();
	void init();
	void displayInfo();
	void updateStats(int);
	int getXP();
};

// Holds HP, multi etc info
class playerRace{
private:
	int
	hp;
public:
	int 
	multi;
	string 
	raceName;
	playerRace();
	void setRace(int,int,int);
	void changeHP(int);
	int multiply(int);
	void displayStats();
	int getHP();
};


playerInfo::playerInfo()
{
	level = 0;
	xp = 0;
	xp2LvlUp = 0;
	name = "";
}


int playerInfo::getXP(){
	return xp;
}


void playerInfo::getName(){
	char buffer[80] = {0};
	cout << "\nWhat is your name?: ";
	cin.getline(buffer, 80);
	name = buffer;
}

void playerInfo::init(){
	level = 0;
	xp = 0;
	xp2LvlUp = 10;
}

void playerInfo::displayInfo(){
	cout<<endl<<"\tPlayer Name: "<<name<<endl
		<<"\tLevel: "<<level<<endl
		<<"\tXP: "<<xp<<endl<<
		"\txp2LevelUp: "<<xp2LvlUp<<endl<<endl;
}

void playerInfo::updateStats(int xpGained){
	xp += xpGained;
	if(xp >= xp2LvlUp){
		level++;
		xp2LvlUp = level * 100;
		sleep(1);
		cout << "\t\t\t\tLevel Up!!!!"<< endl;
		sleep(1);
	}
}

playerRace::playerRace(){
	hp = 0;
	multi = 1;
}

void playerRace::setRace(int hpSet, int multiSet, int type){
	hp= hpSet;
	multi = multiSet;
	switch(type){
	case 1:
		raceName = "Neuromancer";
		break;
	case 2:
		raceName = "Cyber Warlard";
		break;
	case 3:
		raceName = "High-Tech Archeologist";
		break;
	default:
		cout<<"ERROR"<<endl;
		break;
	}
}

void playerRace::changeHP(int change){
	hp += change;
}

int playerRace::multiply(int value){
	value = value * multi;
	return multi;
}

void playerRace::displayStats(){
	cout
		<<"\tRace: "<<raceName<<endl
		<<"\tHP: " <<hp<<endl
		<<"\tSpecial: "<<multi<<endl;
}

int playerRace::getHP(){
	return hp;
}

void mainMenu();
char userMenuChoice(char&);
bool sceneOne(playerInfo&, playerRace&);
bool sceneOneAct1(playerInfo&, playerRace&);
bool sceneOneAct2(playerInfo&, playerRace&);

int main(){
	playerInfo player1;
	playerRace player1Stats;
	bool end = 0;
	mainMenu();
	player1.getName();
	player1.init();
	player1.displayInfo();
	do{
		end = sceneOne(player1,  player1Stats);
	}while(end == 0);
	do{
		end = sceneOneAct1(player1, player1Stats);
	}while(end == 0);
	do{
		end = sceneOneAct2(player1, player1Stats);
	}while(end == 0);
	sleep(15);
	cout << "\n\n\n\n\n\n\n\nTEST DATA"<<endl;
	player1.displayInfo();
	player1Stats.displayStats();
	return 0;
}

void mainMenu(){
	char 
		buffer[80] = {0},
		answer = ' ';
		cout << "\n\n\t\t\t\t   Hello!!\n\t\t\n\n\n"
			"Do you want to play a game?(yes/no): ";
		do{
			answer = userMenuChoice(answer);
			if(answer != 'N' && answer != 'Y')
				cout << "Please Make a Valid Selection"<<endl;
		}while(answer != 'N' && answer != 'Y');
		if(answer == 'N')
			cout << "\t\t\t   GoodBye!!" << endl;
}

char userMenuChoice(char& answer){
	char 
		buffer[80] = {0};
	cin.getline(buffer, 80);
	answer = toupper(buffer[0]);
	return answer;
}

bool sceneOne(playerInfo& player, playerRace& playerStats){
	char answer = ' ';
	bool end = 0;
	cout<<"\nYou Made It To Scene1!!!\n\nHere is a free RARE CANDY"<<endl;
	cout<< "\nWhat would you like to do?(take/leave): ";
	do{
		answer = userMenuChoice(answer);
	}while(answer != 'T' && answer != 'L');
	if(answer == 'T'){
		srand(time(NULL));
		int random = rand();
		int xpGain = (random % 10) + 3;
		player.updateStats(xpGain);
		end = 1;
	}
	else
		end = 0;
	return end;
}

bool sceneOneAct1(playerInfo& player, playerRace& playerStats){
	char answer = ' ';
	bool end = 0;
	int xpGain = 0;
	cout 
		<< "\n\t\tIt's the year 3030"<<endl
		<< "\t\tAnd hear at the Corporate,\n" 
		"\t\tInstutional Bank of Time,\n"
		"\t\tWe find ourselves, reflecting!\n"
		"\t\tFinding out...\n"
		"\t\tThat in fact...\n"
		"\t\tWe came back!\n"
		"\t\tWe were always coming back!!!\n"
		"Computer: \n"
		"\t\tWelcome to consciousness...\n"
		"\t\t...\n"
		"\t\t...\n"
		"\t\t...\n"
		"\t\tI want you to meet DeltronZero\n"
		"\t\tHe Is a Hero, and your commander...\n"
		"DeltronZero: \n"
		"\t\tIt's all heat in this day and age\n"
		"\t\tI rage your grave, anything it takes\n"
		"\t\tto save the day...\n";
	do{
		cout<<
			"Pick a race:\n"
			"\tNeuromancer: Perfect blend of technology and magic\n"
			"\tCyber Warlord: Activating abominations to arm a nation with hatred\n"
			"\tHigh-Tech Archeologist: searching for nicknacks composing music"<<endl;
		do{
			cout << "Race: ";
			answer = userMenuChoice(answer);
			if(answer != 'N' && answer != 'C' && answer != 'H'){
				cout<<"Pick a race:"<<endl;
			}
		}while(answer != 'N' && answer != 'C' && answer != 'H');

		switch(answer){
		case 'N':
			playerStats.setRace(150, 2, 1);
			break;
		case 'C':
			playerStats.setRace(75, 3, 2);
			break;
		case 'H':
			playerStats.setRace(50, 5, 3);
			break;
		default:
			cout<<"ERROR"<<endl;
			break;
		}
		cout
			<<"Computer:\n"
			"\t\tYour Race is: " << playerStats.raceName<<endl
			<<"\t\tYour current stats are: "<<endl;
		player.displayInfo();
		playerStats.displayStats();
		cout<<"\t\tIs this Ok?(yes/no)"<<endl;
		answer = userMenuChoice(answer);
	}while(answer != 'Y');
	xpGain = playerStats.multiply(player.getXP());
	player.updateStats(xpGain);
	end = 1;
	return end;
}

bool sceneOneAct2(playerInfo& player, playerRace& playerStats){
	int xpGain = 0;
	cout
		<<
		"\nDeltronZero:\n"
		"\t\tI used to be a mech soldier but I didn't respect orders\n"
		"\t\tI had to step forward, tell them this ain't for us\n"
		"\t\tLiving in a post-apocalyptic world morbid and horrid\n"
		"\t\tThe secrets of the past they hoarded\n"
		"\t\tNow we just boarded on a futuristic spacecraft\n"
		"\t\tNo mistakes black it's our music we must take back"<<endl<<
		player.name << ": \n"<<endl;
	cout
		<<
		"\t\tI'm feeling like a ghost in a shell\n"
		"\t\tI wrote this in jail playing host to a cell\n"
"\t\tFor the pure verbal,\n"
"\t\tthey said my sentence was equivalent to murder\n"
<<endl
<<
"\n**Your ears Turned Into Recepters, you can now listen to thoughts"
<<endl
<<
"\n**The Walls shake, the police are here for you**\n"
<<player.name<<"(thoughts):\n"
"\t\tEvery word about gravity control \n"
"\t\tand the families they hold for handsome ransoms\n"
"\t\tOn the run with a handgun, blast bioforms; I am warned\n"
"\t\tthat a planet-wise manhunt with cannons\n"
"\t\twill make me, abandon, my foolish plan of uprisin\n"
"****BREAK***WAIT**FOR***STATS*********";

xpGain = playerStats.multiply(player.getXP());
player.updateStats(xpGain);
return 1;
}
