lib_LTLIBRARIES = libwutils.la

libwutils_la_SOURCES = conf.c \
	log.c \
	libevent_utils.c \
	string_utils.c \
	file_utils.c \
	sys_utils.c \
	wrange.c
libwutils_la_LDFLAGS = $(DEPS_LIBS)
libwutils_la_CFLAGS = $(DEPS_CFLAGS) -I$(top_srcdir)/include
