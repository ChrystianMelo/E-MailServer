/**
 * @file MailBox.cpp
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Caixa de mensagens de email.
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "MailBox.h"

Mail::Mail(std::string message, int priority) : m_message(message), m_priority(priority), m_next(nullptr) {}

std::string Mail::getMsg() { return m_message; }

int Mail::getPriority() { return m_priority; }

void Mail::setNext(Mail *next) { m_next = next; }

void Mail::setNext(std::string msg, int priority) { m_next = new Mail(msg, priority); }

Mail *Mail::getNext() { return m_next; }

void Mail::deleteMail()
{
	if (m_next != nullptr)
		m_next->deleteMail();
	delete m_next;
}

MailBox::MailBox() : m_size(0) {}

MailBox::~MailBox()
{
	// Libera recursivamente a memoria
	m_top->deleteMail();

	// Libera a memoria do primieor email.
	delete m_top;
}

int MailBox::getSize() { return m_size; }

void MailBox::insert(int priority, std::string message)
{
	if (m_size == 0)
	{
		m_top = new Mail(message, priority);
	}
	else
	{
		if (priority > m_top->getPriority())
		{
			Mail *actualMail = m_top;
			m_top = new Mail(message, priority);
			m_top->setNext(actualMail);
		}
		else
		{
			Mail *previousMail = m_top;
			Mail *actualMail = m_top;

			for (int i = 0; i < m_size; i++)
			{
				if (priority <= actualMail->getPriority())
				{
					previousMail = actualMail;
					actualMail = actualMail->getNext();
				}
				else
					break;
			}

			previousMail->setNext(message, priority);
			previousMail->getNext()->setNext(actualMail);
		}
	}
	m_size++;

	ESCREVEMEMLOG((long int)(m_top + (m_size - 1)), sizeof(Mail), m_size - 1);
}

std::string MailBox::pop()
{
	const std::string msg = m_top->getMsg();

	LEMEMLOG((long int)(m_top), sizeof(Mail), 0);

	m_top = m_top->getNext();
	m_size--;

	return msg;
}