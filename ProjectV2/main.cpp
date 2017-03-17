#include <iostream>
#include <vector>
#include <algorithm>
#include "player.hpp"
#include "enemy.hpp"
#include "zone.hpp"
#include "libsqlite.hpp"

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

int userChoice(vector<string> options)
{
	int userOutput;
	for (int i=0;i<options.size();i++)
	{
		cout<<i+1<<" : "<<options[i]<<endl;
	}
	cout<<"\nEnter: ";
	cin>>userOutput;
	cout<<userOutput<<endl;
	return userOutput;
}

vector<string> userAuthentication()
{
    system("clear");
	string name;
	cout << "What's your name?\n\n";
	cout << "Enter: ";
	cin>>name;
	cout << "Choose your gender: "<<endl;
	vector<string> options ={"Male", "Female"};
	int output = userChoice(options);
	vector<string> user = {name, options[output-1]};
	return user;
}

void gameOver()
{
	system("clear");
	cout<<"GAME OVER\nYou couldn't defeat all monsters"<<endl;
	cout<<"Press enter key to exit"<<endl;
	system("read");
	exit(0);
}

int printAllStatus(Player* p1, Enemy* e1)
{
	vector<string> playerStatus = p1->checkStatus();
	vector<string> enemyStatus = e1->checkStatus();
	system("clear");
	cout<<"Player's Name: "<<playerStatus[0]<<endl;
	cout<<"Player's Gender: "<<playerStatus[1]<<endl;
	cout<<"Player's HP: "<<playerStatus[2]<<endl;
	cout<<"Player's Weapon: "<<playerStatus[3]<<endl;
	cout<<"Player's Attack: "<<playerStatus[4]<<endl;
	cout<<"Player's Inventory: ";
	vector<string> inventory=p1->showInventory();
	for(string i:inventory){
		cout<<" "<<i;
	}

	cout<<"\n\nEnemy's Name: "<<enemyStatus[0]<<endl;
	cout<<"Enemy's HP: "<<enemyStatus[1]<<endl;
	cout<<"Enemy's Attack: "<<enemyStatus[2]<<"\n\n";
	
	vector<string> options = {"Continue Battle", "Quit", "Sort Inventory"};
	int userOutput = userChoice(options);
	userOutput-=1;
	if (userOutput == 2){
		p1->sortInventory();
	}
	system("clear");
	return userOutput;
}

string retrieveFromDatabase(string column, string table, string whereColumn, string condition)
{
	string output;
	sqlite::sqlite db("project3.db");    // open database
	auto cur = db.get_statement();            // create query
    cur->set_sql( "SELECT " + column + " FROM " + table + " WHERE " + whereColumn + "='" + condition + "';");
    cur->prepare();                            // run query
    while(cur->step()){                    // loop over results
        output=cur->get_text(0);
	}
	
	return output;
}

vector<Enemy*> retrieveEnemy(vector<string> enemies)
{
	vector<Enemy*> enemyObjects;
	string hp, attack;
	int hpInt, attackInt;
	Enemy* e1;
	for (int i=0; i<enemies.size();i++){
		hp = retrieveFromDatabase("ENEMY_HP","enemy","ENEMY_ID",enemies[i]);
		attack = retrieveFromDatabase("ENEMY_ATK", "enemy", "ENEMY_ID", enemies[i]);

		hpInt=stoi(hp);
		attackInt=stoi(attack);

		e1 = new Enemy(enemies[i], hpInt, attackInt);
		enemyObjects.push_back(e1);
	}
	
	return enemyObjects;
}


string battle(Player* p1, vector<Enemy*> enemyObjects)
{
	string winner;
	string turn = "player";
	string input;
	for (int i=0; i<enemyObjects.size();i++){
		cout<<"You are facing a "<<enemyObjects[i]->showName();
		cout<<"[Atk:"<<enemyObjects[i]->showAttack()<<", HP:"<<enemyObjects[i]->showHP()<<"]"<<endl;
		while (p1->showHP() >0 && enemyObjects[i]->showHP()>0){
			if (turn == "player"){
				cout<<"It's your turn! Choose one of the options!\n0: Check Status\n1: Attack\n2: Heal\n3: Surrender\n";
				cout<<"Choose: ";
				cin>>input;
				if (input=="0" || input=="Check"){
					int statusOutput = printAllStatus(p1, enemyObjects[i]);
					while (statusOutput == 2){
						statusOutput = printAllStatus(p1, enemyObjects[i]);
					}
					if (statusOutput == 0){
						continue;
					}
					else if (statusOutput == 1){
						winner="enemy";
						return winner;
					}
				}
				else if (input=="1" || input=="Attack"){
					enemyObjects[i]->decreaseHP(p1->showAttack());
					cout<<"Enemy HP is now: "<<enemyObjects[i]->showHP()<<endl;
				}
				else if (input=="2" || input=="Heal"){
					p1->increaseHP(10);
					cout<<"Your HP is now: "<<p1->showHP()<<endl;
				}
				else if (input=="3" || input=="Surrender"){
					winner="enemy";
					return winner;
				}
				turn="enemy";
			}
			else if (turn == "enemy"){
				cout<<"\nIt's enemy's turn!"<<endl;
				cout<<"The enemy decided to attack"<<endl;
				p1->decreaseHP(enemyObjects[i]->showAttack());
				cout<<"Your HP is now: "<<p1->showHP()<<endl;
				turn="player";

				cout<<"\nPress enter to continue"<<endl;
				system("read");
				system("clear");
			}

			if (p1->showHP()<=0){
				winner="enemy";
			}
			else if (enemyObjects[i]->showHP()<=0){
				winner=="player";
			}
		}
		system("clear");
		cout<<"Well done you just defeated the "<<enemyObjects[i]->showName()<<"\n\n";
	}
	
	return winner;
}

int main(int argc, char* argv[])
{
	mainMenu();
		
	vector<string> user = userAuthentication();
    system("clear");
    cout << "Hello\n\n";
	Player *p1 = new Player(user[0], 25, "None", user[1], 0);

	vector<string> options = {"Bedroom", "Entrance", "Hallway", "Kitchen", "Study"};
	int length = 4;
	

	while (length>=0 && options[0]!="")
	{
		cout << "Where do you want to enter "<<p1->showName()<<"?"<<".\n";
		
		int userOutput=-1;
		string output;
		while (userOutput-1<0 || userOutput-1>options.size()){
			userOutput = userChoice(options);
			if (userOutput-1>=0 && userOutput-1< options.size()){
				output = options[userOutput-1];
			}
			else{
				cout<<"Wrong input. Try again! (insert numbers)"<<endl;
			}
		}
		Zone z1(output);
		string weapon = z1.chooseWeapon();
		p1->pickWeapon(weapon);
		p1->addToInventory(weapon);
		p1->setAttack(10);
		vector<string> enemies = z1.retrieveEnemies();
		vector <Enemy*> enemyObjects = retrieveEnemy(enemies);
		string winner = battle(p1, enemyObjects);
		
		if (winner == "enemy"){
			gameOver();
		}

		cout<<"Congratulations! You passed this stage.\nNow enter another one.\n\n";

		options.erase(std::remove(options.begin(), options.end(), output), options.end());
		length--;
	}
	system("clear");
	cout<<"Well. It seems that you defeated all monsters."<<endl;
	cout<<"Well done!"<<endl;
	cout<<"Press enter to exit";
	system("read");
	return 0;
}