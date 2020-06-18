#ifndef _STATUE_H_
#define _STATUE_H

#include "cocos2d.h"
#include "Const/Const.h"

USING_NS_CC;

class Statue : public Node {
  static constexpr INT32 CNT_TYPE = 6;
 public:
  Statue() = default;
  CREATE_FUNC(Statue);

  virtual bool init();
  void bindSprite(Sprite*, INT32);

  void setGoldCost(INT32);
  INT32 getGoldCost() const; //��һ���
  INT32 getStatueType() const; //��������

  Label* getLabel() const;

 private:
  Sprite* sprite = nullptr;
  Label* label = nullptr;

 private:
  INT32 statueType = 0;
  INT32 goldCost = 0;
  bool playerVisited = false;
};

#endif
