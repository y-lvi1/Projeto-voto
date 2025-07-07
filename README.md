Simulação de uma votação com autenticação e restrição de votos.
=======
# 🗳️ Sistema Eleitoral

Projeto desenvolvido utilizando a linguagem C++. Um sistema eleitoral simples que simula as etapas de um processo democrático: cadastro, votação, administração e apuração de resultados.

## 📌 Funcionalidades

- Cadastro de novos usuários
- Login de usuários
- Menu de votação com: - Votação para **Presidente** e **Governador**
- Listagem de candidatos por **cargo**, **partido** ou **todos**
- Área administrativa com:
- Adição e remoção de candidatos
 - Consulta ao resultado das eleições

## 🧰 Tecnologias Utilizadas

- C++
- CMake
- Hash
- Biblioteca `nlohmann/json` para manipulação de arquivos JSON

## ⚠️ Validações

- CPF único por eleitor
- Verificação se o eleitor já votou
- Só permite voto após login
- Só permite cadastrar candidatos com CPF único
- Não permite mais de um voto por pessoa
- Usuário é limitado a um voto por cargo

## 🔐 Fluxo de Uso

1. Abertura do sistema com menu inicial:
   - Cadastro
   - Login
   - Ver resultados
   - Entrar como admin
2. Após o login:
   - Menu de votação
   - Escolha de voto ou listagem de candidatos
3. Após votar:
   - Usuário é redirecionado ao menu de votação
   - Podera votar em um cargo diferente
4. Admin:
   - Pode adicionar ou remover candidatos

 Cada eleitor pode votar apenas uma vez por cargo.


## 👥 Equipe

- Yuri: Lógica do Sistema e Gerenciamento de Dados

- Yago: Interface do Usuário (CLI) e Menu
  
- Jadiel: Segurança, autenticação e administração

## ⚒️ TODO

Projeto ainda em desenvolvimento, com prazo de entrega de somente 14 dias.

- [ ] Adição de votos brancos e nulos
- [ ] Cadastro e Login com senha por hash
- [ ] Interface gráfica
- [ ] Banco de dados com encriptação
- [ ] Mais modularização
