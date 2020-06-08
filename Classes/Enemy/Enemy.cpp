#include "Enemy.h"

Enemy::Enemy() { enemyIsAlive = false; }

Enemy::~Enemy() {}

bool Enemy::init() { 
  this->setHP(5);
  return true; 
}

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

void Enemy::makeCoinside() {
    this->getSprite()->setPosition(this->getPosition());
}//������λ�ø�enemy��Nodeλ�õ�ͳһ

void Enemy::patrolRoute(const BattleRoom* battleRoom, Knight* knight) {
  const Point enemyPos = this->getPosition();

  if (paceCount % 40) {
    this->setPosition(
        Point(enemyPos.x + DIRX[wayOfPace] - knight->getMoveSpeedX(),
              enemyPos.y + DIRY[wayOfPace] - knight->getMoveSpeedY()));
    this->makeCoinside();
    paceCount++;
    return;
  }

  paceCount = 1;  //����Ϊ1��������һ�ֱ�paceCount%40ʶ��Ϊfalse
  wayCanBeSelected.clear();
  for (INT32 dir = 0; dir < CNTDIR; dir++) {
    if (true) { //4�������ߵķ���
      wayCanBeSelected.push_back(dir);
    }
  }  //ѡȡ�����ߵķ���

  srand(static_cast<unsigned int>(time(nullptr)));
  wayOfPace = wayCanBeSelected[rand() % wayCanBeSelected.size()];
  this->setPosition(
      Point(enemyPos.x + DIRX[wayOfPace] - knight->getMoveSpeedX(),
            enemyPos.y + DIRY[wayOfPace] - knight->getMoveSpeedY()));
  this->makeCoinside();

}  //��û̽�⵽��ʿ��ʱ��������Ѳ��·��

void Enemy::aiOfEnemy(Knight* knight, BattleRoom* battleRoom) {
  if (knight == nullptr || battleRoom == nullptr) {
    return;
  }

  const Point enemyPos = this->getPosition();
  const Point knightPos = knight->getPosition();
  const INT32 disBetweenEnemyAndKnight =
      enemyPos.getDistance(knightPos);  //��ȡ���߾��룬���ں����ж�

  if (disBetweenEnemyAndKnight > SIGHTRANGE) {
    patrolRoute(battleRoom, knight);
  } else {
    paceCount = 0;
    wayOfPace = -1;
    if (disBetweenEnemyAndKnight > ATTACKRANGE) {
      this->setPosition(
          Point(enemyPos.x +
                    2 * (knightPos.x - enemyPos.x) / disBetweenEnemyAndKnight -
                    knight->getMoveSpeedX(),
                enemyPos.y +
                    2 * (knightPos.y - enemyPos.y) / disBetweenEnemyAndKnight -
                    knight->getMoveSpeedY()));
      this->makeCoinside();
    } else {
      attackTheKnight(knight, disBetweenEnemyAndKnight);
    }
  }
}

void Enemy::attackTheKnight(Knight* knight,
                                INT32 disBetweenEnemyAndKnight) {
  if (disBetweenEnemyAndKnight <= 5) {
    if (attackTimeCount % 40 == 0) {
      knight->deductHP(3);
      attackTimeCount = 1;
    }
    attackTimeCount++;
    return;
  }

  else {
    const Point enemyPos = this->getPosition();
    const Point knightPos = knight->getPosition();
    this->setPosition(Point(
        enemyPos.x + 2 * (knightPos.x - enemyPos.x) / disBetweenEnemyAndKnight -
            knight->getMoveSpeedX(),
        enemyPos.y + 2 * (knightPos.y - enemyPos.y) / disBetweenEnemyAndKnight -
            knight->getMoveSpeedY()));
    this->makeCoinside();
  }  //��������һ�������������
}