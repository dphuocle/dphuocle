C=gcc
CFLAGS=-W -Wall -std=c99
LDFLAGS=
EXEC=app
SRC= ../generator/generator.c app.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

app: $(OBJ)
    $(CC) -o $@ $^ $(LDFLAGS)
    
    
%.o: %.c
    $(CC) -o $@ -c $< $(LDFLAGS) -I../generator
    
.PHONY: clear mrproper

clean:
   rm        
