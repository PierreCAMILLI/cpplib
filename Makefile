LINK		=
ECHO 		=	echo
CAT 		=	cat
CXXFLAGS 	=  
LDFLAGS 	=
DEPTH		=	-ftemplate-depth=429496729
CC   		= 	g++ -Wall -std=c++0x $(CXXFLAGS)
LD   		= 	g++ -Wall -std=c++0x $(LDFLAGS)

SRCD 		= 	.
INCD 		= 	${SRCD}/include
OBJD 		= 	obj
BIND 		= 	bin

EXEC 		=	lib_test

OBJFILES 	=	lib_test.o perlin.o vector.o matrix.o matrix2.o curve.o mesh.o ray.o shape.o shape2d.o
OBJS 		= 	$(OBJFILES:%.o=$(OBJD)/%.o)

NO_COLOR	=	$(shell $(ECHO) "\033[0;0m")
OK_COLOR	=	$(shell $(ECHO) "\033[0;92m")
ERROR_COLOR	=	$(shell $(ECHO) "\033[0;91m")
WARN_COLOR	=	$(shell $(ECHO) "\033[0;93m")
INFO_COLOR	=	$(shell $(ECHO) "\033[0;1m")
FILE_COLOR	=	$(shell $(ECHO) "\033[0;33m")

OK_STRING	=	${OK_COLOR}[OK]$(NO_COLOR)
ERROR_STRING=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING	=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

default: $(BIND)/$(EXEC)
$(BIND)/$(EXEC): $(OBJS)
	@$(ECHO) "$(INFO_COLOR)Linking $(FILE_COLOR)$@$(INFO_COLOR) ... $(NO_COLOR)\c"
	$(LD) -o $@ $^ -L{OPENNI_LIBD} $(LINK) 2> temp.log || touch temp.errors
	@if test -e temp.errors; then $(ECHO) "$(ERROR_STRING)" && $(CAT) temp.log; elif test -s temp.log; then $(ECHO) "$(WARN_STRING)" && $(CAT) temp.log; else $(ECHO) "$(OK_STRING)"; fi;
	@$(RM) -f temp.errors temp.log

$(OBJD)/%.o: $(SRCD)/%.c
	@$(ECHO) "$(INFO_COLOR)Compiling source file $(FILE_COLOR)$@$(INFO_COLOR) ... $(NO_COLOR)\c"
	@$(CC) -o $@ -c $< -I$(INCD) -I$(OPENIN_INCD) -L$(OPENNI_LIBD) -I$(SRCD)  2> temp.log || touch temp.errors
	@if test -e temp.errors; then $(ECHO) "$(ERROR_STRING)" && $(CAT) temp.log; elif test -s temp.log; then $(ECHO) "$(WARN_STRING)" && $(CAT) temp.log; else $(ECHO) "$(OK_STRING)"; fi;
	@$(RM) -f temp.errors temp.log

$(OBJD)/%.o: $(SRCD)/%.cpp
	@$(ECHO) "$(INFO_COLOR)Compiling source file $(FILE_COLOR)$@$(INFO_COLOR) ... $(NO_COLOR)\c"
	@$(CC) -o $@ -c $< -I$(INCD) -I$(OPENIN_INCD) -L$(OPENNI_LIBD) -I$(SRCD)  2> temp.log || touch temp.errors
	@if test -e temp.errors; then $(ECHO) "$(ERROR_STRING)" && $(CAT) temp.log; elif test -s temp.log; then $(ECHO) "$(WARN_STRING)" && $(CAT) temp.log; else $(ECHO) "$(OK_STRING)"; fi;
	@$(RM) -f temp.errors temp.log

clean:
	@$(RM) -f $(OBJD)/*.o $(OBJD)/OpenGL/*.o
