#ifndef ML_START_H
#define ML_START_H

#include <Nooskewl_Engine/map.h>
#include <Nooskewl_Engine/map_logic.h>
#include <Nooskewl_Engine/tween.h>
#include <Nooskewl_Engine/widgets.h>

using namespace Nooskewl_Engine;

class ML_start : public Map_Logic {
public:
	ML_start();

	void start(Map *map);
	void end(Map *map);
	void trigger(Map *map, Map_Entity *entity);
	void update(Map *map);
	void activate(Map *map, Map_Entity *activator, Map_Entity *activated);

private:
	bool sat;
	MO3_Text_Button *yes, *pass;
};

#endif // ML_START_H