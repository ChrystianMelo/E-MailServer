/**
 * @file User.cpp
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Representação do usuário.
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "User.h"

<<<<<<< HEAD
User::User(int id) : m_id(id), m_next(nullptr), m_isRemoved(false) {}

User::~User()
{
}
=======
User::User(int id) : m_id(id) {}
>>>>>>> a3124e1463a91704b75ad7671abd9bba78658d70

void User::terminate()
{
	if (m_next != nullptr) {
		m_next->terminate();
		delete m_next;
	}
}

int User::getId() { return m_id; }

<<<<<<< HEAD
MailBox* User::getBox() { return &m_box; }

User* User::getNext() { return m_next; }

void User::setNext(User* next) { m_next = next; }

bool User::isRemoved() { return m_isRemoved; }

void User::setRemoved(bool value) {
	m_isRemoved = value;
	m_box = MailBox();
}
=======
MailBox *User::getBox() { return &box; }
>>>>>>> a3124e1463a91704b75ad7671abd9bba78658d70
