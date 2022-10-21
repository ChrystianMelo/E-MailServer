E-mail Server

Este trabalho prático tem por objetivo implementar um simulador de um servidor
de emails. O sistema simulado terá suporte ao gerenciamento de contas, assim como
à entrega de mensagens de um usuário para outros. 

O programa foi desenvolvido na linguagem C++, compilada pelo compilador G++
da GNU Compiler Collection. Foram usados conceitos de tipos abstratos de dados, em
particular a sua abstração, desempenho e robustez. Como estruturadas de dados foram 
usadas lista para armazenar os usuários e uma fila de prioridade para a caixa de emails.

O foco da simulação será verificar o funcionamento correto do sistema ao executar as
diversas operações do servidor em diferentes situações 
(Cadastro de usuários/Remover usuários/Entregar email/Consultar email).

  ● Cadastrar novo usuário: esta operação cria uma caixa de entrada para o
novo usuário. A nova caixa de entrada deverá estar vazia, ou seja, sem
nenhuma mensagem armazenada. Após a criação da conta e enquanto
ela não for removida, todas as mensagens enviadas para esse usuário
devem ser armazenadas em sua caixa de entrada. ○ Importante: você não
pode assumir um número predeterminado de contas de usuário. Isso
significa que o sistema não deve ter um número fixo ou máximo de contas
de usuário. Cada conta criada deve ser alocada dinamicamente, e a
memória utilizada por ela deve ser liberada se a conta for removida.

  ● Remover usuário: esta operação remove um usuário do sistema. Todas as
mensagens em sua caixa de entrada devem ser automaticamente
apagadas. Após a conta ser removida, mensagens recebidas pelo servidor
e destinadas a esse usuário não devem ser aceitas.

  ● Entregar email: esta operação recebe um novo email destinado a
determinado usuário. Caso o usuário não exista (ou seja, não tenha criado
uma conta ou essa tenha sido removida), a mensagem deve ser recusada
e gerar um erro. Se o usuário possuir uma caixa de entrada no servidor, a
mensagem deve ser armazenada em ordem de prioridade na caixa de
entrada desse usuário. Isso quer dizer que mensagens com prioridade
mais alta devem ser armazenadas à frente de mensagens com prioridade
mais baixa. Caso dois emails tenham a mesma prioridade, aquele que foi
recebido primeiro pelo servidor deverá ficar à frente.

  ● Consultar email: esta operação recebe o identificador de um usuário e
deverá retornar a próxima mensagem na caixa de entrada do usuário,
segundo a prioridade descrita acima. Caso o usuário não exista, o servidor
deve retornar um erro. Em caso de sucesso, a mensagem retornada
deverá ser removida da caixa do usuário.
