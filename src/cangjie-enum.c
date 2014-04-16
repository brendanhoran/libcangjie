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


#include "cangjie-enum.h"


static const GFlagsValue _cangjie_filter_flags_values[] = {
    { CANGJIE_FILTER_BIG5, "CANGJIE_FILTER_BIG5", "big5" },
    { CANGJIE_FILTER_HKSCS, "CANGJIE_FILTER_HKSCS", "hkscs" },
    { CANGJIE_FILTER_PUNCTUATION, "CANGJIE_FILTER_PUNCTUATION", "punctuation" },
    { CANGJIE_FILTER_CHINESE, "CANGJIE_FILTER_CHINESE", "chinese" },
    { CANGJIE_FILTER_ZHUYIN, "CANGJIE_FILTER_ZHUYIN", "zhuyin" },
    { CANGJIE_FILTER_KANJI, "CANGJIE_FILTER_KANJI", "kanji" },
    { CANGJIE_FILTER_KATAKANA, "CANGJIE_FILTER_KATAKANA", "katakana" },
    { CANGJIE_FILTER_HIRAGANA, "CANGJIE_FILTER_HIRAGANA", "hiragana" },
    { CANGJIE_FILTER_SYMBOLS, "CANGJIE_FILTER_SYMBOLS", "symbols" },
    { 0, NULL, NULL }
};

GType
cangjie_filter_flags_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_flags_register_static ("CangjieFilterFlags", _cangjie_filter_flags_values);

  return type;
}


static const GEnumValue _cangjie_version_values[] = {
  { CANGJIE_VERSION_CJ3, "CANGJIE_VERSION_CJ3", "CJ3" },
  { CANGJIE_VERSION_CJ5, "CANGJIE_VERSION_CJ5", "CJ5" },
  { 0, NULL, NULL }
};

GType
cangjie_version_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("CangjieVersion", _cangjie_version_values);

  return type;
}
