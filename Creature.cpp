#include "Creature.h"

void Creature::OnAttacked(Creature* attacker)
{
	int damge = attacker->_attack - _defence;
	if (damge < 0)
		damge = 0;

	_hp -= damge;
	if (_hp < 0)
		_hp = 0;
}