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

#include "cangjie.h"

struct _CangjieContextPrivate
{
    guint32 filter_flags;
    guint8  version;
};

#if GLIB_CHECK_VERSION(2,38,0)
G_DEFINE_TYPE_WITH_PRIVATE (CangjieContext, cangjie_context, G_TYPE_OBJECT)
#else
G_DEFINE_TYPE (CangjieContext, cangjie_context, G_TYPE_OBJECT)

#define cangjie_context_get_instance_private(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), CANGJIE_TYPE_CONTEXT, CangjieContextPrivate))
#endif

enum
{
    PROP_0,

    PROP_CANGJIE_CONTEXT_FILTERFLAGS,
    PROP_CANGJIE_CONTEXT_VERSION,

    N_PROPERTIES
};

/* Keep a pointer to the properties definition */
static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

static void
cangjie_context_set_property (GObject      *object,
                              guint         property_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
    CangjieContext *self = CANGJIE_CONTEXT (object);

    switch (property_id)
    {
        case PROP_CANGJIE_CONTEXT_FILTERFLAGS:
            self->priv->filter_flags = g_value_get_flags (value);
            break;

        case PROP_CANGJIE_CONTEXT_VERSION:
            self->priv->version = g_value_get_enum (value);
            break;

        default:
            /* We don't have any other property... */
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}

static void
cangjie_context_get_property (GObject    *object,
                              guint       property_id,
                              GValue     *value,
                              GParamSpec *pspec)
{
    CangjieContext *self = CANGJIE_CONTEXT (object);

    switch (property_id)
    {
        case PROP_CANGJIE_CONTEXT_FILTERFLAGS:
            g_value_set_flags (value, self->priv->filter_flags);
            break;

        case PROP_CANGJIE_CONTEXT_VERSION:
            g_value_set_enum (value, self->priv->version);
            break;

        default:
            /* We don't have any other property... */
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}

static void
cangjie_context_finalize (GObject *object)
{
    CangjieContext *self = CANGJIE_CONTEXT (object);

    /* Always chain up to the parent class; as with dispose(), finalize()
     * is guaranteed to exist on the parent's class virtual function table
     */
    G_OBJECT_CLASS (cangjie_context_parent_class)->finalize (object);
}

static void
cangjie_context_class_init (CangjieContextClass *klass)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

    gobject_class->set_property = cangjie_context_set_property;
    gobject_class->get_property = cangjie_context_get_property;

    gobject_class->finalize = cangjie_context_finalize;

#if !GLIB_CHECK_VERSION(2,38,0)
    g_type_class_add_private (klass, sizeof (CangjieContextPrivate));
#endif

    obj_properties[PROP_CANGJIE_CONTEXT_FILTERFLAGS] =
        g_param_spec_flags ("filter_flags",
                            "Filter Flags",
                            "Bitwise OR-ed query filter flags",
                            CANGJIE_TYPE_FILTER_FLAGS,
                            CANGJIE_FILTER_ALL,
                            G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    obj_properties[PROP_CANGJIE_CONTEXT_VERSION] =
        g_param_spec_enum ("version",
                           "Version",
                           "The version of the Cangjie input method",
                           CANGJIE_TYPE_VERSION,
                           CANGJIE_VERSION_CJ3,
                           G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    g_object_class_install_properties (gobject_class,
                                       N_PROPERTIES,
                                       obj_properties);
}

static void
cangjie_context_init (CangjieContext *self)
{
    self->priv = cangjie_context_get_instance_private (self);
}
