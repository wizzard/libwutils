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

int main (int argc, char *argv[])
{
    int zz = ((int) (sizeof (gint64) * (CHAR_BIT)));
    gint64 aa;
#define a gint64

    aa = ((a) (~ ((a) (((a) 1) << ((a)((int) (sizeof (a) * (CHAR_BIT))) - 1)))));

    g_printf ("zz: %d aa: %lx\n", zz, aa);

    g_printf ("gint8 max: %d\n", int_max (gint8));
    g_printf ("gint8 min: %d\n", int_min (gint8));
    g_printf ("gint16 max: %d\n", int_max (gint16));
    g_printf ("gint16 min: %d\n", int_min (gint16));
    g_printf ("gint32 max: %d\n", int_max (gint32));
    g_printf ("gint32 min: %d\n", int_min (gint32));
    g_printf ("gint64 max: %d\n", int_max (gint64));
    g_printf ("gint64 min: %d\n", int_min (gint64));

    
}
