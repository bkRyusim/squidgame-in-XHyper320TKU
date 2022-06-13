#include "game.h"

static int bridge_map[8][2] = {
    {1, 5},
    {2, 6},
    {3, 7},
    {4, 8},
    {9, 13},
    {10, 14},
    {11, 15},
    {12, 16}};

int stage = 0;
int answer[8];
int chance = 0;

void set_answer()
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 8; i++)
        answer[i] = rand() % 2;
}

int game_check(int input)
{
    char passed[] = "Passed!";
    char wrong[] = "Wrong!";
    char invalid[] = "Invalid Button!";

    if (input == bridge_map[stage][0] || input == bridge_map[stage][1])
    {
        if (bridge_map[stage][answer[stage]] == input)
        {
            dot_print_o();
            stage++;
            fnd_print_route(answer, stage);

            if (stage == 8)
            {
                game_end(1);
                return 0;
            }
            else
            {
                clcd_write_string(passed);
                usleep(1000000);
                clcd_clear_display();
            }
        }
        else
        {
            clcd_clear_display();
            dot_print_x();
            game_set_chance(chance - 1);

            if (chance == 0)
            {
                game_end(0);
                return 0;
            }
            else
            {
                clcd_write_string(wrong);
                usleep(1000000);
                clcd_clear_display();
            }
        }
    }
    else
    {
        clcd_write_string(invalid);
        usleep(1000000);
        clcd_clear_display();
    }
    return 1;
}

void game_set_chance(int num)
{
    chance = num;
    led_clear();
    led_print_chance(chance);
}

void game_end(int result)
{
    if (result == 1)
    {
        clcd_write_string("You Win!");
    }
    else
    {
        clcd_write_string("You Lose!");
    }
    usleep(1000000);

    led_clear();
    clcd_clear_display();
    fnd_clear();
    dot_clear();
}
