/**
 * @file User.cpp
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe armazenando informaçoẽs do usário.
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "User.h"

User::User(int id) : m_id(id), m_next(nullptr), m_isRemoved(false) {}

User::~User()
{
}

void User::terminate()
{
	if (m_next != nullptr)
	{
		m_next->terminate();
		delete m_next;
	}
}

int User::getId() { return m_id; }

MailBox *User::getBox() { return &m_box; }

User *User::getNext() { return m_next; }

void User::setNext(User *next) { m_next = next; }

bool User::isRemoved() { return m_isRemoved; }

void User::setRemoved(bool value)
{
	m_isRemoved = value;
	m_box = MailBox();
}