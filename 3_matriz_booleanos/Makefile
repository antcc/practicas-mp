# Nombre del proyecto
PROJECTNAME = matriz_booleanos

# Opciones del compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++03 -pedantic -g

# Directorios
BIN = bin
DOC = doc
INCLUDE = include
SRC = src

# Fuentes y cabeceras
SOURCES = $(addprefix $(SRC)/, matriz_bit.cpp matriz_operaciones.cpp calcular.cpp)
INC = $(addprefix $(INCLUDE)/, matriz_bit.h matriz_operaciones.h)
INC += $(addprefix $(INCLUDE)/, matriz_bit1.h matriz_bit1.cpp matriz_bit2.h matriz_bit2.cpp matriz_bit3.h matriz_bit3.cpp matriz_bit4.h matriz_bit4.cpp 

.PHONY: docs tar clean

# ************ Generación de ejecutable ************
#Simplificado

$(BIN)/calcular: $(INC) $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

# ************Documentación ***********
docs:
	@doxygen $(DOC)/doxys/Doxyfile
	@echo "Documentación disponible en $(DOC)/html"

# ************ Distribuir ******************
tar: clean
	@tar zcvf $(PROJECTNAME).tgz *

# ************ Limpieza ************
clean:
	-@rm -f $(BIN)/calcular doc/html/* *.o $(SRC)/*~ $(INC)/*~ *~
	@echo "Limpiando..."
