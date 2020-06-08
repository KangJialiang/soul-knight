﻿#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "cocos2d.h"
#include "Entity.h"



USING_NS_CC;

class Hall;
class BattleRoom;
class Weapon;

class Knight : public Entity {
  friend class BattleScene;
  friend class SafeScene;
  static constexpr float moveSpeed = 5.0f;

 public:
  Knight();
  ~Knight();
  CREATE_FUNC(Knight);
  virtual bool init();

  //virtual void update(float);

  void registerKeyboardEvent();

  void weaponAttack(Vec2 last);
  void useUltimateSkill();

  void bindBattleRoom(BattleRoom*);
  void bindHall(Hall*);

  float getMoveSpeedX();
  float getMoveSpeedY();

  bool allKilled();

  void setNeedCreateBox(bool);
  bool getNeedCreateBox();

  Animate* getAnimate();

 private:
  INT32 armor;
  INT32 MP;
  Weapon* weapon;

  bool needCreateBox;
  

  BattleRoom* atBattleRoom = nullptr; //目前在哪个房间
  Hall* atHall = nullptr;

  bool isInvincible = false; //是否无敌
  bool haveUltimateSkill = true; //是否有大招

  
};

#endif
