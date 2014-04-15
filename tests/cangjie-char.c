#include <cangjie-char.h>


void
test_new_cangjie_char_a (void)
{
    CangjieChar *c = g_object_new (CANGJIE_TYPE_CHAR,
                                   "chchar", "a",
                                   "simpchar", "b",
                                   "code", "abc",
                                   "frequency", 123,
                                   NULL);

    gchar *chchar;
    gchar *simpchar;
    gchar *code;
    guint frequency;

    g_object_get (G_OBJECT (c), "chchar", &chchar, NULL);
    g_assert_cmpstr (chchar, ==, "a");

    g_object_get (G_OBJECT (c), "simpchar", &simpchar, NULL);
    g_assert_cmpstr (simpchar, ==, "b");

    g_object_get (G_OBJECT (c), "code", &code, NULL);
    g_assert_cmpstr (code, ==, "abc");

    g_object_get (G_OBJECT (c), "frequency", &frequency, NULL);
    g_assert_cmpuint (frequency, ==, 123);

    g_free (chchar);
    g_free (simpchar);
    g_free (code);
    g_object_unref (c);
}

void
test_new_cangjie_char_zh (void)
{
    CangjieChar *c = g_object_new (CANGJIE_TYPE_CHAR,
                                   "chchar", "\xE5\xBE\x8C",   // 後
                                   "simpchar", "\xE5\x90\x8E", // 后
                                   "code", "abc",
                                   "frequency", 123,
                                   NULL);


    gchar *chchar;
    gchar *simpchar;
    gchar *code;
    guint frequency;

    g_object_get (G_OBJECT (c), "chchar", &chchar, NULL);
    g_assert_cmpstr (chchar, ==, "\xE5\xBE\x8C");

    g_object_get (G_OBJECT (c), "simpchar", &simpchar, NULL);
    g_assert_cmpstr (simpchar, ==, "\xE5\x90\x8E");

    g_object_get (G_OBJECT (c), "code", &code, NULL);
    g_assert_cmpstr (code, ==, "abc");

    g_object_get (G_OBJECT (c), "frequency", &frequency, NULL);
    g_assert_cmpuint (frequency, ==, 123);

    g_free (chchar);
    g_free (simpchar);
    g_free (code);
    g_object_unref (c);
}

void
test_new_cangjie_char_empty (void)
{
    CangjieChar *c = g_object_new (CANGJIE_TYPE_CHAR, NULL);

    gchar *chchar;
    gchar *simpchar;
    gchar *code;
    guint frequency;

    g_object_get (G_OBJECT (c), "chchar", &chchar, NULL);
    g_assert_cmpstr (chchar, ==, "");

    g_object_get (G_OBJECT (c), "simpchar", &simpchar, NULL);
    g_assert_cmpstr (simpchar, ==, "");

    g_object_get (G_OBJECT (c), "code", &code, NULL);
    g_assert_cmpstr (code, ==, "");

    g_object_get (G_OBJECT (c), "frequency", &frequency, NULL);
    g_assert_cmpuint (frequency, ==, 0);

    g_free (chchar);
    g_free (simpchar);
    g_free (code);
    g_object_unref (c);
}


int
main (int argc, char** argv)
{
#if !GLIB_CHECK_VERSION(2,36,0)
    g_type_init();
#endif

    g_test_init (&argc, &argv, NULL);

    g_test_add_func ("/cangjie-char/new-a", test_new_cangjie_char_a);
    g_test_add_func ("/cangjie-char/new-zh", test_new_cangjie_char_zh);
    g_test_add_func ("/cangjie-char/new-empty", test_new_cangjie_char_empty);

    return g_test_run();
}
