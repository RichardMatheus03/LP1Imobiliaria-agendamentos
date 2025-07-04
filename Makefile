# Nome do executável final
EXEC = imobiliaria

CXX = g++
CXXFLAGS = -Wall -Wextra -g3

# Encontra automaticamente todos os ficheiros fonte .cpp no diretório atual
SRCS = $(wildcard *.cpp)

# Gera os nomes dos ficheiros objeto (.o) a partir dos ficheiros fonte (.cpp)
# Ex: main.cpp imovel.cpp -> main.o imovel.o
OBJS = $(SRCS:.cpp=.o)


all: $(EXEC)


$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Remove o executável e os ficheiros objeto automaticamente
clean:
	rm -f $(EXEC) $(OBJS)
