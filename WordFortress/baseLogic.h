#pragma once

#include <wx\window.h>
#include "callbackMap.h"
#include "database.h"

template <class Gui>
class BaseLogic
{
public:
	BaseLogic(Database* db)
		: database(db)
	{
		// Check if Gui is derived from wxWindow and callbackMap:
		static_assert(std::is_base_of<wxWindow, Gui>::value, "Gui not derived from wxWindow");
	}

	~BaseLogic()
	{
		if (gui != NULL)
		{
			delete gui;
			gui = NULL;
		}
	}

	void ShowGui()
	{
		if (gui != NULL) return;
		gui = new Gui(NULL, wxID_ANY);
		ConnectViewWithLogic();
		Initialize();
		gui->ShowModal();
	}

protected:
	/*
	 * Sets the callbacks of the view with corresponding methods of the corresponding logic.
	 */
	virtual void ConnectViewWithLogic() = 0;
	/*
	 * Optional initialize method, which is called after the gui is built but before the gui is shown.
	 */
	virtual void Initialize() {}

	Gui* gui = NULL;
	Database* database;
};
