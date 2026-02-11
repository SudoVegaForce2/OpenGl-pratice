CC = gcc

OPENGL_CFLAGS = -I/mnt/c/Users/Hamza/OneDrive/Documents/C/folder/glew-2.3.1/glfw-3.4/glfw-3.4/include
OPENGL_LDFLAGS = -L/mnt/c/Users/Hamza/OneDrive/Documents/C/folder/glew-2.3.1/glfw-3.4/glfw-3.4/build/src
OPENGL_LIBS = -lglfw3 -lGLEW -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm


CFLAGS = -Wall -Wextra -O2 $(OPENGL_CFLAGS)


TARGET = line_program


all: $(TARGET)

$(TARGET): Line.c
	$(CC) $(CFLAGS) Line.c $(OPENGL_LDFLAGS) $(OPENGL_LIBS) -o $(TARGET)


run: all
	./$(TARGET)


clean:
	rm -f $(TARGET)

.PHONY: all run clean
