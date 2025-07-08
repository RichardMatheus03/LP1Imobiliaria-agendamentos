# Nome do executável final
EXEC = imobiliaria

# Compilador e flags
CXX = g++
# Adicionamos -Isrc para que o compilador encontre os ficheiros .h dentro da pasta src
CXXFLAGS = -Wall -Wextra -g3 -Isrc

# Encontra automaticamente todos os ficheiros fonte .cpp no diretório src
SRCS = $(wildcard src/*.cpp)

# Gera os nomes dos ficheiros objeto (.o) a partir dos nomes em SRCS,
# mas remove o prefixo "src/" para que os .o sejam criados no diretório atual.
# Ex: src/main.cpp -> main.o
OBJS = $(notdir $(SRCS:.cpp=.o))

# --- REGRAS ---

# Regra padrão: compila tudo
all: $(EXEC)

# Regra para linkar e criar o executável final
# Esta regra não precisa de alteração
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Executável '$(EXEC)' criado com sucesso!"

# Regra para compilar um ficheiro .o a partir de um .cpp que está na pasta src
# Ex: para criar main.o, ele vai procurar por src/main.cpp
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os ficheiros gerados
# Esta regra também não precisa de alteração
clean:
	rm -f $(EXEC) $(OBJS)
	@echo "Ficheiros compilados foram removidos."

# Alvos "falsos" que não são nomes de ficheiros
.PHONY: all clean