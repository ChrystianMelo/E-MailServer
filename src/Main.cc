#include <iostream>
#include <string>
#include "Users.h"
#include "MailBox.h"
#include <fstream>

#define CADASTRA "CADASTRA"
#define REMOVE "REMOVE"
#define CONSULTA "CONSULTA"
#define ENTREGA "ENTREGA"

int main(/*char *argv, int argc */)
{
	std::string inputFilename("input2.txt"); //(argv[1]);
	std::string outputFilename("saida.txt"); //(argv[2]);

	Users users = Users();
	int size = 0;

	// Inicia a leitura do arquivo de entrada.
	std::ifstream myfileInput(inputFilename);

	// Inicia a escrita do arquivo de saida.
	std::ofstream myfile;
	myfile.open(outputFilename);

	std::string line("");
	while (getline(myfileInput, line))
	{

		auto pos = line.find(' ');
		std::string command(line.substr(0, pos));
		line = line.substr(pos + 1, line.size() - 1);

		if (command == CADASTRA)
		{
			int id = stoi(line);
			User *user = users.getUserById(id);
			if (user == nullptr)
			{
				size++;

				users.add(id);

				myfile << "OK: CONTA " << id << " CADASTRADA" << std::endl;
			}
			else if (user->isRemoved())
			{
				user->setRemoved(false);
				myfile << "OK: CONTA " << id << " CADASTRADA" << std::endl;
			}
			else
			{
				myfile << "ERRO: CONTA " << id << " JA EXISTENTE" << std::endl;
			}
		}
		else if (command == REMOVE)
		{
			std::string id(line);

			User *user = users.getUserById(stoi(id));

			if (user == nullptr)
			{
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
			}
			else if (user->isRemoved())
			{
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
			}
			else
			{
				users.defineAsRemoved(stoi(id));
				myfile << "OK: CONTA " << id << " REMOVIDA" << std::endl;
			}
		}
		else if (command == CONSULTA)
		{
			std::string id(line);
			User *user = users.getUserById(stoi(id));

			if (user == nullptr)
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
			else if (user->isRemoved())
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
			else
			{
				MailBox *box = user->getBox();
				if (box->getSize() == 0)
					myfile << "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA" << std::endl;
				else
				{
					myfile << "CONSULTA " << id << ": " << box->pop() << std::endl;
				}
			}
		}
		else if (command == ENTREGA)
		{

			auto pos = line.find(' ');
			std::string id(line.substr(0, pos));
			line = line.substr(pos + 1, line.size() - 1);

			pos = line.find(' ');
			std::string priority(line.substr(0, pos));
			line = line.substr(pos + 1, line.size() - 1);

			// Remove o "FIM" no fim da mensagem.
			pos = line.find("FIM"); // o certo seria buscar por " FIM" mas o exemplo mostra usando "FIM"
			line = line.substr(0, pos);

			std::string msg(line);
			User *user = users.getUserById(stoi(id));
			if (user == nullptr)
			{
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
			}
			else if (user->isRemoved())
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
			else
			{
				MailBox *box = user->getBox();
				box->insert(stoi(priority), msg);
				myfile << "OK: MENSAGEM PARA " << id << " ENTREGUE" << std::endl;
			}
		}
	}

	// Finaliza a escrita do arquivo.
	myfile.close();

	// Finaliza a leitura do arquivo.
	myfileInput.close();

	return 0;
}