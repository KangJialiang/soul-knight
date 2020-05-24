#include "Enemy.h"

Enemy::Enemy() { enemyIsAlive = false; }

Enemy::~Enemy() {}

bool Enemy::init() { return true; }

void Enemy::show() {
  if (getSprite() != nullptr) {
    setVisible(true); //�ɼ�
    enemyIsAlive = true;
  } 
}

void Enemy::hide() {
  if (getSprite() != nullptr) {
    setVisible(false); //���ɼ�
    reset(); //���õ�������
    enemyIsAlive = false;
  }
}

void Enemy::reset() {
  if (getSprite() != nullptr) {
    // randomly reset positon
    // need update
    setPosition(Point(800 + CCRANDOM_0_1() * 2000, 200 - CCRANDOM_0_1() * 100));
  }
}

bool Enemy::isAlive() { return enemyIsAlive;}

//��ײ��� ����û��
bool Enemy::isCollideWithKnight(Knight * knight) {
  //��ȡ��ײ�����bounding box
  Rect entityRec = knight->getBoundingBox();

  Point enemyPos = getPosition();

  //�ж�bounding box �� �������ĵ��Ƿ��н���
  return entityRec.containsPoint(enemyPos);
}