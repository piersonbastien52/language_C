#ifndef ASK_FOR_H
#define ASK_FOR_H

int ask_for_int(char *message);
int ask_for_limited_int(char *message, int min, int max);
float ask_for_limited_float(char *message, float min, float max);

#endif