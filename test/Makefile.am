noinst_PROGRAMS = conf_test \
	types_test \
	str_test
EXTRA_DIST = test.conf.xml

conf_test_SOURCES = conf_test.c
conf_test_CFLAGS = $(DEPS_CFLAGS) -I$(top_srcdir)/include
conf_test_LDADD = $(DEPS_LIBS) $(top_builddir)/src/libwutils.la

types_test_SOURCES = types_test.c
types_test_CFLAGS = $(DEPS_CFLAGS) -I$(top_srcdir)/include
types_test_LDADD = $(DEPS_LIBS) $(top_builddir)/src/libwutils.la

str_test_SOURCES = str_test.c
str_test_CFLAGS = $(DEPS_CFLAGS) -I$(top_srcdir)/include
str_test_LDADD = $(DEPS_LIBS) $(top_builddir)/src/libwutils.la

