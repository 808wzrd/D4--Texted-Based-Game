#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string mystr;
  cout << "What's your name? "<<".\n";
  getline (cin, mystr);
  cout << "Hello Player " << mystr << ".\n";
  cout << "Where are you "<<mystr<<"?"<<".\n";
  getline (cin, mystr);
if (mystr=="Bedroom")
 {cout<<"Chose Your weapon..Broom,Desk Lamp..That if you want to survive :)"<<".\n";
  getline (cin, mystr);
    if (mystr=="Broom"||"Desk Lamp")
    cout<<"Now use that "<<mystr<<" and kill those weakened zombies!!!"<<".\n";
    }
else if(mystr=="Enterance")
  {cout<<"Chose Your weapon..Flash light..That if you want to survive :)"<<".\n";
  getline (cin, mystr);
    if(mystr=="Flash light")
    cout<<"Now use that "<<mystr<<" and kill the Zombie General!!!"<<".\n";
  }
else if(mystr=="Hallway")
  {cout<<"Chose Your weapon..Fire Extinguisher,Picture Frame,Vase..That if you want to survive :)"<<".\n";
  getline (cin, mystr);
    if(mystr=="Fire Extinguisher"||"Picture Frame"||"Vase")
    cout<<"Now use that "<<mystr<<" and kill those Rats!!!"<<".\n";
  }
else if(mystr=="Kitchen")
  {cout<<"Chose Your weapon..Knife,Frying pan..That if you want to survive :)"<<".\n";
  getline (cin, mystr);
    if(mystr=="Knife"||"Frying pan")
    cout<<"Now use that "<<mystr<<" and kill that Zombie elite!!!"<<".\n";
  }
  else if(mystr=="Study")
  {cout<<"Chose Your weapon..Sword,Hand gun..That if you want to survive :)"<<".\n";
  getline (cin, mystr);
    if(mystr=="Sword"||"Hand gun")
    cout<<"Now use that "<<mystr<<" and kill that Zombie General!!!"<<".\n";
  }

  return 0;
}
