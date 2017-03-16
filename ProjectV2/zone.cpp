#include "libsqlite.hpp"
#include "zone.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Zone::Zone(string newName)
{
	name = newName;
}

string Zone::showName() const
{
	return name;
}

vector<string> Zone::showEnemies() const
{
	return enemies;
}

vector<string> Zone::showWeapons()
{
	return weapons;
}

string Zone::chooseWeapon()
{
	sqlite::sqlite db("project3.db");    // open database
    auto cur = db.get_statement();            // create query
    cur->set_sql( "SELECT NAME FROM weapon WHERE ZONE='" + name + "';");
    cur->prepare();                            // run query
    
    while(cur->step()){                    // loop over results
        weapons.push_back(cur->get_text(0));
    }
	
    system("clear");
    cout<<"\nYou have entered the "<< name<<"!\n\n";
    cout<<"Choose your weapon if you want to survive [letters]: \n\n";

    for (int i=0; i<weapons.size();i++){
        if (weapons[i]!=""){
            cout<<i+1<<" : "<<weapons[i]<<endl;
        }
    }
    string mystr;
    cout<<"\nChoose: ";
    cin>>mystr;
    bool fail=true;
    while(fail==true) {
		for (int i=0;i<weapons.size();i++){
			if (mystr == weapons[i]){
				fail=false;
			}
		}
		if (fail==true){
			cout<<"Wrong input. Try again.\n";
            cout<<"Choose: ";
        	cin>>mystr;	
		}
    }
	return mystr;
}

vector<string> Zone::retrieveEnemies()
{
	sqlite::sqlite db("project3.db");
	auto cur = db.get_statement();
    cur->set_sql( "SELECT ENEMY_ID FROM enemy WHERE ZONE='" + name + "';");
    cur->prepare();
	
    while(cur->step()){                    // loop over results
        enemies.push_back(cur->get_text(0));
    }

    system("clear");
    cout << "Now use that weapon and kill the ";
	for (int i=0;i<enemies.size();i++){
		cout<<enemies[i]<<", ";
	}
	cout<<"!!!\n\n";
	
	return enemies;    //returns possible enemies
}


