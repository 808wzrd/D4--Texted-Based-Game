#include <string>
using namespace std;

class Player
{
	public:
	Player(string, int, string, string, int);
	string showName();
	string showWeapon();
	string showGender();
	void pickWeapon(string newWeapon);
	int showHP();
	void decreaseHP(int decrease);
	void increaseHP(int increase);
	int showAttack();
	void setAttack(int newAttack);
	
	private:
	int hp, attack;
	string name, weapon, gender;
};