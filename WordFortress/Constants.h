#ifndef RESSOURCE_CONSTANTS_H
#define RESSOURCE_CONSTANTS_H

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
 *	- Serivce TEXT
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
#define CREATE_NEW_DATABASE "PRAGMA foreign_keys = ON; CREATE TABLE IF NOT EXISTS MailAccounts (MailID INTEGER PRIMARY KEY, MailAddress TEXT); CREATE TABLE IF NOT EXISTS Passwords (PasswordID INTEGER PRIMARY KEY, Salt TEXT, Password TEXT); CREATE TABLE IF NOT EXISTS Entries (EnrtryID INTEGER PRIMARY KEY, Service TEXT, UserName TEXT, MailID INTEGER REFERENCES MailAccounts (MailID), Notes TEXT, PasswordID INTEGER REFERENCES Passwords(PasswordID)); CREATE TABLE IF NOT EXISTS Options(OptionID INTEGER PRIMARY KEY, OptionKey TEXT, OptionValue TEXT);"

#endif RESSOURCE_CONSTANTS_H
