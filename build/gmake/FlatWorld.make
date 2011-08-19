# GNU Make project makefile autogenerated by Premake
ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),debug)
  OBJDIR     = ../../obj/Debug/FlatWorld
  TARGETDIR  = ../../debug
  TARGET     = $(TARGETDIR)/libFlatWorld.a
  DEFINES   += -D_DEBUG
  INCLUDES  += -I../../include -I../../src/FlatWorld
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L../../lib
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release)
  OBJDIR     = ../../obj/Release/FlatWorld
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libFlatWorld.a
  DEFINES   += -DNDEBUG
  INCLUDES  += -I../../include -I../../src/FlatWorld
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall -O2
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L../../lib
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/Engine.o \
	$(OBJDIR)/SFMLSound.o \
	$(OBJDIR)/GameObject.o \
	$(OBJDIR)/GOTemplate.o \
	$(OBJDIR)/GOTManager.o \
	$(OBJDIR)/SFMLKeyboardHandler.o \
	$(OBJDIR)/SFMLMouseHandler.o \
	$(OBJDIR)/Colour.o \
	$(OBJDIR)/Particle.o \
	$(OBJDIR)/ParticleEmitter.o \
	$(OBJDIR)/SFMLGameWindow.o \
	$(OBJDIR)/Shader.o \
	$(OBJDIR)/Vector2f.o \
	$(OBJDIR)/ScreenManager.o \
	$(OBJDIR)/ColourUtilities.o \
	$(OBJDIR)/Timer.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking FlatWorld
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning FlatWorld
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/Engine.o: ../../src/FlatWorld/Engine.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SFMLSound.o: ../../src/FlatWorld/Audio/SFMLSound.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/GameObject.o: ../../src/FlatWorld/ComponentSystem/GameObject.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/GOTemplate.o: ../../src/FlatWorld/ComponentSystem/GOTemplate.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/GOTManager.o: ../../src/FlatWorld/ComponentSystem/GOTManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SFMLKeyboardHandler.o: ../../src/FlatWorld/Controls/SFMLKeyboardHandler.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SFMLMouseHandler.o: ../../src/FlatWorld/Controls/SFMLMouseHandler.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Colour.o: ../../src/FlatWorld/Graphics/Colour.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Particle.o: ../../src/FlatWorld/Graphics/Particle.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ParticleEmitter.o: ../../src/FlatWorld/Graphics/ParticleEmitter.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SFMLGameWindow.o: ../../src/FlatWorld/Graphics/SFMLGameWindow.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Shader.o: ../../src/FlatWorld/Graphics/Shader.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Vector2f.o: ../../src/FlatWorld/Maths/Vector2f.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ScreenManager.o: ../../src/FlatWorld/ScreenSystem/ScreenManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ColourUtilities.o: ../../src/FlatWorld/Utilities/ColourUtilities.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Timer.o: ../../src/FlatWorld/Utilities/Timer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)