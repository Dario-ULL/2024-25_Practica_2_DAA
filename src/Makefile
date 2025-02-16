# Variables
CC = g++
CFLAGS = -Wall -std=c++11
OBJ_DIR = ImplementacionClases
INC_DIR = Clases
SRC_DIR = $(OBJ_DIR)
MAIN_SRC = ram.cc
EXEC = ram

# Archivos objeto, con todos los archivos fuente de .cc a .o
OBJ_FILES = $(OBJ_DIR)/aluUnit.o \
            $(OBJ_DIR)/dataMemory.o \
            $(OBJ_DIR)/inputUnit.o \
						$(OBJ_DIR)/programMemory.o \
            $(OBJ_DIR)/lectorFichero.o \
            $(OBJ_DIR)/outputUnit.o \
            $(OBJ_DIR)/instruccion.o \
            $(OBJ_DIR)/Instrucciones/instruccionLoad.o

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJ_FILES) $(MAIN_SRC)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(MAIN_SRC) -o $(EXEC)

# Regla para compilar los archivos .cc a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Regla para compilar archivos .cc en el subdirectorio Instrucciones
$(OBJ_DIR)/Instrucciones/%.o: $(SRC_DIR)/Instrucciones/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Limpiar los archivos objeto y ejecutables generados
clean:
	rm -f $(OBJ_FILES)

# Regla para limpiar todo
fclean: clean
	rm -f $(EXEC)

# Regla para recompilar todo
re: fclean all
