# Nombre del proyecto
PROJECTNAME = matrizBooleanos

# Opciones del compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++03 -pedantic -g -I./$(INCLUDE)

# Directorios
BIN = bin
DOC = doc
INCLUDE = include
SRC = src

# Fuentes y cabeceras
SOURCESMAIN = $(addprefix $(SRC)/, matriz_bit.cpp matriz_operaciones.cpp calcular.cpp)
SOURCES = $(addprefix $(SRC)/, matriz_bit1.cpp matriz_bit2.cpp matriz_bit3.cpp matriz_bit4.cpp)
INC = $(addprefix $(INCLUDE)/, matriz_bit.h matriz_operaciones.h)
INC += $(addprefix $(INCLUDE)/, matriz_bit1.h matriz_bit2.h matriz_bit3.h matriz_bit4.h)

.PHONY: docs tar clean

# ************ Generación de ejecutable ************

$(BIN)/calcular: $(INC) $(SOURCES) $(SOURCESMAIN)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCESMAIN)

# ************Documentación ***********
docs:
	@doxygen $(DOC)/doxys/Doxyfile
	@echo "Documentación disponible en $(DOC)/html"

# ************ Distribuir ******************
tar: clean
	@tar zcvf $(PROJECTNAME).tgz *

# ************ Limpieza ************
clean:
	-@rm -f $(BIN)/calcular doc/html/* *.o $(SRC)/*~ $(INCLUDE)/*~ *~
	@echo "Limpiando..."
