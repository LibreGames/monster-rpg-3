#include <Nooskewl_Engine/Nooskewl_Engine.h>

#include "brains.h"
#include "ml_start_upper.h"

ML_start_upper::ML_start_upper(int last_visited_time)
{
}

void ML_start_upper::start_audio()
{
	noo.play_music("pub.mml");
}

void ML_start_upper::start(bool been_here_before)
{
	Tilemap *tilemap = noo.map->get_tilemap();
	tilemap->enable_lighting(true);
	tilemap->set_lighting_parameters(true, 15, noo.colours[6]/*medium grey*/);

	if (been_here_before == false) {
		Map_Entity *door1 = new Map_Entity("door");
		door1->load_sprite("door");
		Door_Brain *door1_brain = new Door_Brain(false);
		door1->set_brain(door1_brain);
		door1->set_position(Point<int>(3, 7));
		door1->set_solid(false);

		Map_Entity *door2 = new Map_Entity("door");
		door2->load_sprite("door");
		Door_Brain *door2_brain = new Door_Brain(false);
		door2->set_brain(door2_brain);
		door2->set_position(Point<int>(9, 7));
		door2->set_solid(false);

		Map_Entity *door3 = new Map_Entity("door");
		door3->load_sprite("door");
		Door_Brain *door3_brain = new Door_Brain(false);
		door3->set_brain(door3_brain);
		door3->set_position(Point<int>(15, 7));
		door3->set_solid(false);

		Map_Entity *door4 = new Map_Entity("door");
		door4->load_sprite("door");
		Door_Brain *door4_brain = new Door_Brain(false);
		door4->set_brain(door4_brain);
		door4->set_position(Point<int>(3, 12));
		door4->set_solid(false);

		Map_Entity *door5 = new Map_Entity("door");
		door5->load_sprite("door");
		Door_Brain *door5_brain = new Door_Brain(false);
		door5->set_brain(door5_brain);
		door5->set_position(Point<int>(21, 12));
		door5->set_solid(false);

		noo.map->add_entity(door1);
		noo.map->add_entity(door2);
		noo.map->add_entity(door3);
		noo.map->add_entity(door4);
		noo.map->add_entity(door5);

		Map_Entity *bottle = new Map_Entity("bottle");
		bottle->load_sprite("bottle_tipped");
		bottle->set_brain(new Item_Brain("bottle", 1));
		bottle->set_position(Point<int>(11, 3));
		bottle->set_solid(false);
		noo.map->add_entity(bottle);

		Map_Entity *apple1 = new Map_Entity("apple");
		apple1->load_sprite("apple");
		apple1->set_brain(new Item_Brain("apple", 1));
		apple1->set_position(Point<int>(7, 5));
		apple1->set_z(noo.tile_size);
		apple1->set_high(true);
		apple1->set_solid(false);
		noo.map->add_entity(apple1);

		Map_Entity *apple2 = new Map_Entity("apple");
		apple2->load_sprite("apple");
		apple2->set_brain(new Item_Brain("apple", 1));
		apple2->set_position(Point<int>(20, 16));
		apple2->set_z(noo.tile_size);
		apple2->set_high(true);
		apple2->set_solid(false);
		noo.map->add_entity(apple2);

		SDL_Colour light_colour1 = noo.colours[36]; // light yellow
		SDL_Colour light_colour2 = noo.colours[37]; // darker yellow

		Map_Entity *torch_n1 = new Map_Entity("torch_n1");
		torch_n1->load_sprite("torch_n");
		torch_n1->set_position(Point<int>(6, 7));
		torch_n1->set_solid(false);
		torch_n1->set_z(noo.tile_size);
		noo.map->add_entity(torch_n1);
		Map_Entity *torch_n1_light = new Map_Entity("torch_n1_light");
		torch_n1_light->set_brain(new Flickering_Light_Brain(Vec3D<float>(6, 8, 1), light_colour1, light_colour2, 4, 8, 0, 6));
		torch_n1_light->set_solid(false);
		noo.map->add_entity(torch_n1_light);

		Map_Entity *torch_n2 = new Map_Entity("torch_n2");
		torch_n2->load_sprite("torch_n");
		torch_n2->set_position(Point<int>(12, 7));
		torch_n2->set_solid(false);
		torch_n2->set_z(noo.tile_size);
		noo.map->add_entity(torch_n2);
		Map_Entity *torch_n2_light = new Map_Entity("torch_n2_light");
		torch_n2_light->set_brain(new Flickering_Light_Brain(Vec3D<float>(12, 8, 1), light_colour1, light_colour2, 4, 8, 0, 6));
		torch_n2_light->set_solid(false);
		noo.map->add_entity(torch_n2_light);

		Map_Entity *torch_n3 = new Map_Entity("torch_n3");
		torch_n3->load_sprite("torch_n");
		torch_n3->set_position(Point<int>(18, 7));
		torch_n3->set_solid(false);
		torch_n3->set_z(noo.tile_size);
		noo.map->add_entity(torch_n3);
		Map_Entity *torch_n3_light = new Map_Entity("torch_n3_light");
		torch_n3_light->set_brain(new Flickering_Light_Brain(Vec3D<float>(18, 8, 1), light_colour1, light_colour2, 4, 8, 0, 6));
		torch_n3_light->set_solid(false);
		noo.map->add_entity(torch_n3_light);

		Map_Entity *torch_n4 = new Map_Entity("torch_n4");
		torch_n4->load_sprite("torch_n");
		torch_n4->set_position(Point<int>(2, 12));
		torch_n4->set_solid(false);
		torch_n4->set_z(noo.tile_size);
		noo.map->add_entity(torch_n4);
		Map_Entity *torch_n4_light = new Map_Entity("torch_n4_light");
		torch_n4_light->set_brain(new Flickering_Light_Brain(Vec3D<float>(2, 12, 1), light_colour1, light_colour2, 4, 8, 0, 6));
		torch_n4_light->set_solid(false);
		noo.map->add_entity(torch_n4_light);

		Map_Entity *torch_n5 = new Map_Entity("torch_n5");
		torch_n5->load_sprite("torch_n");
		torch_n5->set_position(Point<int>(20, 12));
		torch_n5->set_solid(false);
		torch_n5->set_z(noo.tile_size);
		noo.map->add_entity(torch_n5);
		Map_Entity *torch_n5_light = new Map_Entity("torch_n5_light");
		torch_n5_light->set_brain(new Flickering_Light_Brain(Vec3D<float>(20, 12, 1), light_colour1, light_colour2, 4, 8, 0, 6));
		torch_n5_light->set_solid(false);
		noo.map->add_entity(torch_n5_light);

		Map_Entity *books1 = new Map_Entity("books1");
		books1->set_position(Point<int>(4, 3));
		books1->set_brain(new Sign_Brain("start_upper_books1"));
		noo.map->add_entity(books1);

		Map_Entity *books2 = new Map_Entity("books2");
		books2->set_position(Point<int>(5, 3));
		books2->set_brain(new Sign_Brain("start_upper_books2"));
		noo.map->add_entity(books2);
	}
}

void ML_start_upper::trigger(Map_Entity *entity)
{
	Point<int> collide_pos;
	if (entity->get_id() == 0 && entity->tiles_collide(Point<int>(22, 3), Size<int>(2, 2), collide_pos)) {
		entity->stop();
		noo.map->change_map("start.map", Point<int>(19, 4), S);
	}
}
