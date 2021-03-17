#pragma once
#include <string>
#include "../engine.h"

#define BIT(x) (1 << x)

namespace tox{
	enum class EventType{
		None = 0,
		WindowResize, WindowClose,
		GameUpdate, GameTrick, Render,
		KeyPress, KeyUp, KeyDown,
		MouseClick, MouseUp, MouseDown, MouseScroll, MouseMove
	};
	
	enum EventCategory{
		None = 0,
		EventCategoryGame 		= BIT(0),
		EventCategoryInput 		= BIT(1),
		EventCategoryKeyboard 	= BIT(2),
		EventCategoryMouse		= BIT(3),
		EventCategoryMouseButton= BIT(4)
	};
	
	class EventDispatcher{
		
	};
	
	class Event{
		friend class EventDispatcher;
	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); };
		
		inline bool isInCategory(EventCategory cat){
			return getCategoryFlags() & cat;
		}
	protected:
		bool isHandled{ false };
	};
}
