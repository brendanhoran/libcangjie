#include <cangjie.h>


void
test_new_cangjie_context (void)
{
    guint32 filter_flags = CANGJIE_FILTER_BIG5 | CANGJIE_FILTER_HKSCS;
    CangjieVersion version = CANGJIE_VERSION_CJ5;

    CangjieContext *cj = g_object_new (CANGJIE_TYPE_CONTEXT,
                                       "filter_flags", filter_flags,
                                       "version", version,
                                       NULL);

    guint32 check_filter_flags;
    g_object_get (G_OBJECT (cj), "filter_flags", &check_filter_flags, NULL);
    g_assert_cmpuint (check_filter_flags, ==, filter_flags);

    CangjieVersion check_version;
    g_object_get (G_OBJECT (cj), "version", &check_version, NULL);
    g_assert_cmpuint (check_version, ==, version);

    g_object_unref (cj);
}

void
test_cangjie_get_characters_single_result (void)
{
    /* TODO: Implement this */
    g_assert_cmpuint(1, ==, 1);
}

void
test_cangjie_get_characters_results_order (void)
{
    /* TODO: Implement this */
    g_assert_cmpuint(1, ==, 1);
}

void
test_cangjie_get_characters_by_shortcode (void)
{
    /* TODO: Implement this */
    g_assert_cmpuint(1, ==, 1);
}

void
test_cangjie_get_characters_multiple_queries (void)
{
    /* TODO: Implement this */
    g_assert_cmpuint(1, ==, 1);
}


int
main (int argc, char** argv)
{
#if !GLIB_CHECK_VERSION(2,36,0)
    g_type_init();
#endif

    g_test_init (&argc, &argv, NULL);

    g_test_add_func ("/cangjie/new", test_new_cangjie_context);
    g_test_add_func ("/cangjie/get-single-character", test_cangjie_get_characters_single_result);
    g_test_add_func ("/cangjie/get-ordered-characters", test_cangjie_get_characters_results_order);
    g_test_add_func ("/cangjie/get-characters-by-shortcode", test_cangjie_get_characters_by_shortcode);
    g_test_add_func ("/cangjie/multiple-get-characters", test_cangjie_get_characters_multiple_queries);

    return g_test_run();
}
