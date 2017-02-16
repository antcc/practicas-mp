# Nombre del proyecto
PROJECTNAME = conectaN

# Directorios del proyecto
SRC = src
INC = include
OBJ = obj
DOC = doc
BIN = bin
DEBUG = debug

# Opciones de compilación
AR = ar
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++03 -g -I./$(INC)

# Archivos del proyecto
SOURCES := matriz.cpp tablero.cpp jugador.cpp
INCLUDES := $(addprefix $(INC)/, $(SOURCES:.cpp=.hpp))
OBJECTS := $(addprefix $(OBJ)/, $(SOURCES:.cpp=.o))
SOURCES := $(addprefix $(SRC)/, $(SOURCES))

.PHONY: docs tar clean mrproper

# ************ Generación de ejecutables *************
# -- Programa principal --
$(BIN)/conectaN: $(OBJ)/conectaN.o $(OBJECTS)
	$(CXX) -o $@ $^

# -- Debug --
$(DEBUG)/debug-%: $(DEBUG)/debug-%.o $(OBJECTS)
	$(CXX) -o $@ $^

# ************ Compilación de módulos ************
# -- Programa principal --
$(OBJ)/conectaN.o: $(SRC)/conectaN.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/%.o: $(SRC)/%.cpp $(INC)/%.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# -- Debug --
$(DEBUG)/debug-%.o: $(DEBUG)/debug-%.cpp $(INC)/%.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# -- Dependencias adicionales --
$(OBJ)/tablero.o: $(INC)/matriz.hpp

$(OBJ)/jugador.o: $(INC)/tablero.hpp

# ************ Generación de documentación ******************
docs:
	@doxygen $(DOC)/doxys/Doxyfile
	@echo "-- Documentación disponible en $(DOC)/html --"

# ************ Distribuir ******************
tar: mrproper
	@tar zcvf $(PROJECTNAME).tgz *

# ************ Limpieza ************
clean :
	-@rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ *~
	@echo "Limpiando..."

mrproper : clean
	-@rm -f $(BIN)/* doc/html/* $(LIB)/*.a
	@echo "Limpieza completada"
