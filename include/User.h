/**
 * @file User.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe armazenando informaçoẽs do usário.
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
 * @brief Definicação da classe para armazenar as informaçoẽs do usário.
 *
 */
class User
{
private:
	/**
	 * @brief Identificador unico do usuário.
	 */
	int m_id;

	/**
	 * @brief Caixa de emails.
	 */
	MailBox m_box;

	/**
	 * @brief Próximo usuário.
	 */
	User *m_next;

	/**
	 * @brief Flag representando se o usuário está definido como excluído.
	 */
	bool m_isRemoved;

public:
	/**
	 * @brief Contrutor da classe
	 *
	 * @param id Identificador unico do usuário.
	 */
	User(int id);

	/**
	 * @brief Destrutor da classe
	 */
	~User();

	/**
	 * @brief Finaliza os usos de memória da classe.
	 */
	void terminate();

	/**
	 * @brief Retorna o dentificador unico do usuário.
	 */
	int getId();

	/**
	 * @brief Retorna a caixa de emails.
	 */
	MailBox *getBox();

	/**
	 * @brief Retorna o proximo usuario.
	 *
	 * @return Proximo usuario.
	 */
	User *getNext();

	/**
	 * @brief Define o proximo usuario.
	 *
	 * @param next Proximo usuário.
	 */
	void setNext(User *next);

	/**
	 * @brief Retorna a flag representando se o usuário está definido como excluído.
	 */
	bool isRemoved();

	/**
	 * @brief Define a flag representando se o usuário está definido como excluído.
	 */
	void setRemoved(bool value);
};

#endif