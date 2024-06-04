IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src/obj
LDIR =lib

_DEPS = encode.h decode.h common.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = base64enc.o common.o encode.o decode.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

base64enc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 