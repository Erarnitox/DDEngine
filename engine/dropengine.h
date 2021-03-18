#pragma once

#include "engine.h"
#include "Log.h"

//Main function:
int main(){
	tox::log::init();
	ENGINE_LOG_INFO("Tox Engine initialized!");
	LOG_TRACE("Tox Application started!");
	
	drop::App* app{ drop::createApp() };
	app->init();
	delete app;
}
