/**
 * @file User.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Caixa de mensagens de email.
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MAIL_BOX_H
#define MAIL_BOX_H

#include <iostream>
#include <string>

#include "memlog.h"

/**
 * @brief Definição da classe que representa o email.
 */
class Mail
{
private:
	/**
	 * @brief Conteudo do email.
	 */
	std::string m_message;

	/**
	 * @brief Prioridade do email.
	 */
	int m_priority;

	/**
	 * @brief Proximo email.
	 */
	Mail *m_next;

public:
	/**
	 * @brief Construtor da classe.
	 *
	 * @param message 	Conteudo do email.
	 * @param priority	Prioridade do email.
	 */
	Mail(std::string message, int priority);

	/**
	 * @brief Retorna o conteudo do email.
	 */
	std::string getMsg();

	/**
	 * @brief Retorna a prioridade do email.
	 */
	int getPriority();

	/**
	 * @brief Define o proximo email
	 *
	 * @param next Proximo email
	 */
	void setNext(Mail *next);

	/**
	 * @brief Define o proximo email
	 *
	 * @param msg 		Conteudo do proximo email
	 * @param priority 	Prioridade do proximo email
	 */
	void setNext(std::string msg, int priority);

	/**
	 * @brief Recupera o proximo email
	 */
	Mail *getNext();

	/**
	 * @brief Destrutor da classe.
	 */
	void deleteMail();
};

/**
 * @brief Definição da classe que representa a caixa de mensagens de email.
 */
class MailBox
{
private:
	/**
	 * @brief A quantidade de email possui na caixa.
	 */
	int m_size;

	/**
	 * @brief Primeiro email na caixa.
	 */
	Mail *m_top;

public:
	/**
	 * @brief Construtor da classe.
	 */
	MailBox();

	/**
	 * @brief Destrutor da classe.
	 */
	~MailBox();

	/**
	 * @brief Retorna a quantidade de email possui na caixa.
	 */
	int getSize();

	/**
	 * @brief Adiciona um email na caixa.
	 *
	 * @param msg 		Conteudo do email
	 * @param priority 	Prioridade do email
	 */
	void insert(int priority, std::string message);

	/**
	 * @brief Remove o email do topo.
	 *
	 * @return Retorna o conteudo do email removido.
	 */
	std::string pop();
};

#endif