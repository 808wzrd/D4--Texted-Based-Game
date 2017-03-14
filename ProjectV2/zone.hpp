#include <string>
using namespace std;

class Zone
{
	public:
	Zone(string, string*);
	string showName() const;
	string* showEnemies() const;
	void run();
	
	private:
	string name;
	string* enemies; //????
};