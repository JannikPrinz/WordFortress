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
		Initialize();
		gui->ShowModal();
	}

protected:
	/*
	 * Sets the callbacks of the view with corresponding methods of the corresponding logic.
	 * Initialize shown content.
	 */
	virtual void Initialize() = 0;

	Gui* gui = NULL;
	Database* database;
};
