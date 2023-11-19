VPATH       := sources:sources/randomSudoku:sources/selectedSudoku:sources/gameSudoku

# Temporary directory containing the object files
BUILDDIR	:= build

# Name of the executable file 
NAME        := solve

# Source files 
SRCS        := gameSudoku.cpp \
			   solveSudoku.cpp \
			   utils.cpp \
			   randomSudoku.cpp \
			   selectedSudoku.cpp \
		   	   main.cpp 

# Object files
OBJS        := $(SRCS:%.cpp=$(BUILDDIR)/%.o)

# Variables
CXX			:= g++
CXXFLAGS	:= -std=c++11 -Wall -Wextra
MAKE		:= make
RM			:= rm -f

# Colors
GREEN			= \033[92m
YELLOW			= \033[0;33m
ESCAPE			= \033[0m

# Rules
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)***** COMPILED *****$(ESCAPE)"

$(BUILDDIR)/%.o : %.cpp | $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR):
	@mkdir $(BUILDDIR)

all: $(NAME)

clean:
	@$(RM) -f $(OBJS)
	@$(RM) -df $(BUILDDIR)
	@echo "$(YELLOW)***** CLEANED  *****$(ESCAPE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)***** FCLEANED *****$(ESCAPE)"

re: fclean all

.PHONY: all clean fclean re
