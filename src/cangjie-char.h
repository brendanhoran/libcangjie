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
#ifndef __CANGJIE_CHAR_H__
#define __CANGJIE_CHAR_H__

#if !defined (__CANGJIE_H__) && !defined (CANGJIE_COMPILATION)
#error "Only <cangjie.h> can be included directly."
#endif

#include <glib-object.h>
/*
 * Potentially, include other headers on which this header depends.
 */

/*
 * Type macros.
 */
#define CANGJIE_TYPE_CHAR                  (cangjie_char_get_type ())
#define CANGJIE_CHAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), CANGJIE_TYPE_CHAR, CangjieChar))
#define CANGJIE_IS_CHAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CANGJIE_TYPE_CHAR))
#define CANGJIE_CHAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), CANGJIE_TYPE_CHAR, CangjieCharClass))
#define CANGJIE_IS_CHAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), CANGJIE_TYPE_CHAR))
#define CANGJIE_CHAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), CANGJIE_TYPE_CHAR, CangjieCharClass))

typedef struct _CangjieChar        CangjieChar;
typedef struct _CangjieCharClass   CangjieCharClass;
typedef struct _CangjieCharPrivate CangjieCharPrivate;

struct _CangjieChar
{
    /* Parent instance structure */
    GObject parent_instance;

    /* instance members */
    CangjieCharPrivate *priv;
};

struct _CangjieCharClass
{
    /* Parent class structure */
    GObjectClass parent_class;

    /* class members */
};

/* used by CANGJIE_TYPE_CHAR */
GType cangjie_char_get_type (void);

/*
 * Method definitions.
 */

#endif /* __CANGJIE_CHAR_H__ */
