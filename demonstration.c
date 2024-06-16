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
static void demonstration_11(const char * const Description);
static void demonstration_12(const char * const Description);
static void demonstration_13(const char * const Description);
static void demonstration_14(const char * const Description);
static void demonstration_15(const char * const Description);
static void demonstration_16(const char * const Description);
static void demonstration_17(const char * const Description);
static void demonstration_18(const char * const Description);
static void demonstration_19(const char * const Description);
static void demonstration_20(const char * const Description);
static void demonstration_21(const char * const Description);
static void demonstration_22(const char * const Description);
static void demonstration_23(const char * const Description);
static void demonstration_24(const char * const Description);
static void demonstration_25(const char * const Description);

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
    {"Formatting Text: Miscellaneous", demonstration_10},
    {"Cursor: Screen Size", demonstration_11},
    {"Cursor: Location", demonstration_12},
    {"Text Manipulation: Insert Character", demonstration_13},
    {"Text Manipulation: Insert String", demonstration_14},
    {"Text Manipulation: Delete String And Characters", demonstration_15},
    {"Text Manipulation: Delete/Insert Multiple Lines", demonstration_16},
    {"Clear: Screen, To EOL, To Bottom", demonstration_17},
    {"Keyboard Input: No Delay", demonstration_18},
    {"Keyboard Input: Disable Get Character Echo", demonstration_19},
    {"Keyboard Input: Special Keys", demonstration_20},
    {"Windows: New Window (Same Size As Standard Screen)", demonstration_21},
    {"Windows: New Window (Smaller Than Standard Screen)", demonstration_22},
    {"Windows: Default Border/Box", demonstration_23},
    {"Windows: Custom Border/Box", demonstration_24},
    {"Subwindows: Data Is Shared", demonstration_25}
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Print Characters */
    move(row++, 0);
    for(i = 0; i < strlen(Description); i++)
    {
        (void)addch(Description[i]);
        (void)refresh();
        (void)napms(25);
    }
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    for(i = 0; i < 21; i++)
    {
        (void)mvprintw(row, 0, "Count: %zu", i);
        (void)refresh();
        (void)napms(50);
    }
    row++;
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Get String */
    (void)mvaddstr(row++, 0, "Enter String: ");
    (void)refresh();
    (void)getnstr(string, sizeof(string));
    (void)mvprintw(row++, 0, "You Entered: %s", string);
    (void)refresh();
    
    /* Get Character */
    (void)mvaddstr(row++, 0, "Enter Character: ");
    (void)refresh();
    c = getch();
    (void)mvprintw(row++, 0, "You Entered: %c", c);
    (void)refresh();
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Print Characters */
    (void)move(row++, 0);
    for(i = 0x00; i < 0x80; i++)
    {
        (void)printw("%02X = ", i);
        (void)addch(A_ALTCHARSET | i);
        (void)addstr("\t");
        if((((i + 1) % 16) == 0) && ((i + 1) != 0x80))
            (void)move(row++, 0);
    }
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
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
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Print Unicode String */
    (void)mvaddwstr(row++, 0, L"👍👎");
    (void)refresh();
    (void)mvaddwstr(row++, 0, GreekLetters);
    (void)refresh();
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Normal */
    (void)attron(A_NORMAL);
    (void)mvaddstr(row++, 0, "A_NORMAL");
    (void)attroff(A_NORMAL);
    (void)refresh();
    
    /* Standout */
    (void)attron(A_STANDOUT);
    (void)mvaddstr(row++, 0, "A_STANDOUT");
    (void)attroff(A_STANDOUT);
    (void)refresh();
    
    /* Underline */
    (void)attron(A_UNDERLINE);
    (void)mvaddstr(row++, 0, "A_UNDERLINE");
    (void)attroff(A_UNDERLINE);
    (void)refresh();
    
    /* Reverse */
    (void)attron(A_REVERSE);
    (void)mvaddstr(row++, 0, "A_REVERSE");
    (void)attroff(A_REVERSE);
    (void)refresh();
    
    /* Blink */
    (void)attron(A_BLINK);
    (void)mvaddstr(row++, 0, "A_BLINK");
    (void)attroff(A_BLINK);
    (void)refresh();
    
    /* Dim */
    (void)attron(A_DIM);
    (void)mvaddstr(row++, 0, "A_DIM");
    (void)attroff(A_DIM);
    (void)refresh();
    
    /* Bold */
    (void)attron(A_BOLD);
    (void)mvaddstr(row++, 0, "A_BOLD");
    (void)attroff(A_BOLD);
    (void)refresh();
    
    /* Reverse And Dim */
    (void)attron(A_REVERSE | A_DIM); // (void)attron(A_REVERSE); (void)attron(A_DIM); Works The Same
    (void)mvaddstr(row++, 0, "A_REVERSE | A_DIM");
    (void)attroff(A_REVERSE | A_DIM);
    (void)refresh();
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Normal */
    (void)attrset(A_NORMAL);
    (void)mvaddstr(row++, 0, "A_NORMAL");
    (void)refresh();
    
    /* Standout */
    (void)attrset(A_STANDOUT);
    (void)mvaddstr(row++, 0, "A_STANDOUT");
    (void)refresh();
    
    /* Underline */
    (void)attrset(A_UNDERLINE);
    (void)mvaddstr(row++, 0, "A_UNDERLINE");
    (void)refresh();
    
    /* Reverse */
    (void)attrset(A_REVERSE);
    (void)mvaddstr(row++, 0, "A_REVERSE");
    (void)refresh();
    
    /* Blink */
    (void)attrset(A_BLINK);
    (void)mvaddstr(row++, 0, "A_BLINK");
    (void)refresh();
    
    /* Dim */
    (void)attrset(A_DIM);
    (void)mvaddstr(row++, 0, "A_DIM");
    (void)refresh();
    
    /* Bold */
    (void)attrset(A_BOLD);
    (void)mvaddstr(row++, 0, "A_BOLD");
    (void)refresh();
    
    /* Reverse | Dim */
    (void)attrset(A_REVERSE | A_DIM);
    (void)mvaddstr(row++, 0, "A_REVERSE | A_DIM");
    (void)refresh();
    
    /* Exit */
    (void)attrset(A_NORMAL);
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Colors */
    (void)attrset(COLOR_PAIR(0));
    (void)mvaddstr(row++, 0, "White On Black");
    (void)attrset(COLOR_PAIR(1));
    (void)mvaddstr(row++, 0, "Blue On Black");
    (void)attrset(COLOR_PAIR(2));
    (void)mvaddstr(row++, 0, "Cyan On Red");
    (void)refresh();
    
    /* Exit */
    (void)attrset(A_NORMAL);
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(0, 0, Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Background 1 */
    (void)bkgd('.');
    (void)mvaddstr(0, 0, Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Background 2 */
    (void)bkgd('*' | COLOR_PAIR(1));
    (void)mvaddstr(0, 0, Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Background 3 */
    (void)bkgd(' ');
    (void)mvaddstr(0, 0, "Press Any Key To Continue...");
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
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    (void)napms(1000);
    
    /* Beep */
    (void)beep();
    (void)mvaddstr(row++, 0, "Beep");
    (void)refresh();
    (void)napms(1000);
    
    /* Flash */
    (void)flash();
    (void)mvaddstr(row++, 0, "Flash");
    (void)refresh();
    (void)napms(1000);
    
    /*** Clean Up ***/
    (void)endwin();
}

/*** Cursor ***/
static void demonstration_11(const char * const Description)
{
    int numCols, numRows, row = 0;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Screen Size */
    (void)getmaxyx(stdscr, numRows, numCols);
    (void)mvprintw(row++, 0, "Rows: %d", numRows);
    (void)refresh();
    (void)mvprintw(row++, 0, "Columns: %d", numCols);
    (void)refresh();
    (void)mvprintw(row++, 0, "Lines: %d", LINES);
    (void)refresh();
    (void)mvprintw(row++, 0, "Columns: %d", COLS);
    (void)refresh();
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_12(const char * const Description)
{
    int row = 0, x, y;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Get String */
    (void)mvaddstr(row++, 0, "Enter String (Ending With '~'):");
    (void)refresh();
    (void)move(row++, 0);
    while(getch() != '~')
        continue;
    
    /* Location */
    (void)addch('\b'); // Before '~'
    (void)getyx(stdscr, y, x);
    (void)mvprintw(row++, 0, "Your '~' Is At Location (%d, %d)", x, y);
    (void)refresh();
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

/*** Text Manipulation ***/
static void demonstration_13(const char * const Description)
{
    size_t i;
    int row = 0;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Insert Characters */
    move(row++, 0);
    for(i = 0; i < strlen(Description); i++)
    {
        (void)insch(Description[strlen(Description) - 1 - i]);
        (void)refresh();
        (void)napms(50);
    }
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_14(const char * const Description)
{
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print String */
    (void)insstr(Description);
    (void)refresh();
    (void)napms(500);
    
    /* Insert String */
    (void)insertln();
    (void)refresh();
    (void)napms(500);
    
    /* Exit */
    (void)insstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_15(const char * const Description)
{
    size_t i;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/ 
    /* Print String */
    (void)addstr(Description);
    (void)refresh();
    (void)napms(500);
    
    /* Delete Characters */
    (void)move(0, 0);
    for(i = 0; i < strlen(Description); i++)
    {
        (void)delch();
        (void)refresh();
        (void)napms(50);
    }
    
    /* Print String */
    (void)addstr(Description);
    (void)refresh();
    (void)napms(500);
    
    /* Delete String */
    (void)move(0, 0);
    (void)deleteln();
    (void)refresh();
    (void)napms(500);
    
    /* Exit */
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_16(const char * const Description)
{    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/ 
    /* Print String */
    (void)addstr(Description);
    (void)refresh();
    (void)napms(1500);
    
    /* Insert Lines */
    (void)move(0, 0);
    (void)insdelln(3);
    (void)addstr("Three Lines Inserted");
    (void)refresh();
    (void)napms(1500);
    
    /* Delete Lines */
    (void)move(0, 0);
    (void)insdelln(-4);
    (void)addstr("Four Lines Deleted");
    (void)refresh();
    (void)napms(1500);
    
    /* Exit */
    (void)move(0, 0);
    (void)insdelln(-1);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

/*** Clear ***/
static void demonstration_17(const char * const Description)
{
    size_t i;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/
    /* Print Strings */
    for(i = 0; i < 20; i++)
    {
        (void)mvaddstr(i, i, Description);
        (void)refresh();
        (void)napms(100);
    }
    
    /* Clear Screen */
    (void)clear();
    (void)mvaddstr(0, 0, "Screen Cleared");
    (void)refresh();
    (void)napms(1500);
    
    /* Print Strings */
    for(i = 0; i < 20; i++)
    {
        (void)mvaddstr(i, i, Description);
        (void)refresh();
        (void)napms(100);
        (void)move(i, i);
        (void)clrtoeol(); // Clear To EOL
    }
    
    /* Clear Screen */
    (void)clear();
    (void)mvaddstr(0, 0, "Screen Cleared");
    (void)refresh();
    (void)napms(1500);
    
    /* Print Strings */
    for(i = 0; i < 20; i++)
        (void)mvaddstr(i, i, Description);
    (void)refresh();
    
    /* Clear To Bottom */
    (void)move(10, 0);
    (void)clrtoeol(); // Clear To EOL
    (void)addstr("Clear To Bottom In 1 Second From Here");
    (void)refresh();
    (void)napms(1000);
    (void)clrtobot();
    (void)refresh();
    (void)napms(1000);
    
    /* Clear Screen */
    (void)clear();
    (void)mvaddstr(0, 0, "Screen Cleared");
    (void)refresh();
    (void)napms(1500);
    
    /* Exit */
    (void)move(0, 0);
    (void)addstr("Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

/*** Keyboard Input ***/
static void demonstration_18(const char * const Description)
{
    int row = 0;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    
    /* No Delay */
    (void)nodelay(stdscr, TRUE);
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(row++, 0, Description);
    (void)mvaddstr(row++, 0, "Press Any Key To Continue");
    (void)refresh();
    
    /* Wait */
    while(getch() == ERR)
    {
        (void)addch('.');
        (void)refresh();
        (void)napms(100);
    }
    
    /* Restore Delay */
    (void)nodelay(stdscr, FALSE);
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_19(const char * const Description)
{
    char password[256];
    int row = 0;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    
    /* Turn Off Echo */
    (void)noecho();
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    
    /* Get Password */
    (void)mvaddstr(row++, 0, "Enter Secret Password: ");
    (void)refresh();
    (void)getnstr(password, sizeof(password));
    (void)mvprintw(row++, 0, "You Entered: %s", password);
    (void)refresh();
    
    /* Turn On Echo */
    (void)echo();
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

static void demonstration_20(const char * const Description)
{
    bool exit = false;
    int row = 0;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    
    /* Enable Special Keys */
    (void)keypad(stdscr, TRUE);
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    (void)mvaddstr(row++, 0, "Press One Of The Arrow Keys (Up, Down, Left, Or Right)");
    (void)refresh();
    
    /* Get Special Key */
    while(!exit)
    {
        switch(getch())
        {
            case KEY_UP:
                (void)mvaddstr(row++, 0, "KEY_UP");
                (void)refresh();
                exit = true;
                break;
            case KEY_DOWN:
                (void)mvaddstr(row++, 0, "KEY_DOWN");
                (void)refresh();
                exit = true;
                break;
            case KEY_LEFT:
                (void)mvaddstr(row++, 0, "KEY_LEFT");
                (void)refresh();
                exit = true;
                break;
            case KEY_RIGHT:
                (void)mvaddstr(row++, 0, "KEY_RIGHT");
                (void)refresh();
                exit = true;
                break;
            default:
                /* Do Nothing */
                break;
        }
    }
    
    /* Disable Special Keys*/
    (void)keypad(stdscr, FALSE);
    
    /* Exit */
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)endwin();
}

/*** Windows ***/
static void demonstration_21(const char * const Description)
{
    WINDOW *newWindow;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    newWindow = newwin(0, 0, 0, 0); // Same Size As Standard Screen
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(0, 0, Description);
    (void)refresh();
    (void)napms(1500);
    
    /* Standard Screen */
    (void)clear();
    (void)bkgd('.');
    (void)mvaddstr(0, 0, "This Is The Standard Screen");
    (void)mvaddstr(1, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /* New Window */
    (void)wbkgd(newWindow, '*');
    (void)mvwaddstr(newWindow, 0, 0, "This Is A New Window");
    (void)mvwaddstr(newWindow, 1, 0, "Press Any Key To Continue...");
    (void)wrefresh(newWindow);
    (void)wgetch(newWindow);
    
    /* Standard Screen */
    (void)touchwin(stdscr); // This Is Necessary If Standard Screen Hasn't Changed; If Standard Screen Hasn't Changed, refresh Won't Show It Again
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)delwin(newWindow);
    (void)endwin();
}

static void demonstration_22(const char * const Description)
{
    WINDOW *newWindow;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    newWindow = newwin(LINES / 2, COLS / 2, LINES / 4, COLS / 4); // 1/2 Size Of Standard Screen
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(0, 0, Description);
    (void)refresh();
    (void)napms(1500);
    
    /* Standard Screen */
    (void)clear();
    (void)bkgd('.');
    (void)mvaddstr(0, 0, "This Is The Standard Screen");
    (void)mvaddstr(1, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /* New Window */
    (void)wbkgd(newWindow, '*');
    (void)mvwaddstr(newWindow, 0, 0, "This Is A New Window");
    (void)mvwaddstr(newWindow, 1, 0, "Press Any Key To Continue...");
    (void)wrefresh(newWindow);
    (void)wgetch(newWindow);
    
    /* Standard Screen */
    (void)touchwin(stdscr); // This Is Necessary If Standard Screen Hasn't Changed; If Standard Screen Hasn't Changed, refresh Won't Show It Again
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)delwin(newWindow);
    (void)endwin();
}

static void demonstration_23(const char * const Description)
{    
    WINDOW *newWindow;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    newWindow = newwin(LINES / 2, COLS / 2, LINES / 4, COLS / 4); // 1/2 Size Of Standard Screen
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(0, 0, Description);
    (void)refresh();
    (void)napms(1500);
    
    /* Standard Screen */
    (void)clear();
    (void)bkgd('.');
    (void)border(0, 0, 0, 0, 0, 0, 0, 0); // 0 (Use Default Characters)
    (void)mvaddstr(2, 2, "This Is The Standard Screen With A Default Border");
    (void)mvaddstr(3, 2, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /* New Window */
    (void)wbkgd(newWindow, '*');
    (void)box(newWindow, 0, 0); // 0 (Use Default Characters)
    (void)mvwaddstr(newWindow, 2, 2, "This Is A New Window Within A Default Box");
    (void)mvwaddstr(newWindow, 3, 2, "Press Any Key To Continue...");
    (void)wrefresh(newWindow);
    (void)wgetch(newWindow);
    
    /* Standard Screen */
    (void)touchwin(stdscr); // This Is Necessary If Standard Screen Hasn't Changed; If Standard Screen Hasn't Changed, refresh Won't Show It Again
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)delwin(newWindow);
    (void)endwin();
}

static void demonstration_24(const char * const Description)
{    
    WINDOW *newWindow;
    
    /*** Set Up ***/
    /* Set Up */
    (void)initscr();
    newWindow = newwin(LINES / 2, COLS / 2, LINES / 4, COLS / 4); // 1/2 Size Of Standard Screen
    
    /*** Run ***/
    /* Print String */
    (void)mvaddstr(0, 0, Description);
    (void)refresh();
    (void)napms(1500);
    
    /* Standard Screen */
    (void)clear();
    (void)bkgd('.');
    (void)border('A', 'B', 'C', 'D', '1', '2', '3', '4');
    (void)mvaddstr(2, 2, "This Is The Standard Screen With A Custom Border");
    (void)mvaddstr(3, 2, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
    
    /* New Window */
    (void)wbkgd(newWindow, '*');
    (void)box(newWindow, ':', '-');
    (void)mvwaddstr(newWindow, 2, 2, "This Is A New Window Within A Custom Box");
    (void)mvwaddstr(newWindow, 3, 2, "Press Any Key To Continue...");
    (void)wrefresh(newWindow);
    (void)wgetch(newWindow);
    
    /* Standard Screen */
    (void)touchwin(stdscr); // This Is Necessary If Standard Screen Hasn't Changed; If Standard Screen Hasn't Changed, refresh Won't Show It Again
    (void)refresh();
    (void)getch();
    
    /*** Clean Up ***/
    (void)delwin(newWindow);
    (void)endwin();
}

/*** Subwindows ***/
static void demonstration_25(const char * const Description)
{
    int row = 0;
    WINDOW* subwindow;
    
    /*** Set Up ***/
    (void)initscr();
    
    /*** Run ***/ 
    /* Print String */
    (void)mvaddstr(row++, 0, Description);
    (void)refresh();
    (void)napms(1500);
    
    /* Subwindow */
    subwindow = subwin(stdscr, LINES - 2, COLS - 2, 1, 1);
    (void)box(subwindow, 0, 0);
    (void)mvwaddstr(subwindow, 2, 2, "This Is A Sub Window");
    (void)mvwaddstr(subwindow, 3, 2, "Press Any Key To Continue...");
    (void)wrefresh(subwindow);
    (void)wgetch(subwindow);
    
    /* Exit */
    (void)mvaddstr(row++, 0, "This Is The Standard Screen, Writing Into The Subwindow");
    (void)mvaddstr(row++, 0, "Press Any Key To Continue...");
    (void)refresh();
    (void)getch();
   
    
    /*** Clean Up ***/
    (void)endwin();
}
