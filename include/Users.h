/**
 * @file Users.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef USERS_H
#define USERS_H

#include <iostream>

#include "User.h"

/**
 * @brief Definição da classe para armazenar usuarios
 *
 */
class Users
{
private:
	/**
	 * @brief Primeiro usuário.
	 */
	User *m_top;

	/**
	 * @brief Quantidade de usuários.
	 */
	int m_size;

public:
	/**
	 * @brief Construtor da classe.
	 */
	Users();

	/**
	 * @brief Destrutor da classe.
	 */
	~Users();

	/**
	 * @brief Adiciona usuário.
	 *
	 * @param id Id do novo usuário.
	 */
	void add(int userId);

	/**
	 * @brief Remove usuário(parcialmente).
	 *
	 * @param id Id do usuário a ser removido.
	 */
	void defineAsRemoved(int userId);

	/**
	 * @brief Remove usuário (completamente).
	 *
	 * @param id Id do usuário a ser removido.
	 */
	void rm(int userId);

	/**
	 * @brief Retorna o usuário com o id especificado.
	 *
	 * @param id Id do usuário buscado.
	 *
	 * @return Usuario encontrado ou nullptr.
	 */
	User *getUserById(int id);
};

#endif