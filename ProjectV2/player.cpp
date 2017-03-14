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
	hp= hp-decrease;
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
