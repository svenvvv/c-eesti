PROGNAME = eestic_näited
BINDIR = bin
OBJDIR = obj

CC = gcc
LDFLAGS = -lm
CFLAGS = -Wall -Wpedantic -std=c99

SRCS = main.c
OBJS := $(patsubst %.c,%.o, $(SRCS))

.PHONY: default dirs clean all

all: $(PROGNAME)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROGNAME): dirs $(foreach obj,$(OBJS), $(OBJDIR)/$(obj))
	$(CC) -o $(BINDIR)/$(PROGNAME) $(foreach obj,$(OBJS), $(OBJDIR)/$(obj)) $(LDFLAGS)

dirs:
	mkdir -p $(OBJDIR) $(BINDIR)

clean:
	rm -fv $(OBJDIR)/*.o $(BINDIR)/$(PROGNAME)
