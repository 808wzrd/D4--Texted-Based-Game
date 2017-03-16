#include <string>
using namespace std;

class Enemy
{
	public:
	Enemy(string, int, int);
	string showName();
	int showHP();
	int showAttack();
	void decreaseHP(int decrease);
	
	private:
	int hp, attack;
	string name;
};