#include "Bullet.h"

Bullet::Bullet(){}

Bullet::~Bullet(){}

bool Bullet::init() {  return true; }

Vec2 Bullet::getBulletSpeed() { return this->bulletSpeed; }

void Bullet::setBulletSpeed(Vec2 speed) { this->bulletSpeed = speed; }


bool Bullet::isInScreen()        ///���˽���λ�ȡ��ͼλ����д
{
  return true;
}


