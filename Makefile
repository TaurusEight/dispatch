# Time-stamp: <2016-02-19 13:22:16 dmendyke>


#
# Makefile:  Builds the classic project
#


##
# Macros
cc := /usr/bin/g++
ccflags := -std=c++14  -I/home/dmendyke/dev/cc/ct
sh := /bin/bash
RM := /bin/rm
AR := /usr/bin/ar


##
# Rules
%.d : %.cc ; $(sh) ./dep.sh $<
%.o : %.cc ; $(cc) $(ccflags) -c -o $@ $<


##
files = dispatch node application main


##
objects =
dependents =
targets =
libraries =


##
target := dispatch
source = $(addsuffix .cc,$(files))
objects += $(source:.cc=.o)
dependents += $(source:.cc=.d)


##
# Main target
all : $(target) $(dependents) ; @echo Build Completed

##
# all '*.d' files
include $(dependents)

##
# Main target
$(target) : $(objects) ; $(cc) $(ccflags) -o $@ $^ -lcppformat


##
# Debugging rule
.PHONEY: dump
dump:
	@echo TARGETS: $(target)
	@echo OBJECTS: $(objects)
	@echo DEPENDENTS: $(dependents)
	@echo LIBRARIES: $(libraries)


##
# Run the application and dump the log file
.PHONEY: run
run : ; @./generate && cat log.out


##
# Remove build files
.PHONEY:	clean
clean : ; $(RM) --force $(target) $(objects)
nuke : clean ; $(RM) --force $(dependents)

.PHONEY: wipe
wipe:
	$(RM) --force *.d
