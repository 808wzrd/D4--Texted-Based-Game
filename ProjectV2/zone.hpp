#include <string>
#include <vector>
using namespace std;

class Zone
{
	public:
	Zone(string);
	string showName() const;
	vector<string> showEnemies() const;
	vector<string> retrieveEnemies();
	vector<string> showWeapons();
	string chooseWeapon();
	
	private:
	string name;
	vector<string> enemies;
	vector<string> weapons;
};