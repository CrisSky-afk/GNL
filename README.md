# 📖 Get Next Line

Implementação do projeto **Get Next Line** da Escola 42, desenvolvida em **C**, com o objetivo de criar uma função capaz de ler uma linha de um descritor de arquivo por vez.

O desafio do projeto é gerenciar corretamente a memória dinâmica, o buffer de leitura e os estados da função, independentemente do tamanho do `BUFFER_SIZE`.

---

## 📖 Sobre o projeto

A função `get_next_line()` permite ler o conteúdo de arquivos e entradas padrão de forma incremental, retornando uma linha completa a cada chamada.

Ao contrário de funções tradicionais que carregam o arquivo inteiro para a memória, a GNL mantém apenas as informações necessárias para entregar a próxima linha solicitada.

---

## 🎯 Objetivos

- Trabalhar com descritores de arquivos;
- Utilizar a função `read()`;
- Gerenciar memória dinâmica;
- Manipular strings manualmente;
- Desenvolver algoritmos independentes do tamanho do buffer;
- Compreender o conceito de estado persistente utilizando variáveis estáticas.

---

# ⚙️ Protótipo da função

```c
char	*get_next_line(int fd);
```

A função deve:

- Retornar a próxima linha disponível;
- Incluir o caractere `'\n'`, quando existir;
- Retornar `NULL` ao chegar ao final do arquivo ou em caso de erro.

---

# 🏗️ Estrutura do projeto

```text
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
│
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
│
├── Makefile
└── tests/
```

---

# ⚙️ Compilação

## Mandatory

```bash
cc -Wall -Wextra -Werror \
get_next_line.c \
get_next_line_utils.c \
main.c
```

---

## Bonus

```bash
cc -Wall -Wextra -Werror \
get_next_line_bonus.c \
get_next_line_utils_bonus.c \
main.c
```

---

# ▶️ Exemplo de uso

Arquivo:

```text
Olá
Mundo
42
```

Código:

```c
int		fd;
char	*line;

fd = open("arquivo.txt", O_RDONLY);

while ((line = get_next_line(fd)))
{
	printf("%s", line);
	free(line);
}
close(fd);
```

Saída:

```text
Olá
Mundo
42
```

---

# ⚙️ BUFFER_SIZE

O comportamento da função deve ser correto independentemente do tamanho definido para o buffer.

Exemplos:

```bash
cc -D BUFFER_SIZE=1 ...
```

```bash
cc -D BUFFER_SIZE=42 ...
```

```bash
cc -D BUFFER_SIZE=9999 ...
```

Todos os testes devem produzir exatamente a mesma saída.

---

# 📂 Mandatory

A parte obrigatória implementa a leitura sequencial de linhas utilizando um único descritor de arquivo por vez.

## Características

- ✅ Retorna uma linha por chamada;
- ✅ Inclui `'\n'` quando presente;
- ✅ Retorna a última linha mesmo sem quebra de linha;
- ✅ Retorna `NULL` ao final do arquivo;
- ✅ Funciona com qualquer `BUFFER_SIZE`;
- ✅ Sem vazamentos de memória.

---

# ⭐ Bonus

A versão bônus adiciona suporte a múltiplos descritores de arquivo simultaneamente.

Isso significa que a função consegue manter o estado de leitura de diferentes arquivos ao mesmo tempo.

Exemplo:

```c
fd1 = open("arquivo1.txt", O_RDONLY);
fd2 = open("arquivo2.txt", O_RDONLY);

printf("%s", get_next_line(fd1));
printf("%s", get_next_line(fd2));

printf("%s", get_next_line(fd1));
printf("%s", get_next_line(fd2));
```

Cada descritor continua exatamente do ponto onde havia parado.

---

## Características do bônus

- ✅ Suporte a múltiplos FDs;
- ✅ Estado independente para cada arquivo;
- ✅ Compatível com qualquer `BUFFER_SIZE`;
- ✅ Sem vazamentos de memória.

---

# 🧠 Funcionamento

A função segue o seguinte fluxo:

```text
Receber fd
    ↓
Ler BUFFER_SIZE bytes
    ↓
Acumular em memória estática
    ↓
Encontrar '\n'
    ↓
Extrair linha completa
    ↓
Atualizar o restante
    ↓
Retornar a linha
```

---

# 🔄 Fluxo da leitura

```text
Arquivo
   ↓
read()
   ↓
Buffer temporário
   ↓
Memória estática
   ↓
Separação da linha
   ↓
Retorno ao usuário
```

---

# 🧪 Testes realizados

## Mandatory

- ✅ Arquivos vazios;
- ✅ Arquivos com várias linhas;
- ✅ Linhas muito longas;
- ✅ BUFFER_SIZE = 1;
- ✅ BUFFER_SIZE grandes;
- ✅ Arquivos sem `'\n'` no final;
- ✅ Final de arquivo;
- ✅ Valgrind sem leaks.

---

## Bonus

- ✅ Leitura alternada entre múltiplos FDs;
- ✅ Arquivos independentes;
- ✅ BUFFER_SIZE variados;
- ✅ Valgrind sem leaks.

---

# 🔐 Tratamento de erros

A função trata corretamente situações como:

- Descritor inválido;
- `BUFFER_SIZE <= 0`;
- Falha em `read()`;
- Final do arquivo;
- Falha em alocação dinâmica.

---

# 📚 Conceitos estudados

Durante o desenvolvimento deste projeto foram explorados conceitos como:

- Descritores de arquivos;
- `read()`;
- Memória dinâmica;
- Variáveis estáticas;
- Manipulação de strings;
- Gerenciamento de recursos;
- Tratamento de erros;
- Leitura incremental.

---

# 🛠️ Tecnologias utilizadas

- Linguagem C;
- GNU Make;
- Função `read()`;
- Valgrind.

---

# 👩‍💻 Autoria

Projeto desenvolvido como parte do currículo da **42**.

Autora:

- **Cristiane Suominsky** (`csuomins` / `cris_sky`)

---

> *"Ler um arquivo inteiro é fácil. O desafio é lembrar exatamente onde você parou."* 📖
