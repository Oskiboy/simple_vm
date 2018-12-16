#################################
# Defines			#
#################################

FLAGS	:= -Wall
INCLUDE := -I include
OBJDIR	:= bin
OBJS	:= $(addprefix $(OBJDIR)/, parser.o arg_parser.o)

#################################
# Rules				#
#################################

all: $(OBJDIR)/main.exe
$(OBJDIR)/main.exe: main.c $(OBJS)
	gcc -o $@ $^ $(FLAGS) $(INCLUDE) 

objs: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/%.o: src/%.c
	gcc -o $@ -c $^ $(FLAGS) $(INCLUDE)

$(OBJDIR): 
	mkdir $(OBJDIR)

clean:
	rm $(OBJS)
