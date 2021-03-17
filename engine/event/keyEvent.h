#pragma once

#include "coreEvent.h"

namespace tox{
	class KeyDownEvent : public Event{
	public:
		inline int getKeyCode() const { return keyCode; }
		
		virtual EventType getEventType() const override{
			return EventType::KeyDown;
		}
	
	protected:
		KeyDownEvent(int keyCode):keyCode{ keyCode }{}
		int keyCode;
	};
}
