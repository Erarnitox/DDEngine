#include "Log.h"

namespace tox{
	std::shared_ptr<spdlog::logger> log::engineLogger;
	std::shared_ptr<spdlog::logger> log::clientLogger;
	
	void log::init(){
		#if TOX_DEBUG > 0
			spdlog::set_pattern("%^[%T] %n: %v%$");
			engineLogger = spdlog::stdout_color_mt("ENGINE");
			engineLogger->set_level(spdlog::level::trace);
		
			clientLogger = spdlog::stdout_color_mt("APP");
			clientLogger->set_level((spdlog::level::trace));
		#endif
	}
}
