#include "enemy.hpp"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(string newName, int newHP, int newAttack)
{
	name = newName;
	hp = newHP;	
	attack = newAttack;
}

string Enemy::showName() const
{
	return name;
}

int Enemy::showHP() const
{
	return hp;
}

void Enemy::decreaseHP(int decrease)
{
	hp= hp-decrease;
}

int Enemy::showAttack() const
{
	return attack;
}