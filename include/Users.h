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
  * @brief Definicação da classe para armazenar usuarios
  *
  */
class Users
{
private:
	User* m_top;
	int m_size;
public:
	Users();
	~Users();
	void add(int userId);
	void rm(int userId);
	User* getUserById(int id);

	void defineAsRemoved(int userId);
};

#endif