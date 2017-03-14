#include "libsqlite.hpp"                    // sqlite library
#include <iostream>
#include <string>
using namespace std;

/*class Menu
{
public:
    Menu(const string &name, const string &prompt, 
        const std::vector<std::pair<string, string> > &choices 
        = std::vector<std::pair<string, string> >{});
    virtual ~Menu();
    const string& getChoice() const;
    bool operator==(const string &name) const;
private:
    static const string menuend;
    string _name, _prompt;
    std::vector<std::pair<string, string> > _choices;
    
    
};*/
sqlite::sqlite db("project.db");    // open database
    
void Bedroom(string mystr)
{
    sqlite::sqlite db("project.db");    // open database
    auto cur = db.get_statement();            // create query
    cur->set_sql( "SELECT WEAPON FROM zone WHERE zone_id='Bedroom';" );
    cur->prepare();                            // run query
    string weapons[10];
    int i=0;  
    while( cur->step() ){                    // loop over results
        cout << cur->get_int(0) << " " << cur->get_text(0) << endl;
        weapons[i]=cur->get_text(0);
        i++;
    }
    cout<<"You have entered the Bedroom\n";
    cout<<"Choose your weapon if you want to survive: \n 1: Broom \n 2: Desk Lamp \n";
    
    cin>>mystr;
    if (mystr=="Broom"|| mystr=="Desk Lamp"){
        cout<<"Now use that "<<mystr<<" and kill those weakened zombies!!!"<<".\n";
    }
};

void Entrance(string mystr)
{
    cout<<"Chose Your weapon..Flash light..That if you want to survive :)"<<".\n";
    cin>> mystr;
    if(mystr=="Flash light")
    cout<<"Now use that "<<mystr<<" and kill the Zombie General!!!"<<".\n";
    
};
void Hallway(string mystr)
{
    cout << "Connected to database\n";
    auto cur = db.get_statement();            // create query
    cur->set_sql("SELECT WEAPON FROM zone WHERE zone_id='Hallway';");
    cur->prepare();                            // run query
    
    string weapons[10];
    int i=0;
    
    while( cur->step() ){                    // loop over results
        weapons[i]=cur->get_text(0);
        cout << cur->get_int(0) << " " << cur->get_text(0) << endl;
        i++;
    }
    
    cout<<"Chose Your weapon..Fire Extinguisher,Picture Frame,Vase..That if you want to survive :)"<<".\n";
    cin>> mystr;
    if(mystr=="Fire Extinguisher"||"Picture Frame"||"Vase")
    cout<<"Now use that "<<mystr<<" and kill those Rats!!!"<<".\n";
};

void Kitchen(string mystr)
{
    cout<<"Chose Your weapon..Knife,Frying pan..That if you want to survive :)"<<".\n";
    cin>> mystr;
    if(mystr=="Knife"||"Frying pan")
    cout<<"Now use that "<<mystr<<" and kill that Zombie elite!!!"<<".\n";
};

void Study(string mystr)
{
    cout<<"Chose Your weapon..Sword,Hand gun..That if you want to survive :)"<<".\n";
    cin>> mystr;
    if(mystr=="Sword"||"Hand gun")
    cout<<"Now use that "<<mystr<<" and kill that Zombie General!!!"<<".\n";
};

int main ()
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
    
    
    cout << "What's your name? "<<".\n";
    cin>>mystr;
    system("cls");
    cout << "Hello Player " << mystr << ".\n";
    cout << "Where do you want to enter "<<mystr<<"?"<<".\n";
    cout << "1: Bedroom\n";
    cout << "2: Entrance\n";
    cout << "3: Hallway\n";
    cout << "4: Kitchen\n";
    cout << "5: Study\n";
    cin>> mystr;
    
    if (mystr=="Bedroom" || mystr=="1")
    {
        Bedroom("Bedroom");
    }
    else if (mystr=="Entrance" || mystr=="2")
    {
        Entrance("Entrance");
    }
    else if (mystr=="Hallway" || mystr=="3")
    {
        Hallway("Hallway");
    }
    else if(mystr=="Kitchen" || mystr=="4")
    {
        Kitchen("Kitchen");
    }
    else if(mystr=="Study" || mystr=="5")
    {
        Study("Study");
    }
    else
    {
        cout << "Error. Zone not available!";
    } 
    return 0;
}