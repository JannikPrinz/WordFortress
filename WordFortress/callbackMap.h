#pragma once

#include <map>

template <class CallbackAction>
class CallbackMap
{
public:
	typedef std::function<void()> CallbackFunction;
	typedef std::map<CallbackAction, CallbackFunction> CallbackFunctionMap;

	CallbackMap() { }
	~CallbackMap() { }

public:
	inline void SetCBFunction(const CallbackAction& action, const CallbackFunction& function)
	{
		callbackMap.emplace(action, function);
	}

protected:
	inline void CallCBFunction(const CallbackAction& action)
	{
		CallbackFunctionMap::iterator it = callbackMap.find(action);
		if (it != callbackMap.end() && it->second != NULL)
		{
			it->second();
		}
	}

private:
	CallbackFunctionMap callbackMap;
};
