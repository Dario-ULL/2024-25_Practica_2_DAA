# Nombre del ejecutable
TARGET = ram

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Archivos fuente
SRCS = ram.cc

# Archivos objeto generados
OBJS = $(SRCS:.cc=.o)

# Regla principal
all: $(TARGET)

# Regla para compilar el ejecutable y eliminar archivos .o después de la compilación
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm -f $(OBJS)

# Regla para compilar archivos .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(TARGET)

# Limpiar completamente
dist-clean: clean
	rm -f *~
