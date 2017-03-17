#include <string>
#include <vector>
using namespace std;

class Enemy
{
	public:
	Enemy(string, int, int);
	string showName();
	int showHP();
	int showAttack();
	void decreaseHP(int decrease);
	vector<string> checkStatus();

	
	private:
	int hp, attack;
	string name;
};