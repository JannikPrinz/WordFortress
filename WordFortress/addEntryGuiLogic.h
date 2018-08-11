#pragma once

#include "database.h"
#include "GUI\wordFortressAddEntryGui.h"
#include "baseLogic.h"

class AddEntryGuiLogic : public BaseLogic<WordFortressAddEntryGui>
{
public:
	AddEntryGuiLogic(Database* database);
	~AddEntryGuiLogic();

	void AddEntry();

private:
	void AddMail();
	void ConnectViewWithLogic() override;
};
