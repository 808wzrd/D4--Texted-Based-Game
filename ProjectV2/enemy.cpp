#include "enemy.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Enemy::Enemy(string newName, int newHP, int newAttack)
{
	name = newName;
	hp = newHP;	
	attack = newAttack;
}

string Enemy::showName()
{
	return name;
}

int Enemy::showHP()
{
	return hp;
}

void Enemy::decreaseHP(int decrease)
{
	hp = hp - decrease;
}

int Enemy::showAttack()
{
	return attack;
}

vector<string> Enemy::checkStatus()
{
	//change all to string
	string hpString = to_string(hp);
	string attackString = to_string(attack);
	vector<string> status = {name, hpString, attackString};
	return status;
}