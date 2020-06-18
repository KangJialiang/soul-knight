#include "Weapon.h"


Weapon::Weapon(){}

bool Weapon::init()
{ 
  return true;	
}

Weapon::~Weapon(){}

void Weapon::setFireSpeed(float fireSpeed)
{
  
  this->fireSpeed = fireSpeed;
}

float Weapon::getFireSpeed() { return this->fireSpeed; }
void Weapon::setAttack(INT32 attack) { this->attack = attack; }
INT32  Weapon::getAttack() { return this->attack; }

INT32 Weapon::getMPConsumption() {  return mpConsumption;}

void Weapon::setMPConsumption(INT32 deta) { this->mpConsumption = deta;}

bool Weapon::getWeaponState()
{
  return this->weaponState;
}

void Weapon::setWeaponState(bool state)
{
  this->weaponState = state;
}

void Weapon::knifeAttack(Knight* knight)
{
  if (knight->getAtBattleRoom() == nullptr) return;
  Vector<Enemy*>& vecEnemy = knight->getAtBattleRoom()->getVecEnemy();

  for (auto& e : vecEnemy) {
    if (e->getParent() == nullptr) continue;

    float enemyX = e->getPositionX(), enemyY = e->getPositionY();

    if (sqrt(pow(knight->getPositionX() - enemyX, 2) +
      pow(knight->getPositionY() - enemyY, 2)) <= 75.0f) {
      e->deductHP(this->attack); //�ڼ���Բ�� ��Ѫ
    }
  }
}

Bullet* Weapon::createBullet(Vec2 speed,INT32 firePower)
{
  Bullet* bullet = Bullet::create();
  bullet->setBulletSpeed(speed);
  bullet->bindSprite(Sprite::create("Bullet//pistol.png"), 12);

  if (speed.x == 0 && speed.y > 0)
  {
    //this->getSprite()->setRotation(-90.0f);
    bullet->getSprite()->setRotation(-90.0f);
  }
  else if (speed.x < 0)
  {
    //this->getSprite()->setRotation(-(180.0f + 180.0f * atan(speed.y / speed.x) / PI));
    bullet->getSprite()->setRotation(-(180.0f + 180.0f * atan(speed.y / speed.x) / PI));
  }
  else if (speed.x == 0 && speed.y < 0)   
  {
    //this->getSprite()->setRotation(-270.0f);
    bullet->getSprite()->setRotation(-(180.0f + 180.0f * atan(speed.y / speed.x) / PI));
  }
  else
  {
    //this->getSprite()->setRotation(-(180.0f * atan(speed.y / speed.x) / PI));
    bullet->getSprite()->setRotation(-(180.0f + 180.0f * atan(speed.y / speed.x) / PI));
  }
  bullet->setAttack(firePower);

  return bullet;
}