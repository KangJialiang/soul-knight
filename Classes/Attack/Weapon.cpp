#include "Weapon.h"

Weapon::Weapon(){}

bool Weapon::init()
{
    return true;
}




void Weapon::bindWeapon(Weapon* weapon)
{
    this->sprite = weapon->getSprite();
    this->attack = weapon->getAttack();
    this->speed = weapon->getSpeed();
}



Bullet* Weapon::createBullet(Vec2 speed, Vec2 curPos, BattleRoom* atBattleRoom, Hall* atHall)  //to do������������� atBattleRoom��atHall
{
    Bullet* bullet = Bullet::create();
    bullet->bindSprite(Sprite::create("bullet.png"));
    bullet->setPosition(curPos);
    bullet->setSpeed(speed);

    //to do
    
    return bullet;
}

float Weapon::getSpeed()
{
	return this->speed;
}

Weapon::~Weapon() {}
