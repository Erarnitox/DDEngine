#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "engine.h"

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

//Logging macros:
#define ENGINE_LOG_ERROR(...) ::tox::log::getEngineLogger()->error(__VA_ARGS__)
#define ENGINE_LOG_WARNING(...) ::tox::log::getEngineLogger()->warning(__VA_ARGS__)
#define ENGINE_LOG_INFO(...) ::tox::log::getEngineLogger()->info(__VA_ARGS__)
#define ENGINE_LOG_TRACE(...) ::tox::log::getEngineLogger()->trace(__VA_ARGS__)

#define LOG_ERROR(...) ::tox::log::getClientLogger()->error(__VA_ARGS__)
#define LOG_WARNING(...) ::tox::log::getClientLogger()->warning(__VA_ARGS__)
#define LOG_INFO(...) ::tox::log::getClientLogger()->info(__VA_ARGS__)
#define LOG_TRACE(...) ::tox::log::getClientLogger()->trace(__VA_ARGS__)
