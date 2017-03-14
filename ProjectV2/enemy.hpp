#include <string>
using namespace std;

class Enemy
{
	public:
	Enemy(string, int, int);
	string showName() const;
	int showHP() const;
	int showAttack() const;
	void decreaseHP(int decrease);
	
	private:
	int hp, attack;
	string name;
};