# Nombre del ejecutable
TARGET = ram

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Directorios
IMPL_DIR = ImplementacionClases
CLASS_DIR = Clases

# Archivos fuente
SRCS = $(wildcard $(IMPL_DIR)/*.cc) ram.cc

# Archivos objeto generados
OBJS = $(SRCS:.cc=.o)

# Regla principal
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm -f $(OBJS)

# Regla para compilar archivos .o
$(IMPL_DIR)/%.o: $(IMPL_DIR)/%.cc $(CLASS_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(TARGET) $(OBJS)

# Limpiar completamente
dist-clean: clean
	rm -f *~