/**
 * @file Users.cpp
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Users.h"
#include "msgassert.h"
#include "memlog.h"

Users::Users() : m_size(0), m_top(nullptr)
{
}

Users::~Users()
{
	if (m_top != nullptr)
	{
		m_top->terminate();
		delete m_top;
	}
}

void Users::add(int userId)
{
	User *lastUser = m_top;
	if (m_size == 0)
		m_top = new User(userId);
	else
	{
		for (int i = 1; i < m_size; i++)
			lastUser = lastUser->getNext();
		lastUser->setNext(new User(userId));
	}
	m_size++;

	// Faz o registro de memoria
	ESCREVEMEMLOG((long int)(&(lastUser)), sizeof(int), lastUser->getId());
}

/*
void Users::rm(int userId)
{
	User *actuaUser = m_top;

	if (m_size == 0)
		return;

	if (m_size == 1)
	{
		if (m_top->getId() != userId)
		{
			m_top = nullptr;

			m_size--;
		}
	}
	else
	{
		User *previousUser = m_top;

		for (int i = 1; i < m_size; i++)
		{
			if (actuaUser->getId() != userId)
			{
				previousUser = actuaUser;
				actuaUser = actuaUser->getNext();
			}
			else
				break;
		}

		previousUser->setNext(actuaUser->getNext());
		actuaUser->setNext(nullptr);
		m_size--;
	}
}
*/

void Users::defineAsRemoved(int userId)
{
	User *actuaUser = m_top;

	if (m_size == 0)
		return;

	if (m_size == 1)
	{
		if (m_top->getId() != userId)
		{
			m_top->setRemoved(true);
		}
	}
	else
	{
		for (int i = 1; i < m_size; i++)
		{
			if (actuaUser->getId() != userId)
				actuaUser = actuaUser->getNext();
			else
				break;
		}

		actuaUser->setRemoved(true);
	}
}

User *Users::getUserById(int id)
{
	if (m_size == 0)
		return nullptr;

	User *actualUser = m_top;
	for (int i = 0; i < m_size; i++)
		if (actualUser->getId() != id)
			actualUser = actualUser->getNext();
		else
			return actualUser;

	return nullptr;
}
