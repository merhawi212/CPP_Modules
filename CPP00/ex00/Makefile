NAME = megaphone
SRC = megaphone.cpp
BUILD_DIR = ./build
OBJ = $(BUILD_DIR)/$(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 
	
$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
