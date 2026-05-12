CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = ciphers
SRC = ciphers.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

tar:
	tar -czf CS2600_Cipher.tar.gz ciphers.c README.md Makefile
