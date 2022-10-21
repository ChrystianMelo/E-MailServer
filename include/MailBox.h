/**
 * @file User.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Caixa de emails.
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

/**
 * @brief Email.
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
	 * @param priority 	Prioridade do email.
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
	 * @brief Define o proximo email.
	 *
	 * @param next Proximo email.
	 */
	void setNext(Mail *next);

	/**
	 * @brief Define o proximo email.
	 *
	 * @param message 	Conteudo do email.
	 * @param priority 	Prioridade do email.
	 */
	void setNext(std::string msg, int priority);

	/**
	 * @brief Retorna o proximo email.
	 *
	 * @return Proximo email ou nullptr.
	 */
	Mail *getNext();
};

/**
 * @brief Definicação da classe para caixa de emails.
 *
 */
class MailBox
{
private:
	/**
	 * @brief Quantidade de mensagens na caixa de entrada.
	 */
	int m_size;

	/**
	 * @brief Primeira mensagem na caixa de entrada.
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
	 * @brief Retorna a quantidade de emails na caixa de entrada.
	 */
	int getSize();

	/**
	 * @brief Adiciona uma mensagem na caixa de entrada.
	 *
	 * @param message 	Conteudo do email.
	 * @param priority 	Prioridade do email.
	 */
	void insert(int priority, std::string message);

	/**
	 * @brief Remove a primeira mensagem.
	 *
	 * @return Retorna o conteudo da mensagem.
	 */
	std::string pop();
};

#endif