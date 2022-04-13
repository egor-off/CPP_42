########################################################################
####################### Makefile Template ##############################
########################################################################

CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
LDFLAGS =

APPNAME = PhoneBook
EXT = .cpp
SRCDIR = ./srcs
OBJDIR = ./obj

SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(OBJDIR)/%.d)
RM = rm -rf
DELOBJ = $(OBJDIR)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.d: $(SRCDIR)/%$(EXT) | $(OBJDIR)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:$(OBJDIR)/%.d=$(OBJDIR)/%.o) >$@

-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT) | $(OBJDIR)
	$(CC) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	$(RM) $(DELOBJ)

.PHONY: fclean
fclean:
	$(RM) $(DELOBJ) $(APPNAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all
