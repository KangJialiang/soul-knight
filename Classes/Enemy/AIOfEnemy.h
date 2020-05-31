#ifndef _AIOFENEMY_H_
#define _AIOFENEMY_H_
#include "Enemy.h"
#include "Scene/BattleRoom.h"
#include <vector>

class AIOfEnemy {
	static constexpr INT32 SIGHTRANGE = 300;
	static constexpr INT32 ATTACKRANGE = 100;
	static constexpr INT32 LEFT = 0;
	static constexpr INT32 UP = 1;
	static constexpr INT32 RIGHT = 2;
	static constexpr INT32 DOWN = 3;

public:
	AIOfEnemy();
	~AIOfEnemy();
	void bindEnemy(Enemy* enemy);
	void aiOfEnemy(Knight* knight,BattleRoom* battleRoom,const std::vector<float>& boundaryOfRoom);//boundaryOfRoom��һ����װ�˱߽��vector����˳������ӦΪ��߽硢�ϡ��ҡ���

private:
	void patrolRoute(const BattleRoom* battleRoom,Knight* knight,const std::vector<float>& boundaryOfRoom);
	void attackTheKnight(Knight* knight, INT32 disBetweenEnemyAndKnight);

private:
	Enemy* myEnemy;
	INT32 paceCount;//���ڱ�֤����20��������ͬһ����
	INT32 wayOfPace;//ѡ���ߵķ���
	std::vector<INT32> wayCanBeSelected;//�ɹ�ѡ������߷���
};
#endif // _AIOFENEMY_H_
