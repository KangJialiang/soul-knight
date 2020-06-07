#include "Weapon.h"
#define PI 3.1415926535898

Weapon::Weapon(){}

bool Weapon::init()
{ 
  return true;	
}

Weapon::~Weapon(){}

void Weapon::bindWeapon(Weapon* weapon) 
{
  this->bindSprite(weapon->sprite, LayerPlayer + 1);
  this->attack = weapon->attack;
  this->fireSpeed = weapon->fireSpeed;
}

<<<<<<< Updated upstream


=======
>>>>>>> Stashed changes
void Weapon::setFireSpeed(float fireSpeed)
{
  this->fireSpeed = fireSpeed;
}

float Weapon::getFireSpeed() { return this->fireSpeed; }
<<<<<<< Updated upstream
=======
void Weapon::setAttack(INT32 attack) { this->attack = attack; }
INT32  Weapon::getAttack() { return this->attack; }
>>>>>>> Stashed changes

Bullet* Weapon::createBullet(Vec2 speed,INT32 firePower)
{
  Bullet* bullet = Bullet::create();
  bullet->setBulletSpeed(speed);
  bullet->bindSprite(Sprite::create("Bullet//pistol.png"), 12);

  if (speed.x == 0 && speed.y > 0)  bullet->getSprite()->setRotation(-90);
  else if (speed.x < 0)   bullet->getSprite()->setRotation(-(180 + 180 * atan(speed.y / speed.x) / PI));
  else if (speed.x == 0 && speed.y < 0)   bullet->getSprite()->setRotation(-270);
  else    bullet->getSprite()->setRotation(-(180 * atan(speed.y / speed.x) / PI));
  bullet->setAttack(firePower);

  return bullet;
<<<<<<< Updated upstream
  
=======
>>>>>>> Stashed changes
}