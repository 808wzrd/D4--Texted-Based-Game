#include "libsqlite.hpp"
#include "zone.hpp"
#include <iostream>
#include <string>

using namespace std;

Zone::Zone(string newName, string* newEnemies)
{
	name = newName;
	enemies = newEnemies;   //??????
}

string Zone::showName() const
{
	return name;
}

string* Zone::showEnemies() const
{
	return enemies;
}

void Zone::run()
{
	sqlite::sqlite db("project3.db");    // open database
    auto cur = db.get_statement();            // create query
    cur->set_sql( "SELECT NAME FROM weapon WHERE ZONE='" + name + "';");
    cur->prepare();                            // run query
    string weapons[10];
    int i=0;
    while(cur->step()){                    // loop over results
        weapons[i]=cur->get_text(0);
        i++;
    }
    system("clear");
    cout<<"You have entered the "<< name<<endl;
    cout<<"Choose your weapon if you want to survive [letters]: \n";
    i=0;
    for (const string &weapon : weapons){
        if (weapon!=""){
            //cout<<i+1<<": "<<weapon<<endl;
            cout<<weapon<<endl;
            i++;
        }
    }
    string mystr;
    cin>>mystr;
    bool fail=true;
    while(fail==true) {
        if (mystr == weapons[0] || mystr == weapons[1]) {
            fail=false;

        }
        else{
            cout<<"Wrong input. Try again.\n";
            cin>>mystr;
        }
    }

    cur = db.get_statement();
    cur->set_sql( "SELECT ENEMY_ID FROM enemy WHERE ZONE='" + name + "';");
    cur->prepare();
    string enemies[10];
    i=0;
    while(cur->step()){                    // loop over results
        enemies[i]=cur->get_text(0);
        i++;
        cout<<cur->get_text(0)<<endl;
    }

    system("clear");
    cout << "Now use that " << mystr << " and kill the " << enemies[0] <<"!!!" << ".\n";


}










