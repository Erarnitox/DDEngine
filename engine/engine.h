#pragma once

namespace tox{
	class App{
	public:
		App();
		virtual ~App();
		void start();
	};
	
	extern tox::App* createApp();
}
