#include "libsqlite.hpp"                    // sqlite library
#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string newName, int newHP, string newWeapon, string newGender, int newAttack)
{
	name = newName;
	hp = newHP;	
	weapon = newWeapon;
    gender = newGender;
    attack = newAttack;
}

string Player::showName()
{
	return name;
}

string Player::showGender()
{
	return gender;
}

int Player::showHP()
{
	return hp;
}

void Player::decreaseHP(int decrease)
{
	hp = hp - decrease;
}

void Player::increaseHP(int increase)
{
	hp = hp + increase; 
}

string Player::showWeapon()
{
	return weapon;
}

void Player::pickWeapon(string newWeapon)
{
	weapon = newWeapon;
}

int Player::showAttack()
{
    return attack;
}

void Player::setAttack(int newAttack)
{
	attack=newAttack;
}

vector<string> Player::checkStatus()
{
	string hpString = to_string(hp);
	string attackString = to_string(attack);
	vector<string> status = {name, gender, hpString, weapon, attackString};
	return status;
}

void Player::addToInventory(string weapon)
{
	inventory.push_back(weapon);
}

vector<string> Player::showInventory()
{
	return inventory;
}

void Player::sortInventory()
{
	int minPos;
	string temp;
	for (int i=0;i< inventory.size()-1;i++) {
		minPos = i;
		for (int j = i + 1; j < inventory.size(); j++) {
			if (inventory[j] < inventory[minPos]) {
				minPos = j;
			}
		}
		if (minPos != i) {
			temp = inventory[i];
			inventory[i] = inventory[minPos];
			inventory[minPos] = temp;
		}
	}
}