//#include <math.h>
//#include "j1Globals.h"
//#include "j1App.h"
//#include "j1FadeToBlack.h"
//#include "j1Render.h"
//#include "SDL/include/SDL_render.h"
//#include "SDL/include/SDL_timer.h"
//
//j1FadeToBlack::j1FadeToBlack()
//{
//	screen = { 0, 0, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE };
//}
//
//j1FadeToBlack::~j1FadeToBlack()
//{}
//
//// Load assets
//bool j1FadeToBlack::Start()
//{
//	LOG("Preparing Fade Screen");
//	SDL_SetRenderDrawBlendMode(App->render->renderer, SDL_BLENDMODE_BLEND);
//	return true;
//}
//
//// Update: draw background
//update_status j1FadeToBlack::Update()
//{
//	if (current_step == fade_step::none)
//		return UPDATE_CONTINUE;
//
//	Uint32 now = SDL_GetTicks() - start_time;
//	float normalized = MIN(1.0f, (float)now / (float)total_time);
//
//	switch (current_step)
//	{
//	case fade_step::fade_to_black:
//	{
//		if (now >= total_time)
//		{
//			total_time += total_time;
//			start_time = SDL_GetTicks();
//			current_step = fade_step::fade_from_black;
//			if (switch_scene) {
//				module_off->Disable();
//				module_on->Enable();
//			}
//			else {
//				isBlack = true;
//			}
//		}
//	} break;
//
//	case fade_step::fade_only_black:
//	{
//		if (now >= total_time)
//		{
//			isBlack = true;
//		}
//	} break;
//
//	case fade_step::fade_from_black:
//	{
//		isBlack = false;
//		normalized = 1.0f - normalized;
//		if (now >= total_time) {
//			current_step = fade_step::none;
//			switch_scene = false;
//			isfadding = false;
//		}
//
//	} break;
//	}
//
//	// Finally render the black square with alpha on the screen
//	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, (Uint8)(normalized * 255.0f));
//	SDL_RenderFillRect(App->render->renderer, &screen);
//
//	return UPDATE_CONTINUE;
//}
//
//// Fade to black. At mid point deactivate one module, then activate the other
//bool j1FadeToBlack::FadeToBlack(Module* module_off, Module* module_on, float time)
//{
//	bool ret = false;
//
//	if (current_step == fade_step::none)
//	{
//		current_step = fade_step::fade_to_black;
//		start_time = SDL_GetTicks();
//		total_time = (Uint32)(time * 0.5f * 1000.0f);
//
//		ret = true;
//		this->module_off = module_off;
//		this->module_on = module_on;
//		switch_scene = true;
//	}
//	else if (isfadding) {
//
//		/*	If the background is fading to the second texture of the background
//		*	it will continue the fade to black and load the level, if it's from the
//		*	black it will return to black and load the level
//		*/
//		if (current_step == fade_step::fade_from_black) {
//			current_step = fade_step::fade_to_black;
//			start_time = (SDL_GetTicks() - start_time) + (SDL_GetTicks() - total_time);
//		}
//		isfadding = false;
//		ret = true;
//		this->module_off = module_off;
//		this->module_on = module_on;
//		switch_scene = true;
//	}
//
//	return ret;
//}
//
//bool j1FadeToBlack::FadeToBlack(float time)
//{
//	bool ret = false;
//
//	if (current_step == fade_step::none)
//	{
//		current_step = fade_step::fade_to_black;
//		start_time = SDL_GetTicks();
//		total_time = (Uint32)(time * 0.5f * 1000.0f);
//		ret = true;
//		isfadding = true;
//	}
//
//	return ret;
//}
//
//bool j1FadeToBlack::FadeonlyBlack(float time)
//{
//	bool ret = false;
//
//	if (current_step == fade_step::none && !isBlack)
//	{
//		current_step = fade_step::fade_only_black;
//		start_time = SDL_GetTicks();
//		total_time = (Uint32)(time * 1000.0f);
//		ret = true;
//		isfadding = true;
//	}
//
//	return ret;
//}
//
//void j1FadeToBlack::resetStep()
//{
//	current_step = fade_step::none;
//}
