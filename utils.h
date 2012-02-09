/*-
 * Copyright (c) 2011 Ganael LAPLANCHE <ganael.laplanche@martymac.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _UTILS_H
#define _UTILS_H

#include "types.h"
#include "options.h"

/* stat(2) */
#include <sys/types.h>
#include <sys/stat.h>

/* getpagesize(2) */
#include <unistd.h>
#define PAGE_MASK     (getpagesize() - 1)
#define round_page(x) ((((unsigned long)(x)) + PAGE_MASK) & ~(PAGE_MASK))

#define round_num(x, y) \
    ((((x) % (y)) != 0) ? ((x / y) * y + y) : x)

#define rewind_list(head) \
    { while((head) && (head)->prevp) { (head) = (head)->prevp; } }
#define fastfw_list(head) \
    { while((head) && (head)->nextp) { (head) = (head)->nextp; } }

#define min(x, y) ((x <= y) ? x : y)

unsigned int get_num_digits(double i);
fsize_t get_size(char *file_path, struct stat *file_stat,
    struct program_options *options);

#endif /* _UTILS_H */
