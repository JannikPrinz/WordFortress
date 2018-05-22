#ifndef LOGIC_ADDENTRYGUILOGIC_H
#define LOGIC_ADDENTRYGUILOGIC_H

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
	void ConnectViewWithLogic() override;
};

#endif // LOGIC_ADDENTRYGUILOGIC_H
