#include <iostream>
#include <vector>
#include <algorithm>
#include "player.hpp"
#include "enemy.hpp"
#include "zone.hpp"
#include "libsqlite.hpp"                    // sqlite library

using namespace std;

void mainMenu()
{
	system("clear");
    string mystr;
    cout << "\n Welcome!" << endl;
    cout << "\n 1. Play" << endl;
    cout << "\n 2. Exit" << endl;
    cout << "\n> ";
	bool exitLoop=false;
    while (exitLoop==false){
        cin >> mystr;
        if (mystr=="1"){
            exitLoop=true;
        }
        else if (mystr=="2"){
            exitLoop=true;
            exit(0);
        }
        else{
            cout<<"Invalid input. Try again!";
        }
    }
}

string userAuthenticaiton()
{
    system("clear");
	string mystr;
	cout << "What's your name? "<<".\n";
    cin>>mystr;
	return mystr;
}

void playerStatus(Player player)
{
	cout<<"Name: ?? \nHP: ??\nWeapon: ?? \nAttack: ??";
}

void enemyStatus(Enemy enemy)
{
	cout<<"Name: ??\nHP: ??\n";
}

void attackEnemy(Player player, Enemy enemy)
{
	int attack;
	attack=player.showAttack(); //????
	enemy.decreaseHP(attack);
}
	
int userChoice(vector<string> options)
{
	int userOutput;
	for (int i=0;i<options.size();i++)
	{
		cout<<i+1<<" : "<<options[i]<<endl;
	}
	cin>>userOutput;
	cout<<userOutput<<endl;
	return userOutput;
}

int main(int argc, char* argv[])
{
	mainMenu();
		
	string name;
	name = userAuthenticaiton();
    system("clear");
    cout << "Hello " << name << ".\n";
	Player *p1 = new Player(name, 100, "Axe", "Male", 15);
	
	cout << "Where do you want to enter "<<p1->showName()<<"?"<<".\n";
	vector <string> options = {"Bedroom", "Entrance", "Hallway", "Kitchen", "Study"};
	int length = 4;

	int userOutput=-1;
	string output;
	while (userOutput-1<0 || userOutput-1>options.size())
	{
		userOutput = userChoice(options);
		if (userOutput-1>=0 && userOutput-1< options.size())
		{
			output = options[userOutput-1];
		}
		else
		{
			cout<<"Wrong input. Try again! (insert numbers)"<<endl;
		}
	}
	string enemies[]={"zombie","vampire"};    //fixxxxxxxx
	Zone z1(output,enemies);
	z1.run();
	
	cout<<"Congratulations! You passed this stage.\n Now enter another one."<<endl;
	//options= options - userOutput; // ??????? check that

    options.erase(std::remove(options.begin(), options.end(), output), options.end());

	cout << "Where do you want to go next "<<p1->showName()<<"?"<<".\n";
    userOutput=-1;
	while (userOutput-1<0 || userOutput-1 >= options.size())
	{
		userOutput = userChoice(options);
		if (userOutput>0 && userOutput<sizeof(options))
		{
			output = options[userOutput-1];
		}
		else
		{
			cout<<"Wrong input. Try again! (insert numbers)"<<endl;
		}
	}
	string enemies2[]={"rat","dog"};
	Zone z2(output,enemies2);
	z2.run();
	
	cout<<"Well done! You killed all monsters.\n Now its time for the final one."<<endl;
	string enemies3[]={"boss"};
	Zone z6("final",enemies3);
	z6.run();
	
	cout<<"Well done! You passed all levels.\n";
	cout<<"Press any key to exit";
	string exit;
	cin>>exit;
	return 0;
}













