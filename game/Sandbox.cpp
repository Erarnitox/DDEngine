#include "../engine/toxengine.h"

class Sandbox : public tox::App{
public:
	Sandbox(){
		
	}
	
	~Sandbox(){
		
	}
};

tox::App* tox::createApp(){
	return new Sandbox();
}


