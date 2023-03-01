#
# Include generated dependency files.
#
XAR_SRCS := xar.c
XAR_SRCS := $(patsubst %, /Users/user/Downloads/xar-xar-452/xar/src/%, $(XAR_SRCS))
-include $(XAR_SRCS:/Users/user/Downloads/xar-xar-452/xar/%.c=%.d)

src_all : src/xar src/ixar

src_install : src/ixar
	/usr/bin/install -c -d $(DESTDIR)$(BINDIR)
	/usr/bin/install -c -m 0755 $< $(DESTDIR)$(BINDIR)/xar
	/usr/bin/install -c -d $(DESTDIR)$(MANDIR)/man1
	/usr/bin/install -c -m 0644 /Users/user/Downloads/xar-xar-452/xar/src/xar.1 $(DESTDIR)$(MANDIR)/man1

src_uninstall :
	rm -f $(DESTDIR)/$(BINDIR)/xar
	rm -f $(DESTDIR)/$(MANDIR)/man1/xar.1

src_clean :
	rm -f src/xar
	rm -f src/ixar
	rm -f $(XAR_SRCS:/Users/user/Downloads/xar-xar-452/xar/%.c=%.o)
	rm -f $(XAR_SRCS:/Users/user/Downloads/xar-xar-452/xar/%.c=%.d)

src_distclean :


ifeq (yes, yes)
LIBRXAR := $(LIBRXAR_S)
endif
ifeq (yes, yes)
LIBRXAR := $(LIBXAR_A)
endif

# xar links against librxar, so that it can be run without first installing
# libxar.
src/% : src/%.o $(LIBRXAR)
	@mkdir -p $(@D)
ifneq ($(words "" ), 1)
	$(CC) $(CFLAGS) -o $@ $< /Users/user/Downloads/xar-xar-452/gen/lib $(LDFLAGS) $(LIBRXAR) -lpthread -lbz2 -lz  -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib -lxml2 -lz -lpthread -licucore -lm
else
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LIBRXAR) -lpthread -lbz2 -lz  -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib -lxml2 -lz -lpthread -licucore -lm
endif

ifeq (yes, yes)
LIBXAR := $(LIBXAR_A)
endif
ifeq (yes, yes)
LIBXAR := $(LIBXAR_S)
endif

# ixar is the version of the xar binary that gets installed.
src/i% : src/%.o $(LIBXAR)
	@mkdir -p $(@D)
ifneq ($(words "" ), 1)
	$(CC) $(CFLAGS) -o $@ $< $(LIBDIR) $(LDFLAGS) $(LIBXAR) -lpthread -lbz2 -lz  -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib -lxml2 -lz -lpthread -licucore -lm
else
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LIBXAR) -lpthread -lbz2 -lz  -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib -lxml2 -lz -lpthread -licucore -lm
endif

src/%.o : /Users/user/Downloads/xar-xar-452/xar/src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(SHELL) -ec "$(CC) -MM $(CPPFLAGS) $< | sed \"s/\($(subst /,\/,$(notdir $(basename $@)))\)\.o\([ :]*\)/$(subst /,\/,$(strip $(dir $@)))\1.o \2/g\" > $(@:%.o=%.d)"
