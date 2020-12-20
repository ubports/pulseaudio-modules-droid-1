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
	libdroid-sink-29.la \
	libdroid-source-29.la \
	module-droid-sink-29.la \
	module-droid-source-29.la \
	module-droid-card-29.la

noinst_HEADERS = module-droid-sink-symdef.h module-droid-source-symdef.h module-droid-card-symdef.h

libdroid_sink_29_la_SOURCES = droid-sink.c droid-sink.h
libdroid_sink_29_la_LDFLAGS = -avoid-version -Wl,-z,noexecstack -lhybris-common
libdroid_sink_29_la_LIBADD = $(top_builddir)/src/common/libdroid-util-29.la $(AM_LIBADD)
libdroid_sink_29_la_CFLAGS = $(AM_CFLAGS)

libdroid_source_29_la_SOURCES = droid-source.c droid-source.h
libdroid_source_29_la_LDFLAGS = -avoid-version -Wl,-z,noexecstack -lhybris-common
libdroid_source_29_la_LIBADD = $(top_builddir)/src/common/libdroid-util-29.la $(AM_LIBADD)
libdroid_source_29_la_CFLAGS = $(AM_CFLAGS)

module_droid_sink_29_la_SOURCES = module-droid-sink.c
module_droid_sink_29_la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common
module_droid_sink_29_la_LIBADD = -lm libdroid-sink-29.la $(AM_LIBADD)
module_droid_sink_29_la_CFLAGS = $(AM_CFLAGS)

module_droid_source_29_la_SOURCES = module-droid-source.c
module_droid_source_29_la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common
module_droid_source_29_la_LIBADD = -lm libdroid-source-29.la $(AM_LIBADD)
module_droid_source_29_la_CFLAGS = $(AM_CFLAGS)

module_droid_card_29_la_SOURCES = module-droid-card.c droid-extcon.c droid-extevdev.c
module_droid_card_29_la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common -ludev
module_droid_card_29_la_LIBADD = -lm libdroid-sink-29.la libdroid-source-29.la $(top_builddir)/src/common/libdroid-util-29.la $(AM_LIBADD) $(EVDEV_LIBS)
module_droid_card_29_la_CFLAGS = $(AM_CFLAGS) $(EVDEV_CFLAGS)
