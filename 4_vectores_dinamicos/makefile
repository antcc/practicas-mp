# Con un código tan simple, usemos un makefile simplificado
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++03 -pedantic -g

# ************ Generación de ejecutable ************

mostrar: mostrar.cpp
	$(CXX) $(CXXFLAGS) -o mostrar mostrar.cpp

# ************ Limpieza ************
clean :
	-rm calcular ./*~ ./*.o
