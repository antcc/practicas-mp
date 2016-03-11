# Name: 	   makefile
# Author: 	   Miguel Lentisco & Antonio Coín
# Description: keep dependencies between files for separate compilation

# Project-specific variables
PROJECTNAME = makes
LIBNAME = shapes
SOURCESMAIN = central.cpp area.cpp
DOCNAME = documentation.html

# Compiler settings
AR = ar
CXX = g++
CXXFLAGS = -I./$(INCLUDE) -Wall -Wextra -pedantic -g -std=c++03
LDFLAGS = -L./$(LIB)
LDLIBS = -l$(LIBNAME)

# Folder names
BIN = bin
LIB = lib
OBJ = obj
SRC = src
INCLUDE = include
DOC = doc

# --- Rules ---

.PHONY: all clean mrproper distribute docs

all: $(LIB)/lib$(LIBNAME).a $(addprefix $(BIN)/, central area)

## make the executables files
$(BIN)/central: $(OBJ)/central.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BIN)/area: $(OBJ)/area.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

## make main .o files
$(OBJ)/central.o: $(SRC)/central.cpp $(INCLUDE)/circle.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/area.o: $(SRC)/area.cpp $(INCLUDE)/circle.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

## create the library
$(LIB)/lib$(LIBNAME).a: $(addprefix $(OBJ)/, circle.o point.o)
	$(AR) rvs $@ $^

## pattern rule for making .o files for the library
$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

docs:
	@doxygen doc/Doxyfile
	@rm -f doc/$(DOCNAME)
	-@ln -s html/files.html doc/$(DOCNAME)	
	@echo "--- Documentación creada en la carpeta doc ---"

tar: clean
	-@rm -f $(BIN)/*
	@tar zcvf $(PROJECTNAME).tgz *

clean:
	@echo "Limpiando..."
	-@rm -f $(OBJ)/*.o  $(OBJ)/*~ $(SRC)/*~ $(INCLUDE)/*~ *~

mrproper: clean
	@echo "Limpiando ejecutables y librerías..."
	-@rm -f $(BIN)/* $(LIB)/*.a
