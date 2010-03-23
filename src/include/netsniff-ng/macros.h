/*
 * Copyright (C) 2009, 2010  Daniel Borkmann <daniel@netsniff-ng.org> and 
 *                           Emmanuel Roullit <emmanuel@netsniff-ng.org>
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or (at 
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
 */

/*
 * Contains: 
 *    Macros, defines and versioning stuff
 */

#ifndef _NET_MACROS_H_
#define _NET_MACROS_H_

/* Versioning information */
#define PROGNAME_STRING  "netsniff-ng"
#define VERSION_STRING   "0.5.5.0"

/*
 * Some versioning definition:
 * w.x.y.z 
 * `-+-+-+-- "Huge"  changes ---> These only change on overflow of "Minor"
 *   `-+-+-- "Major" changes _/            - x elem of {0, 1, ..., 9}
 *     `-+-- "Minor" changes, new features - y elem of {0, 1, ..., 9}
 *       `-- "Tiny"  changes, bug fixes    - z elem of {0, 1, ...}
 */

/* Stuff for compiler */
#define likely(x)               __builtin_expect((x), 1)
#define unlikely(x)             __builtin_expect((x), 0)

#define __read_mostly __attribute__((__section__(".data.read_mostly")))

/* Standardized info/warning/error printing routines that should be used source-wide */
#include <errno.h>
#include <string.h>

#define info(fmt, arg...)                                     \
                                fprintf(stdout, fmt, ## arg);

#define warn(fmt, arg...)                                           \
                                fprintf(stderr, "W: " fmt, ## arg); \
                                fflush(stderr);

/* Do not a perror() after this and do not end string with '\n'! */
#define err(fmt, arg...)                                                                      \
                                fprintf(stderr, "E: " fmt ": %s\n", ## arg, strerror(errno)); \
                                fflush(stderr);

/* Calc macros for Byte conversion */
#define DIV_KBYTES(x)           ((x) / (1024LLU))
#define DIV_MBYTES(x)           ((x) / (1048576LLU))
#define DIV_GBYTES(x)           ((x) / (1073741824LLU))

#define DIV_US2HOURS(x)         ((x) / (3600000000LLU))
#define MOD_HOURS2US(x)         ((x) % (3600000000LLU))
#define DIV_US2MINUT(x)         ((x) / (60000000LLU))
#define MOD_MINUT2US(x)         ((x) % (60000000LLU))
#define DIV_US2SECON(x)         ((x) / (1000000LLU))
#define MOD_SECON2US(x)         ((x) % (1000000LLU))
#define DIV_US2MILLI(x)         ((x) / (1000LLU))
#define MOD_MILLI2US(x)         ((x) % (1000LLU))

#define DIV_S2DAYS(x)           ((x) / (86400LLU))
#define MOD_DAYS2S(x)           ((x) % (86400LLU))
#define DIV_S2HOURS(x)          ((x) / (3600LLU))
#define MOD_HOURS2S(x)          ((x) % (3600LLU))
#define DIV_S2MINUT(x)          ((x) / (60LLU))
#define MOD_MINUT2S(x)          ((x) % (60LLU))

/* Release alias, some versioning fun ;) */
#define MOOH     "+-------------------------+     \n" \
                 "| 0xDECA:FBAD:FADE:DEAD^2 |     \n" \
                 "+-------------------------+     \n" \
                 "        \\   ^__^               \n" \
                 "         \\  (oo)\\_______      \n" \
                 "            (__)\\       )\\/\\ \n" \
                 "                ||----w |       \n" \
                 "                ||     ||       \n"

/* Some preprocessor terminal color related stuff */
#define __reset       "0"
#define __bold        "1"

#define __black      "30"
#define __red        "31"
#define __green      "32"
#define __yellow     "33"
#define __blue       "34"
#define __magenta    "35"
#define __cyan       "36"
#define __white      "37"
#define __on_black   "40"
#define __on_red     "41"
#define __on_green   "42"
#define __on_yellow  "43"
#define __on_blue    "44"
#define __on_magenta "45"
#define __on_cyan    "46"
#define __on_white   "47"

/* Some preprocessor hacks */
#define colorize_start(fore)            "\033[" __##fore "m"
#define colorize_start_full(fore, back) "\033[" __##fore ";" __on_##back "m"
#define colorize_end()                  "\033[" __reset "m"

#define colorize_str(fore, text)  	     colorize_start(fore) text colorize_end()
#define colorize_full_str(fore, back, text)  colorize_start_full(fore, back) text colorize_end()

#endif				/* _NET_MACROS_H_ */
