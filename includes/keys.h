#ifndef KEYS_H
# define KEYS_H
# ifdef __linux__
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
#  define A 97
#  define D 100
#  define W 119
#  define S 115
#  define ENTER 65293
#  define SPACE 32
# else
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
#  define A 0
#  define D 2
#  define W 13
#  define S 1
#  define ENTER 36
#  define SPACE 49
# endif

#endif