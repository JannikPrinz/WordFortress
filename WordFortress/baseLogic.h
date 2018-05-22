#ifndef LOGIC_BASELOGIC_H
#define LOGIC_BASELOGIC_H

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
		gui->ShowModal();
	}

protected:
	/*
	 * Sets the callbacks of the view with corresponding methods of the corresponding logic.
	 */
	virtual void ConnectViewWithLogic() = 0;

	Gui* gui = NULL;
	Database* database;
};

#endif // LOGIC_BASELOGIC_H
