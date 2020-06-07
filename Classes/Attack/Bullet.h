#ifndef _BULLET_H_
#define _BULLET_H_
#include "cocos2d.h"
#include "Entity2.h"
USING_NS_CC;

class Bullet : public Entity2 {
public:
  Bullet();
  ~Bullet();
  CREATE_FUNC(Bullet);
  virtual bool init();

  bool isInScreen();
  Vec2 getBulletSpeed();
  void setBulletSpeed(Vec2 speed);
<<<<<<< Updated upstream
=======
  void setAttack(INT32 attack);
  INT32 getAttack();
>>>>>>> Stashed changes


protected:
  Vec2 bulletSpeed;
<<<<<<< Updated upstream
=======
  INT32 attack;
>>>>>>> Stashed changes

};

#endif;
