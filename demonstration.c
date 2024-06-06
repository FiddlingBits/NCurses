/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include "demonstration.h"
#include <locale.h>
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
static void demonstration_3(const char * const Description);
static void demonstration_4(const char * const Description);
static void demonstration_5(const char * const Description);
static void demonstration_6(const char * const Description);
static void demonstration_7(const char * const Description);
static void demonstration_8(const char * const Description);
static void demonstration_9(const char * const Description);
static void demonstration_10(const char * const Description);

/****************************************************************************************************
 * Constant
 ****************************************************************************************************/

static const demonstration_list_t demonstration_List[] =
{
    {"Basic Input/Output: Print String And Characters", demonstration_0},
    {"Basic Input/Output: Print Formatted String", demonstration_1},
    {"Basic Input/Output: Get String And Character", demonstration_2},
    {"Basic Input/Output: Alternate Character Set", demonstration_3},
    {"Basic Input/Output: Alternate Character Set (Manual Box Creation)", demonstration_4},
    {"Basic Input/Output: Print Unicode String", demonstration_5},
    {"Formatting Text: Character Attribute On/Off", demonstration_6},
    {"Formatting Text: Character Attribute Set", demonstration_7},
    {"Formatting Text: Character Color", demonstration_8},
    {"Formatting Text: Background", demonstration_9},
    {"Formatting Text: Miscellaneous", demonstration_10}
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

/*** Basic Input/Output ***/
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
    (void)refresh();
    
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
    (void)refresh();
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
    (void)refresh();
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
    (void)refresh();
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
    (void)refresh();
    
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
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_3(const char * const Description)
{
    unsigned int i;
    int row = 0;
    
    /*** Set Up ***/
    setlocale(LC_ALL, "");
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    (void)refresh();
    
    /* Print Characters */
    (void)move(row++, 0);
    for(i = 0x00; i < 0x80; i++)
    {
        (void)printw("%02X = ", i);
        (void)addch(A_ALTCHARSET | i);
        addstr("\t");
        if((((i + 1) % 16) == 0) && ((i + 1) != 0x80))
            (void)move(row++, 0);
    }
    
    /* Exit */
    (void)move(row++, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_4(const char * const Description)
{
    int row = 0;
    
    /*** Set Up ***/
    setlocale(LC_ALL, "");
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    (void)refresh();
    
    /* Print Characters */
    (void)move(row++, 0);
    (void)addch(ACS_ULCORNER);
    (void)addch(ACS_HLINE);
    (void)addch(ACS_URCORNER);
    (void)move(row++, 0);
    (void)addch(ACS_VLINE);
    (void)addch(' ');
    (void)addch(ACS_VLINE);
    (void)move(row++, 0);
    (void)addch(ACS_LLCORNER);
    (void)addch(ACS_HLINE);
    (void)addch(ACS_LRCORNER);
    
    /* Exit */
    (void)move(row++, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_5(const char * const Description)
{
    const wchar_t GreekLetters[] = 
    {
        0x0391, 0x03B1, 0x0392, 0x03B2, 0x0393, 0x03B3, 0x0394, 0x03B4, 0x0395, 0x03B5, 0x0396, 0x03B6,
        0x0397, 0x03B7, 0x0398, 0x03B8, 0x0399, 0x03B9, 0x039A, 0x03BA, 0x039B, 0x03BB, 0x039C, 0x03BC,
        0x039D, 0x03BD, 0x039E, 0x03BE, 0x039F, 0x03BF, 0x03A0, 0x03C0, 0x03A1, 0x03C1, 0x03A3, 0x03C3,
        0x03A4, 0x03C4, 0x03A5, 0x03C5, 0x03A6, 0x03C6, 0x03A7, 0x03C7, 0x03A8, 0x03C8, 0x03A9, 0x03C9,
        '\0'
    };
    int row = 0;
    
    /*** Set Up ***/
    setlocale(LC_ALL, "");
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    (void)refresh();
    
    /* Print Unicode String */
    (void)move(row++, 0);
    (void)addwstr(L"👍👎");
    (void)refresh();
    (void)move(row++, 0);
    (void)addwstr(GreekLetters);
    (void)refresh();
    
    /* Exit */
    (void)move(row++, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

/*** Formatting Text ***/
static void demonstration_6(const char * const Description)
{
    int row = 0;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    (void)refresh();
    
    /* Normal */
    (void)move(row++, 0);
    (void)attron(A_NORMAL);
    (void)addstr("A_NORMAL");
    (void)attroff(A_NORMAL);
    (void)refresh();
    
    /* Standout */
    (void)move(row++, 0);
    (void)attron(A_STANDOUT);
    (void)addstr("A_STANDOUT");
    (void)attroff(A_STANDOUT);
    (void)refresh();
    
    /* Underline */
    (void)move(row++, 0);
    (void)attron(A_UNDERLINE);
    (void)addstr("A_UNDERLINE");
    (void)attroff(A_UNDERLINE);
    (void)refresh();
    
    /* Reverse */
    (void)move(row++, 0);
    (void)attron(A_REVERSE);
    (void)addstr("A_REVERSE");
    (void)attroff(A_REVERSE);
    (void)refresh();
    
    /* Blink */
    (void)move(row++, 0);
    (void)attron(A_BLINK);
    (void)addstr("A_BLINK");
    (void)attroff(A_BLINK);
    (void)refresh();
    
    /* Dim */
    (void)move(row++, 0);
    (void)attron(A_DIM);
    (void)addstr("A_DIM");
    (void)attroff(A_DIM);
    (void)refresh();
    
    /* Bold */
    (void)move(row++, 0);
    (void)attron(A_BOLD);
    (void)addstr("A_BOLD");
    (void)attroff(A_BOLD);
    (void)refresh();
    
    /* Reverse And Dim */
    (void)move(row++, 0);
    (void)attron(A_REVERSE | A_DIM); // (void)attron(A_REVERSE); (void)attron(A_DIM); Works The Same
    (void)addstr("A_REVERSE | A_DIM");
    (void)attroff(A_REVERSE | A_DIM);
    (void)refresh();
    
    /* Exit */
    (void)move(row++, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_7(const char * const Description)
{
    int row = 0;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    (void)refresh();
    
    /* Normal */
    (void)move(row++, 0);
    (void)attrset(A_NORMAL);
    (void)addstr("A_NORMAL");
    (void)refresh();
    
    /* Standout */
    (void)move(row++, 0);
    (void)attrset(A_STANDOUT);
    (void)addstr("A_STANDOUT");
    (void)refresh();
    
    /* Underline */
    (void)move(row++, 0);
    (void)attrset(A_UNDERLINE);
    (void)addstr("A_UNDERLINE");
    (void)refresh();
    
    /* Reverse */
    (void)move(row++, 0);
    (void)attrset(A_REVERSE);
    (void)addstr("A_REVERSE");
    (void)refresh();
    
    /* Blink */
    (void)move(row++, 0);
    (void)attrset(A_BLINK);
    (void)addstr("A_BLINK");
    (void)refresh();
    
    /* Dim */
    (void)move(row++, 0);
    (void)attrset(A_DIM);
    (void)addstr("A_DIM");
    (void)refresh();
    
    /* Bold */
    (void)move(row++, 0);
    (void)attrset(A_BOLD);
    (void)addstr("A_BOLD");
    (void)refresh();
    
    /* Reverse | Dim */
    (void)move(row++, 0);
    (void)attrset(A_REVERSE | A_DIM);
    (void)addstr("A_REVERSE | A_DIM");
    (void)refresh();
    
    /* Exit */
    (void)move(row++, 0);
    (void)attrset(A_NORMAL);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_8(const char * const Description)
{
    int row = 0;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    
    /* Colors */
    if(!has_colors() && !can_change_color())
    {
        printf("%s\r\n", Description);
        printf("  Error: Colors And/Or Changing Colors Not Supported\r\n");
        (void)endwin();
        return;
    }
    (void)start_color();
    (void)init_pair(0, COLOR_WHITE, COLOR_BLACK);
    (void)init_pair(1, COLOR_BLUE, COLOR_BLACK);
    (void)init_pair(2, COLOR_CYAN, COLOR_RED);
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    (void)refresh();
    
    /* Colors */
    (void)move(row++, 0);
    (void)attrset(COLOR_PAIR(0));
    (void)addstr("White On Black");
    (void)move(row++, 0);
    (void)attrset(COLOR_PAIR(1));
    (void)addstr("Blue On Black");
    (void)move(row++, 0);
    (void)attrset(COLOR_PAIR(2));
    (void)addstr("Cyan On Red");
    (void)refresh();
    
    /* Exit */
    (void)move(row++, 0);
    (void)attrset(A_NORMAL);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_9(const char * const Description)
{
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    
    /* Colors */
    if(!has_colors() && !can_change_color())
    {
        printf("%s\r\n", Description);
        printf("  Error: Colors And/Or Changing Colors Not Supported\r\n");
        (void)endwin();
        return;
    }
    (void)start_color();
    (void)init_pair(0, COLOR_WHITE, COLOR_BLACK);
    (void)init_pair(1, COLOR_CYAN, COLOR_RED);
    
    /*** Run ***/
    /* Print String */
    (void)addstr(Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Background 1 */
    (void)bkgd('.');
    (void)move(0, 0);
    (void)addstr(Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Background 2 */
    (void)bkgd('*' | COLOR_PAIR(1));
    (void)move(0, 0);
    (void)addstr(Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Background 3 */
    (void)bkgd(' ');
    (void)move(0, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_10(const char * const Description)
{
    int row = 0;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)move(row++, 0);
    (void)addstr(Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Beep */
    (void)beep();
    (void)move(row++, 0);
    (void)addstr("Beep");
    (void)refresh();
    (void)napms(1000);
    
    /* Flash */
    (void)flash();
    (void)move(row++, 0);
    (void)addstr("Flash");
    (void)refresh();
    (void)napms(1000);
    
    /*** Clean Up ***/
    (void)endwin();
}

