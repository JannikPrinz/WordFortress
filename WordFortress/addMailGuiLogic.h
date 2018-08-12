#pragma once

#include "database.h"
#include "GUI\wordFortressAddMailGui.h"
#include "baseLogic.h"

class AddMailGuiLogic : public BaseLogic<WordFortressAddMailGui>
{
public:
	AddMailGuiLogic(Database* database);
	~AddMailGuiLogic();

	void AddMail();

private:
	void Initialize() override;
};
