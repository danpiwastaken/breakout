#pragma once
#include "Entity.h"
#include <vector>
#include "ball.h"

namespace std
{
	enum class state { normal, destroyed };
}

class brick: public Entity
{
private:
	std::state _state;
	ball* _ball;
public:
	void Update();
	void setState(std::state new_state);
	void setBall(ball* ball);
	std::state getState();
	brick();
};

