noinst_PROGRAMS = conf_test
EXTRA_DIST = test.conf.xml

conf_test_SOURCES = conf_test.c
conf_test_CFLAGS = $(DEPS_CFLAGS) -I$(top_srcdir)/include
conf_test_LDADD = $(DEPS_LIBS) $(top_builddir)/src/libwutils.la
