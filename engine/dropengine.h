#pragma once

#include "Vector3.h"
#include "engine.h"
#include "Log.h"

//Main function:
int main(){
	tox::log::init();
	ENGINE_LOG_INFO("Engine initialized!");
	LOG_TRACE("Application started!");
	
	drop::App* app{ drop::createApp() };
	app->init();
	delete app;
}
