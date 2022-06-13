//-------| src/main.c |-------//
#include "main.h"

static off_t IEB_DOT[MAX_DOT] = {
	IEB_DOT1,
	IEB_DOT2,
	IEB_DOT3,
	IEB_DOT4,
	IEB_DOT5
};

static off_t IEB_FND[MAX_FND] = {
	IEB_FND0,
	IEB_FND1,
	IEB_FND2,
	IEB_FND3,
	IEB_FND4,
	IEB_FND5,
	IEB_FND6,
	IEB_FND7
};

static int fd;
static int map_counter = 0;
static void *map_data[100];

int main(int argc, char *argv[])
{

	int i;
	short *led, *dot[MAX_DOT], *fnd[MAX_FND];
	short *clcd_cmd, *clcd_data, *keypad_out, *keypad_in;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if (fd == -1)
	{
		fprintf(stderr, "Cannot open /dev/mem file");
		exit(EXIT_FAILURE);
	}

	led = mapper(IEB_LED);

	for (i = 0; i < MAX_DOT; i++)
	{
		dot[i] = mapper(IEB_DOT[i]);
	}

	for (i = 0; i < MAX_FND; i++)
	{
		fnd[i] = mapper(IEB_FND[i]);
	}

	clcd_cmd = mapper(IEB_CLCD_CMD);
	clcd_data = mapper(IEB_CLCD_DATA);

	keypad_out = mapper(IEB_KEY_W);
	keypad_in = mapper(IEB_KEY_R);

	init_led(led);
	init_dot(dot);
	init_fnd(fnd);
	init_clcd(clcd_cmd, clcd_data);
	init_keypad(keypad_out, keypad_in);

	set_answer();

	switch (argc)
	{
	case 1:
		game_set_chance(NORMAL);
		break;

	case 2:
		if (strcmp(argv[1], "EASY") == 0)
			game_set_chance(EASY);
		else if (strcmp(argv[1], "NORMAL") == 0)
			game_set_chance(NORMAL);
		else if (strcmp(argv[1], "HARD") == 0)
			game_set_chance(HARD);
		else
		{
			printf("Usage : Invalid argument in argv[1]. Only 3 types exists.(EASY, NORMAL, HARD)\n");
			return 0;
		}

		break;

	default:
		printf("Usage : Too many arguments\n");
		return 0;
	}

	clcd_clear_display();
	fnd_clear();
	dot_clear();

	while (input_mode() == TRUE)
	{
	}

	unmapper();
	close(fd);
	return 0;
}

short *mapper(off_t offset)
{

	map_data[map_counter] = mmap(NULL, sizeof(short), PROT_WRITE, MAP_SHARED, fd, offset);

	if (map_data[map_counter] == MAP_FAILED)
	{
		fprintf(stderr, "Cannot do mmap()");
		emergency_closer();
	}

	return (short *)map_data[map_counter++];
}

void unmapper()
{

	int i;

	for (i = 0; i < map_counter; i++)
	{
		munmap(map_data[i], sizeof(short));
	}

	map_counter = 0;
}

void emergency_closer()
{

	unmapper();
	close(fd);
	exit(EXIT_FAILURE);
}

truth_t input_mode()
{

	int key_count, key_value;
	char clcd_str[] = "Too much Button Pressed!!";
	int check_result;
	truth_t result;

	key_count = keypad_read(&key_value);

	if (key_count == 1)
	{
		check_result = game_check(key_value);
		if (check_result)
			result = TRUE;
		else
			result = FALSE;
		return result;
	}

	else if (key_count > 1)
	{
		clcd_write_string(clcd_str);
	}

	return TRUE;
}
