#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <vector>

#include "Actor/Entity.h"
#include "Actor/Knight.h"
#include "Const/Const.h"

class Enemy : public Entity {
  static constexpr INT32 SIGHTRANGE = 350;
  static constexpr INT32 ATTACKRANGE = 200;

 public:
  Enemy();
  ~Enemy();
  CREATE_FUNC(Enemy);
  virtual bool init();

 public:
  void show();
  void hide();
  void reset();
  bool isAlive();
  bool isCollideWithKnight(Knight* knight);

  void makeCoinside();

  void aiOfEnemy(Knight* knight, BattleRoom* battleRoom);  

 private:
  void patrolRoute(const BattleRoom* battleRoom, Knight* knight);
  void attackTheKnight(Knight* knight, INT32 disBetweenEnemyAndKnight);

 private:
  bool enemyIsAlive;

  INT32 paceCount = 0;  //���ڱ�֤����20��������ͬһ����
  INT32 wayOfPace = -1;  //ѡ���ߵķ���
  INT32 attackTimeCount = 1;
  std::vector<INT32> wayCanBeSelected;  //�ɹ�ѡ������߷���
};

#endif