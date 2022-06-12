/**
 * @file display.h
 * @author Lucas Pfeiffer
 * @brief Contains all enums, structs, and functions involving displaying to the console
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#define SCREEN_DIVIDER "----------------------------------------------\n"

/*
    ANSI color codes found from
    https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
*/
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

bool GetUserFormattedInput(char * output, char * format, int numFields, ...);
void ClearScreen(void);

#endif /* DISPLAY_H */

/*** end of file ***/