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
#include <string.h>

gchar *get_random_string (size_t len, gboolean readable)
{
    gchar *out;

    out = g_malloc (len + 1);

    if (readable) {
        gchar readable_chars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        size_t i;

        for (i = 0; i < len; i++)
            out[i] = readable_chars[rand() % strlen (readable_chars)];
    } else {
        if (!RAND_pseudo_bytes ((unsigned char *)out, len))
            return out;
    }

    *(out + len) = '\0';

    return out;
}

gboolean get_md5_sum (const gchar *buf, size_t len, gchar **md5str, gchar **md5b)
{
    unsigned char digest[16];
    size_t i;
    gchar *out;

    if (!md5b && !md5str)
        return TRUE;

    MD5 ((const unsigned char *)buf, len, digest);

  
    if (md5b)
        *md5b = get_base64 ((const gchar *)digest, 16);
    if (md5str) {
        out = g_malloc (33);
        for (i = 0; i < 16; ++i)
            sprintf(&out[i*2], "%02x", (unsigned int)digest[i]);
        *md5str = out;
    }
    return TRUE;
}

gchar *get_base64 (const gchar *buf, size_t len)
{
    int ret;
    gchar *res;
    BIO *bmem, *b64;
    BUF_MEM *bptr;
    
    b64 = BIO_new (BIO_f_base64 ());
    bmem = BIO_new (BIO_s_mem ());
    b64 = BIO_push (b64, bmem);
    BIO_write (b64, buf, len);
    ret = BIO_flush (b64);
    if (ret != 1) {
        BIO_free_all (b64);
        return NULL;
    }
    BIO_get_mem_ptr (b64, &bptr);
    res = g_malloc (bptr->length);
    memcpy (res, bptr->data, bptr->length);
    res[bptr->length - 1] = '\0';
    BIO_free_all (b64);

    return res;
}
