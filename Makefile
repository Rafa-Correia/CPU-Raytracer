SRC_DIR := src
OBJ_DIR := tmp
BIN_DIR := bin

EXE := $(BIN_DIR)/main
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -O3
CFLAGS   := -Wall
#LDFLAGS  := -Llib
#LDLIBS   := -lm
CXX = g++

#$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
#$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)