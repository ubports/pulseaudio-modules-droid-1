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
	libdroid-sink$(DROID_MODULE_SUFFIX).la \
	libdroid-source$(DROID_MODULE_SUFFIX).la \
	module-droid-sink$(DROID_MODULE_SUFFIX).la \
	module-droid-source$(DROID_MODULE_SUFFIX).la \
	module-droid-card$(DROID_MODULE_SUFFIX).la

noinst_HEADERS = module-symdef-compat.h

libdroid_sink__DROID_MODULE_SUFFIX__la_SOURCES = droid-sink.c droid-sink.h
libdroid_sink__DROID_MODULE_SUFFIX__la_LDFLAGS = -avoid-version -Wl,-z,noexecstack -lhybris-common
libdroid_sink__DROID_MODULE_SUFFIX__la_LIBADD = $(top_builddir)/src/common/libdroid-util$(DROID_MODULE_SUFFIX).la $(AM_LIBADD)
libdroid_sink__DROID_MODULE_SUFFIX__la_CFLAGS = $(AM_CFLAGS)

libdroid_source__DROID_MODULE_SUFFIX__la_SOURCES = droid-source.c droid-source.h
libdroid_source__DROID_MODULE_SUFFIX__la_LDFLAGS = -avoid-version -Wl,-z,noexecstack -lhybris-common
libdroid_source__DROID_MODULE_SUFFIX__la_LIBADD = $(top_builddir)/src/common/libdroid-util$(DROID_MODULE_SUFFIX).la $(AM_LIBADD)
libdroid_source__DROID_MODULE_SUFFIX__la_CFLAGS = $(AM_CFLAGS)

module_droid_sink__DROID_MODULE_SUFFIX__la_SOURCES = module-droid-sink.c
module_droid_sink__DROID_MODULE_SUFFIX__la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common
module_droid_sink__DROID_MODULE_SUFFIX__la_LIBADD = -lm libdroid-sink$(DROID_MODULE_SUFFIX).la $(AM_LIBADD)
module_droid_sink__DROID_MODULE_SUFFIX__la_CFLAGS = $(AM_CFLAGS) -DPA_MODULE_NAME=module_droid_sink$(subst -,_,$(DROID_MODULE_SUFFIX))

module_droid_source__DROID_MODULE_SUFFIX__la_SOURCES = module-droid-source.c
module_droid_source__DROID_MODULE_SUFFIX__la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common
module_droid_source__DROID_MODULE_SUFFIX__la_LIBADD = -lm libdroid-source$(DROID_MODULE_SUFFIX).la $(AM_LIBADD)
module_droid_source__DROID_MODULE_SUFFIX__la_CFLAGS = $(AM_CFLAGS) -DPA_MODULE_NAME=module_droid_source$(subst -,_,$(DROID_MODULE_SUFFIX))

module_droid_card__DROID_MODULE_SUFFIX__la_SOURCES = module-droid-card.c droid-extcon.c droid-extevdev.c
module_droid_card__DROID_MODULE_SUFFIX__la_LDFLAGS = -module -avoid-version -Wl,-z,noexecstack -lhybris-common -ludev
module_droid_card__DROID_MODULE_SUFFIX__la_LIBADD = -lm libdroid-sink$(DROID_MODULE_SUFFIX).la libdroid-source$(DROID_MODULE_SUFFIX).la $(top_builddir)/src/common/libdroid-util$(DROID_MODULE_SUFFIX).la $(AM_LIBADD) $(EVDEV_LIBS)
module_droid_card__DROID_MODULE_SUFFIX__la_CFLAGS = $(AM_CFLAGS) $(EVDEV_CFLAGS) -DPA_MODULE_NAME=module_droid_card$(subst -,_,$(DROID_MODULE_SUFFIX))
