# CC := /usr/local/arm-linux-4.1.1/bin/arm-linux-gcc
CC := gcc

OUTPUT		= squidgame
SRCS		= ./src/main.c \
				./src/led.c\
				./src/dot.c\
				./src/fnd.c\
				./src/clcd.c\
				./src/keypad.c\
				./src/game.c

CFLAGS		= -I./lib


$(OUTPUT) : $(SRCS)
	$(CC) $(CFLAGS) -g -o bin/$@ $(SRCS)

xim : $(SRCS)
	@cd /usr/xim && $(MAKE) -s xim_OUTPUT="bin/$(OUTPUT)" \
	xim_PATH="$(PWD)" xim_SRCS="$(SRCS)" xim_CFLAGS="$(CFLAGS)"

clean:
	@rm -f bin/$(OUTPUT)
	@rm -f bin/xim_$(OUTPUT)

