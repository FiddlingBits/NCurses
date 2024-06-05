/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "demonstration.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************************************
 * Type Definition
 ****************************************************************************************************/

typedef struct demonstration_list_s
{
    char *description;
    void (*demonstration)(const char * const Description);
} demonstration_list_t;

/****************************************************************************************************
 * Function Prototype
 ****************************************************************************************************/

static void demonstration_0(const char * const Description);
static void demonstration_1(const char * const Description);
static void demonstration_2(const char * const Description);

/****************************************************************************************************
 * Constant
 ****************************************************************************************************/

static const demonstration_list_t demonstration_List[] =
{
    {"Basic Input/Output: Print String And Characters", demonstration_0},
    {"Basic Input/Output: Print Formatted String", demonstration_1},
    {"Basic Input/Output: Get String And Character", demonstration_2}
};
static const size_t demonstration_ListCount = sizeof(demonstration_List) / sizeof(demonstration_List[0]);

/****************************************************************************************************
 * Function Definition (Public)
 ****************************************************************************************************/

/*** Demonstration ***/
void demonstration(int argc, char *argv[])
{
    size_t demonstration;
    size_t i;
    
    if(argc == 2)
    {
        demonstration = strtoul(argv[1], NULL, 10);
        if(demonstration < demonstration_ListCount)
            demonstration_List[demonstration].demonstration(demonstration_List[demonstration].description);
        else
            (void)printf("Invalid Demonstration Number: %zu\n", demonstration);
    }
    else
    {
        (void)printf("usage: %s [NUMBER]\n", argv[0]);
        for(i = 0; i < demonstration_ListCount; i++)
            (void)printf("  [%zu] %s\n", i, demonstration_List[i].description);
    }
}

/****************************************************************************************************
 * Function Definition (Private)
 ****************************************************************************************************/

static void demonstration_0(const char * const Description)
{
    size_t i;
    int row = 0;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    
    /* Print Characters */
    (void)move(row++, 0);
    for(i = 0; i < strlen(Description); i++)
    {
        (void)addch(Description[i]);
        (void)refresh();
        (void)napms(25);
    }
    
    /* Exit */
    (void)move(row++, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_1(const char * const Description)
{
    size_t i;
    int row = 0;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    for(i = 0; i < 21; i++)
    {
        (void)move(row, 0);
        (void)printw("Count: %zu", i);
        (void)refresh();
        (void)napms(50);
    }
    row++;
    
    /* Exit */
    (void)move(row++, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_2(const char * const Description)
{
    int c, row = 0;
    char string[256];
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    
    /* Get String */
    (void)move(row++, 0);
    (void)addstr("Enter String: ");
    (void)refresh();
    (void)getnstr(string, sizeof(string));
    (void)move(row++, 0);
    (void)printw("You Entered: %s", string);
    (void)refresh();
    
    /* Get Character */
    (void)move(row++, 0);
    (void)addstr("Enter Character: ");
    (void)refresh();
    c = getch();
    (void)move(row++, 0);
    (void)printw("You Entered: %c", c);
    (void)refresh();
    
    /* Exit */
    (void)move(row++, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}
