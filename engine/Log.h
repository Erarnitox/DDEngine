#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

//TODO: change on Release:
#define TOX_DEBUG 1

namespace tox{
	class log{
	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getEngineLogger(){ return engineLogger;}
		inline static std::shared_ptr<spdlog::logger>& getClientLogger(){ return clientLogger;}
	};
}

#if TOX_DEBUG > 0
	//Logging macros:
	#define ENGINE_LOG_ERROR(...) ::tox::log::getEngineLogger()->error(__VA_ARGS__)
	#define ENGINE_LOG_WARNING(...) ::tox::log::getEngineLogger()->warn(__VA_ARGS__)
	#define ENGINE_LOG_INFO(...) ::tox::log::getEngineLogger()->info(__VA_ARGS__)
	#define ENGINE_LOG_TRACE(...) ::tox::log::getEngineLogger()->trace(__VA_ARGS__)

	#define LOG_ERROR(...) ::tox::log::getClientLogger()->error(__VA_ARGS__)
	#define LOG_WARNING(...) ::tox::log::getClientLogger()->warn(__VA_ARGS__)
	#define LOG_INFO(...) ::tox::log::getClientLogger()->info(__VA_ARGS__)
	#define LOG_TRACE(...) ::tox::log::getClientLogger()->trace(__VA_ARGS__)
#else
	//Logging macros:
	#define ENGINE_LOG_ERROR(...) 
	#define ENGINE_LOG_WARNING(...) 
	#define ENGINE_LOG_INFO(...) 
	#define ENGINE_LOG_TRACE(...)

	#define LOG_ERROR(...)
	#define LOG_WARNING(...)
	#define LOG_INFO(...)
	#define LOG_TRACE(...)
#endif
