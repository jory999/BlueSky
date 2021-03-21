OBJ := system.o loader.o
TOP_DIR := $(PWD)
OBJ_DIR := $(TOP_DIR)/obj
BIN_DIR := $(TOP_DIR)/bin
FONT_DIR := $(TOP_DIR)/font
BIN := system.img
SUB_DIR := system loader
export OBJ_DIR BIN_DIR FONT_DIR 

all:CHECKDIR $(SUB_DIR)

CHECKDIR:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(SUB_DIR) : ECHO
	make -C $@

ECHO:
	@echo $(SUB_DIR)
	@echo begin compile

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR) $(FONT_DIR)/*.o