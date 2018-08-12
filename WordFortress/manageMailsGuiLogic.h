#pragma once

#include "database.h"
#include "GUI\wordFortressManageMailsGui.h"
#include "baseLogic.h"

class ManageMailsGuiLogic : public BaseLogic<WordFortressManageMailsGui>
{
public:
	ManageMailsGuiLogic(Database* database);
	~ManageMailsGuiLogic();

	void AddMail();

private:
	void Initialize() override;
	void RefreshGuiContent();
	void ConnectViewWithLogic() override;

private:
	MailWithTimesUsedList shownMails{};
};
