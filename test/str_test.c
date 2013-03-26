/*
 * Copyright (C) 2012-2013 Paul Ionkin <paul.ionkin@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */
#include "wutils.h"

void str_remove_quotes_1 (void)
{
    gchar *str = g_strdup ("\"aa\"");
    str = str_remove_quotes (str);

    g_assert_cmpstr (str, ==, "aa");
    g_free (str);
}

void str_remove_quotes_2 (void)
{
    gchar *str = g_strdup ("\"\"");
    str = str_remove_quotes (str);

    g_assert_cmpstr (str, ==, "");
    g_free (str);
}

void str_remove_quotes_3 (void)
{
    gchar *str = g_strdup ("\"test\"test\"");
    str = str_remove_quotes (str);

    g_assert_cmpstr (str, ==, "test\"test");
    g_free (str);
}

void str_remove_quotes_4 (void)
{
    gchar *str = g_strdup ("\"\"\"\"\"");
    str = str_remove_quotes (str);

    g_assert_cmpstr (str, ==, "");
    g_free (str);
}

int main (int argc, char *argv[])
{
    g_test_init (&argc, &argv, NULL);

	g_test_add_func ("/utils/str_remove_quotes_1", str_remove_quotes_1);
	g_test_add_func ("/utils/str_remove_quotes_2", str_remove_quotes_2);
	g_test_add_func ("/utils/str_remove_quotes_3", str_remove_quotes_3);
	g_test_add_func ("/utils/str_remove_quotes_4", str_remove_quotes_4);

    return g_test_run ();
}
