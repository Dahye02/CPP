CC = g++
TARGET = app.out
OBJS = main.o kor.o usa.o

CFLAGS = -wall
LDFLAGS = -lc

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^
.c.o:
	$(CC) -c -o $@ $<
clean:
	rm -rf $(OBJS) $(TARGET)


