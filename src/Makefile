# Nome do compilador
CC = gcc

# Flags para o compilador
CFLAGS = -Wall -g

# Nome do executável
EXEC = programa

# Arquivos de código-fonte
SRC = main.c funcoes.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Regras de compilação
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c funcoes.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

# Para evitar que o make tente fazer o arquivo readme.md
.PHONY: clean
