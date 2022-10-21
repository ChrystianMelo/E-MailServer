/**
 * @file User.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
<<<<<<< HEAD
 * @brief
=======
 * @brief Representação do usuário.
>>>>>>> a3124e1463a91704b75ad7671abd9bba78658d70
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef USER_H
#define USER_H

#include <iostream>

#include "MailBox.h"

/**
 * @brief Definição da classe representando o usuário.
 */
class User
{
private:
	/**
	 * @brief Identificador unico do usuário.
	 */
	int m_id;

<<<<<<< HEAD
	MailBox m_box;

	User* m_next;

	bool m_isRemoved;
public:
	User(int id);

	~User();

	void terminate();

	int getId();

	MailBox* getBox();

	User* getNext();

	void setNext(User* next);

	bool isRemoved();

	void setRemoved(bool value);
=======
	/**
	 * @brief Caixa de mensagens do usuário.
	 */
	MailBox box;

	/**
	 * @brief Proximo usuário.
	 */
	User *next;

public:
	/**
	 * @brief Contrutor da classe
	 */
	User(int id);

	/**
	 * @brief Retorna o identificador unico do usuário.
	 */
	int getId();

	/**
	 * @brief Retorna a caixa de mensagens do usuário.
	 */
	MailBox *getBox();

	User *getNext() { return next; }
	void setNext(User *u) { next = u; }
>>>>>>> a3124e1463a91704b75ad7671abd9bba78658d70
};

#endif