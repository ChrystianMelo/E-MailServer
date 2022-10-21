#include <iostream>
#include <string>
#include <fstream>

#include "msgassert.h"
#include "memlog.h"

#include "Users.h"
#include "MailBox.h"

#define CADASTRA "CADASTRA"
#define REMOVE "REMOVE"
#define CONSULTA "CONSULTA"
#define ENTREGA "ENTREGA"

/**
 * @brief Le as opcoes da linha de comando e inicializa variaveis
 *
 * @param argv Argumentos passados na execução.
 * @param argc Quantidade de argumentos.
 */
void parse_args(char **argv, int argc, std::string *inputFilename, std::string *outputFilename, std::string *logFilename, bool *accessPattern)
{
	for (int i = 0; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (arg.compare("-i") == 0)
		{
			erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
			std::string arg(argv[i + 1]);
			*inputFilename = arg;
			i++;
		}
		else if (arg.compare("-o") == 0)
		{
			erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
			std::string arg(argv[i + 1]);
			*outputFilename = arg;
			i++;
		}
		else if (arg.compare("-p") == 0)
		{
			erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
			std::string arg(argv[i + 1]);
			*logFilename = arg;
			i++;
		}
		// else if (arg.compare("-l") == 0)
		//{
		*accessPattern = false; // [removido]
								//}
	}
}

/**
 * @brief Main
 *
 * @param argc
 * @param argv
 *      -i "nome do arquivo de entrada" (entrada em formato .ppm)
 *      -o "nome do arquivo de saída" (saída em formato .pgm)
 *      -p log.out (registro de desempenho)
 *      -l (padrão de acesso e localidade) [removido]
 * @return ** int
 */
int main(int argc, char *argv[])
{
	// Por padrão, se espera 4 entradas.
	// erroAssert(argc > 4, "Numero de argumentos minimo para execução não atingido.");

	// Processa os argumentos de entrada.
	std::string inputFilename;
	std::string outputFilename;
	std::string logFilename;
	bool accessPattern;

	// Le os argumentos de entrada do programa.
	parse_args(argv, argc, &inputFilename, &outputFilename, &logFilename, &accessPattern);

	// Trata possiveis erros com as entradas.
	erroAssert(!inputFilename.empty(), "O arquivo de entrada não é válido.");
	erroAssert(!outputFilename.empty(), "O arquivo de saida não é válido.");
	erroAssert(!logFilename.empty(), "O arquivo de log não é válido.");

	// Inicia o mem log.
	iniciaMemLog(logFilename.c_str());

	// Define o memlog de acordo com o padrão de acesso.
	if (accessPattern)
		ativaMemLog();
	else
		desativaMemLog();

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

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
			}
			else
			{
				myfile << "ERRO: CONTA " << id << " JA EXISTENTE" << std::endl;

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
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

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
			}
			else
			{
				users.defineAsRemoved(stoi(id));

				myfile << "OK: CONTA " << id << " REMOVIDA" << std::endl;

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
			}
		}
		else if (command == CONSULTA)
		{
			std::string id(line);
			User *user = users.getUserById(stoi(id));

			if (user == nullptr)
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
			else if (user->isRemoved())
			{
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
			}
			else
			{
				MailBox *box = user->getBox();
				if (box->getSize() == 0)
					myfile << "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA" << std::endl;
				else
				{
					myfile << "CONSULTA " << id << ": " << box->pop() << std::endl;
				}

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
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
			{
				myfile << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
			}
			else
			{
				MailBox *box = user->getBox();
				box->insert(stoi(priority), msg);
				myfile << "OK: MENSAGEM PARA " << id << " ENTREGUE" << std::endl;

				// Faz o registro de memoria
				LEMEMLOG((long int)(&(user)), sizeof(int), user->getId());
			}
		}
	}

	// conclui registro de acesso
	finalizaMemLog();

	// Finaliza a escrita do arquivo.
	myfile.close();

	// Finaliza a leitura do arquivo.
	myfileInput.close();

	return 0;
}