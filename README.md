# Minishell

## Descrição
O Minishell é um projeto desenvolvido na École 42, cujo objetivo é criar um interpretador de comandos minimalista em C, replicando funcionalidades essenciais do Bash.

## Funcionalidades
- Execução de comandos binários presentes no `$PATH`
- Implementação de comandos built-in como `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Suporte a pipes (`|`) para encadeamento de comandos
- Redirecionamento de entrada (`<`), saída (`>` e `>>`)
- Manipulação de sinais (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Suporte a variáveis de ambiente

## Como usar esse repositório
```
  git clone <link do repositório>
  cd <diretório do repositório>
```

## Como Compilar e Executar
```sh
make
./minishell
```

## Dependências
- CC ou Clang
- Make
- Biblioteca `readline`


## Como Usar
Exemplo de uso:
```sh
$ ./minishell
minishell$ echo "Hello, world!"
Hello, world!
minishell$ ls | grep .c
main.c
parser.c
executor.c
minishell$ exit
```


