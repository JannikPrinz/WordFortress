#pragma once

#define DATABASE_FILENAME "DataBase.wfdb"

// ******************************************************************
// ======================= SQL statements: ==========================
// ******************************************************************

/*
 * MailAccounts
 *	- MailID INTEGER PRIMARY KEY
 *	- MailAddress TEXT
 *
 * Passwords
 *	- PasswordID INTEGER PRIMARY KEY
 *	- Salt TEXT
 *	- Password TEXT
 *
 * Entries
 *	- EntryID INTEGER PRIMARY KEY
 *	- Service TEXT
 *	- UserName TEXT
 *	- MailID INTEGER REFERENCES MailAccounts (MailID)
 *	- Notes TEXT
 *	- PasswordID INTEGER REFERENCES Passwords(PasswordID)
 *
 * Options
 *	- OptionID INTEGER PRIMARY KEY
 *	- OptionKey TEXT
 *	- OptionValue TEXT
 */
#define CREATE_NEW_DATABASE "PRAGMA foreign_keys = ON; CREATE TABLE IF NOT EXISTS MailAccounts (MailID INTEGER PRIMARY KEY, MailAddress TEXT); CREATE TABLE IF NOT EXISTS Passwords (PasswordID INTEGER PRIMARY KEY, Salt TEXT, Password TEXT); CREATE TABLE IF NOT EXISTS Entries (EntryID INTEGER PRIMARY KEY, Service TEXT, UserName TEXT, MailID INTEGER REFERENCES MailAccounts (MailID), Notes TEXT, PasswordID INTEGER REFERENCES Passwords(PasswordID)); CREATE TABLE IF NOT EXISTS Options(OptionID INTEGER PRIMARY KEY, OptionKey TEXT, OptionValue TEXT);"
#define INSERT_DEFAULT_VALUES "PRAGMA foreign_keys = ON; INSERT INTO MailAccounts (MailID, MailAddress) VALUES (1, \"\");"

// TABLE values:
#define MAILACCOUNTS_MAILID "MailID"
#define MAILACCOUNTS_MAILADDRESS "MailAddress"
#define ENTRIES_ENTRYID "EntryID"
#define ENTRIES_SERVICE "Service"
#define ENTRIES_USERNAME "UserName"
#define ENTRIES_MAILID "MailID"
#define ENTRIES_NOTES "Notes"
#define ENTRIES_PASSWORDID "PasswordID"

// SELECT values:
#define MAILACCOUNTS_TIMES_USED "times"

// INSERT statements:
#define INSERT_NEW_MAILACCOUNT_PART_1 "PRAGMA foreign_keys = ON; INSERT INTO MailAccounts (MailAddress) VALUES (\""
#define INSERT_NEW_MAILACCOUNT_PART_2 "\");"
#define INSERT_NEW_PASSWORD_PART_1 "PRAGMA foreign_keys = ON; INSERT INTO Passwords (Salt, Password) VALUES (\""
#define INSERT_NEW_PASSWORD_PART_2 "\", \""
#define INSERT_NEW_PASSWORD_PART_3 "\");"
#define INSERT_NEW_ENTRY_PART_1 "PRAGMA foreign_keys = ON; INSERT INTO Entries (Service, UserName, MailID, Notes, PasswordID) VALUES (\""
#define INSERT_NEW_ENTRY_PART_2 "\", \""
#define INSERT_NEW_ENTRY_PART_3 "\", "
#define INSERT_NEW_ENTRY_PART_4 ", \""
#define INSERT_NEW_ENTRY_PART_5 "\", "
#define INSERT_NEW_ENTRY_PART_6 ");"
#define INSERT_NEW_OPTION_PART_1 "PRAGMA foreign_keys = ON; INSERT INTO Options (OptionKey, OptionValue) VALUES (\""
#define INSERT_NEW_OPTION_PART_2 "\", \""
#define INSERT_NEW_OPTION_PART_3 "\");"

// SELECT statements:
#define GET_LAST_INSERTED_ID "select last_insert_rowid();"
#define GET_MAIL_ACCOUNTS "PRAGMA foreign_keys = ON; SELECT * FROM MailAccounts;"
#define GET_MAIL_ACCOUNTS_WITH_TIMES_USED "PRAGMA foreign_keys = ON; SELECT M.MailID, M.MailAddress, E.times FROM MailAccounts M LEFT OUTER JOIN (SELECT MailID, COUNT(MailID) AS times FROM Entries GROUP BY MailID) E ON M.MailID = E.MailID;"
#define GET_ENTRIES "PRAGMA foreign_keys = ON; SELECT * FROM Entries;"
