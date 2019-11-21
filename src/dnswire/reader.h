/*
 * Author Jerry Lundström <jerry@dns-oarc.net>
 * Copyright (c) 2019, OARC, Inc.
 * All rights reserved.
 *
 * This file is part of the dnswire library.
 *
 * dnswire library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dnswire library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with dnswire library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <dnswire/dnswire.h>
#include <dnswire/decoder.h>

#include <stdlib.h>

#ifndef __dnswire_h_reader
#define __dnswire_h_reader 1

struct dnswire_reader {
    struct dnswire_decoder decoder;
    uint8_t*               buf;
    size_t                 size, inc, max, at, left, added;
};

#define DNSWIRE_READER_INITIALIZER                   \
    {                                                \
        .decoder = DNSWIRE_DECODER_INITIALIZER,      \
        .buf     = malloc(DNSWIRE_DEFAULT_BUF_SIZE), \
        .size    = DNSWIRE_DEFAULT_BUF_SIZE,         \
        .inc     = DNSWIRE_DEFAULT_BUF_SIZE,         \
        .max     = DNSWIRE_MAXIMUM_BUF_SIZE,         \
        .at      = 0,                                \
        .left    = 0,                                \
        .added   = 0,                                \
    }

#define dnswire_reader_added(r) (r).added
#define dnswire_reader_dnstap(r) (&(r).decoder.dnstap)
#define dnswire_reader_cleanup(r) \
    free((r).buf);                \
    dnswire_decoder_cleanup((r).decoder)

enum dnswire_result dnswire_reader_set_bufsize(struct dnswire_reader*, size_t);
enum dnswire_result dnswire_reader_set_bufinc(struct dnswire_reader*, size_t);
enum dnswire_result dnswire_reader_set_bufmax(struct dnswire_reader*, size_t);

enum dnswire_result dnswire_reader_add(struct dnswire_reader*, const uint8_t*, size_t);
enum dnswire_result dnswire_reader_read(struct dnswire_reader*, int);

static inline enum dnswire_result dnswire_reader_fread(struct dnswire_reader* handle, FILE* fp)
{
    return dnswire_reader_read(handle, fileno(fp));
}

#endif
