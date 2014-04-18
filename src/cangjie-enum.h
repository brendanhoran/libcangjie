/* Copyright (c) 2013-2014 - The libcangjie authors.
 *
 * This file is part of libcangjie.
 *
 * libcangjie is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libcangjie is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libcangjie.  If not, see <http://www.gnu.org/licenses/>.
 */


/* inclusion guard */
#ifndef __CANGJIE_ENUMS_H__
#define __CANGJIE_ENUMS_H__

#if !defined (__CANGJIE_H__) && !defined (CANGJIE_COMPILATION)
#error "Only <cangjie.h> can be included directly."
#endif

#include <glib-object.h>

G_BEGIN_DECLS

typedef enum {
    CANGJIE_FILTER_ALL         = 0,
    CANGJIE_FILTER_BIG5        = (1 << 0),
    CANGJIE_FILTER_HKSCS       = (1 << 1),
    CANGJIE_FILTER_PUNCTUATION = (1 << 2),
    CANGJIE_FILTER_CHINESE     = (1 << 3),
    CANGJIE_FILTER_ZHUYIN      = (1 << 4),
    CANGJIE_FILTER_KANJI       = (1 << 5),
    CANGJIE_FILTER_KATAKANA    = (1 << 6),
    CANGJIE_FILTER_HIRAGANA    = (1 << 7),
    CANGJIE_FILTER_SYMBOLS     = (1 << 8),
} CangjieFilterFlags;

#define CANGJIE_TYPE_FILTER_FLAGS cangjie_filter_flags_get_type()
GType cangjie_filter_flags_get_type (void);


typedef enum {
    CANGJIE_VERSION_CJ3 = 3,
    CANGJIE_VERSION_CJ5 = 5,
} CangjieVersion;

#define CANGJIE_TYPE_VERSION cangjie_version_get_type()
GType cangjie_version_get_type (void);

G_END_DECLS

#endif
