AM_LIBADD = \
	$(PULSEAUDIO_LIBS) \
	$(HYBRIS_LIBS)

AM_CFLAGS = \
	$(DROID_DEVICE_CFLAGS) \
	$(PULSEAUDIO_CFLAGS) \
	$(DROIDHEADERS_CFLAGS) \
	$(HYBRIS_CFLAGS) \
	-DPULSEAUDIO_VERSION=@PA_MAJOR@ \
	-I$(top_srcdir)/src/droid \
	-I$(top_srcdir)/src/common/include


modlibexec_LTLIBRARIES = \
	libdroid-sink-24.la \
	libdroid-source-24.la \
	module-droid-sink-24.la \
	module-droid-source-24.la \
	module-droid-card-24.la

noinst_HEADERS = module-droid-sink-symdef.h module-droid-source-symdef.h module-droid-card-symdef.h

libdroid_sink_24_la_SOURCES = droid-sink.c droid-sink.h
libdroid_sink_24_la_LDFLAGS = -avoid-version -Wl,-z,noexecstack -lhybris-common
libdroid_sink_24_la_LIBADD = $(top_builddir)/src/common/libdroid-util-24.la $(AM_LIBADD)
libdroid_sink_24_la_CFLAGS = $(AM_CFLAGS)

libdroid_source_24_la_SOURCES = droid-source.c droid-source.h
libdroid_source_24_la_LDFLAGS = -avoid-version -Wl,-z,noexecstack -lhybris-common
libdroid_source_24_la_LIBADD = $(top_builddir)/src/common/libdroid-util-24.la $(AM_LIBADD)
libdroid_source_24_la_CFLAGS = $(AM_CFLAGS)

module_droid_sink_24_la_SOURCES = module-droid-sink.c
module_droid_sink_24_la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common
module_droid_sink_24_la_LIBADD = -lm libdroid-sink-24.la $(AM_LIBADD)
module_droid_sink_24_la_CFLAGS = $(AM_CFLAGS)

module_droid_source_24_la_SOURCES = module-droid-source.c
module_droid_source_24_la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common
module_droid_source_24_la_LIBADD = -lm libdroid-source-24.la $(AM_LIBADD)
module_droid_source_24_la_CFLAGS = $(AM_CFLAGS)

module_droid_card_24_la_SOURCES = module-droid-card.c droid-extcon.c
module_droid_card_24_la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common -ludev
module_droid_card_24_la_LIBADD = -lm libdroid-sink-24.la libdroid-source-24.la $(top_builddir)/src/common/libdroid-util-24.la $(AM_LIBADD)
module_droid_card_24_la_CFLAGS = $(AM_CFLAGS)
