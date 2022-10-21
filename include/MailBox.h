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
	 * @brief Prioridade do email.
	 */
	void setNext(Mail *next);
	void setNext(std::string msg, int priority);
	Mail *getNext();
};

/**
 * @brief Definicação da classe para armazenar dados de arquivos graficos do tipo PGM.
 *
 */
class MailBox
{
private:
	int m_size;
	Mail *m_top;

public:
	MailBox();

	~MailBox();
	int getSize();
	std::string toString();
	void insert(int priority, std::string message);
	std::string pop();
};

#endif