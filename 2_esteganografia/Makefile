# Nombres específicos del proyecto
PROJECTNAME = esteganografia
LIBNAME = codificar

# Directorios del proyecto
SRC = src
INC = include
OBJ = obj
LIB = lib
DOC = doc
BIN = bin

# Opciones de compilación
AR = ar
CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g -I./$(INC)
LDFLAGS = -L./$(LIB)
LDLIBS = -l$(LIBNAME)

.PHONY: all docs tar clean mrproper

all: $(BIN)/ocultar $(BIN)/revelar

# ************ Generación de ejecutables *************
$(BIN)/%: $(OBJ)/%.o $(LIB)/lib$(LIBNAME).a
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# ************ Creación de la librería *************
$(LIB)/lib$(LIBNAME).a: $(addprefix $(OBJ)/, codificar.o imagenES.o)
	$(AR) rvs $@ $^

# ************ Compilación de módulos ************
# --- Programas ---
$(OBJ)/revelar.o: $(SRC)/revelar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/ocultar.o: $(SRC)/ocultar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# --- Librería ---
$(OBJ)/%.o : $(SRC)/%.cpp $(INC)/%.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# ************ Generación de documentación ******************
docs:
	@doxygen $(DOC)/doxys/Doxyfile
	@echo "Documentación disponible en $(DOC)/html"

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
