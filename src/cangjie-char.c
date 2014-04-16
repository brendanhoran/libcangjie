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


#include <cangjie-char.h>


struct _CangjieCharPrivate
{
    gchar *chchar;
    gchar *simpchar;
    gchar *code;
    guint  frequency;
};

#if GLIB_CHECK_VERSION(2,38,0)
G_DEFINE_TYPE_WITH_PRIVATE (CangjieChar, cangjie_char, G_TYPE_OBJECT)
#else
G_DEFINE_TYPE (CangjieChar, cangjie_char, G_TYPE_OBJECT)

#define cangjie_char_get_instance_private(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), CANGJIE_TYPE_CHAR, CangjieCharPrivate))
#endif


enum
{
    PROP_0,

    PROP_CANGJIE_CHAR_CHCHAR,
    PROP_CANGJIE_CHAR_SIMPCHAR,
    PROP_CANGJIE_CHAR_CODE,
    PROP_CANGJIE_CHAR_FREQUENCY,

    N_PROPERTIES
};

/* Keep a pointer to the properties definition */
static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

static void
cangjie_char_set_property (GObject      *object,
                           guint         property_id,
                           const GValue *value,
                           GParamSpec   *pspec)
{
    CangjieChar *self = CANGJIE_CHAR (object);

    switch (property_id)
    {
        case PROP_CANGJIE_CHAR_CHCHAR:
            g_free (self->priv->chchar);
            // TODO: Ensure only 4 bytes
            self->priv->chchar = g_value_dup_string (value);
            break;

        case PROP_CANGJIE_CHAR_SIMPCHAR:
            g_free (self->priv->simpchar);
            // TODO: Ensure only 4 bytes
            self->priv->simpchar = g_value_dup_string (value);
            break;

        case PROP_CANGJIE_CHAR_CODE:
            g_free (self->priv->code);
            // TODO: Ensure only 6 bytes
            self->priv->code = g_value_dup_string (value);
            break;

        case PROP_CANGJIE_CHAR_FREQUENCY:
            self->priv->frequency = g_value_get_uint (value);
            break;

        default:
            /* We don't have any other property... */
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}

static void
cangjie_char_get_property (GObject    *object,
                           guint       property_id,
                           GValue     *value,
                           GParamSpec *pspec)
{
    CangjieChar *self = CANGJIE_CHAR (object);

    switch (property_id)
    {
        case PROP_CANGJIE_CHAR_CHCHAR:
            g_value_set_string (value, self->priv->chchar);
            break;

        case PROP_CANGJIE_CHAR_SIMPCHAR:
            g_value_set_string (value, self->priv->simpchar);
            break;

        case PROP_CANGJIE_CHAR_CODE:
            g_value_set_string (value, self->priv->code);
            break;

        case PROP_CANGJIE_CHAR_FREQUENCY:
            g_value_set_uint (value, self->priv->frequency);
            break;

        default:
            /* We don't have any other property... */
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}

static void
cangjie_char_finalize (GObject *object)
{
    CangjieChar *self = CANGJIE_CHAR (object);

    g_free (self->priv->chchar);
    g_free (self->priv->simpchar);
    g_free (self->priv->code);

    /* Always chain up to the parent class; as with dispose(), finalize()
     * is guaranteed to exist on the parent's class virtual function table
     */
    G_OBJECT_CLASS (cangjie_char_parent_class)->finalize (object);
}

static void
cangjie_char_class_init (CangjieCharClass *klass)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

    gobject_class->set_property = cangjie_char_set_property;
    gobject_class->get_property = cangjie_char_get_property;

    gobject_class->finalize = cangjie_char_finalize;

#if !GLIB_CHECK_VERSION(2,38,0)
    g_type_class_add_private (klass, sizeof (CangjieCharPrivate));
#endif

    obj_properties[PROP_CANGJIE_CHAR_CHCHAR] =
        g_param_spec_string ("chchar",
                             "Character",
                             "The character to input",
                             "",
                             G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    obj_properties[PROP_CANGJIE_CHAR_SIMPCHAR] =
        g_param_spec_string ("simpchar",
                             "Simplified Character",
                             "The Simplified Chinese equivalent of the character to input",
                             "",
                             G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    obj_properties[PROP_CANGJIE_CHAR_CODE] =
        g_param_spec_string ("code",
                             "Code",
                             "The Cangjie code of the character to input",
                             "",
                             G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    obj_properties[PROP_CANGJIE_CHAR_FREQUENCY] =
        g_param_spec_uint ("frequency",
                           "Frequency",
                           "The character frequency",
                           0, 65535, 0,
                           G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    g_object_class_install_properties (gobject_class,
                                       N_PROPERTIES,
                                       obj_properties);
}

static void
cangjie_char_init (CangjieChar *self)
{
    self->priv = cangjie_char_get_instance_private (self);
}
