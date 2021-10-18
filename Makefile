CC            = g++
COMMON_CFLAGS = -nostdlib -fno-exceptions
CFLAGS        = $(COMMON_CFLAGS) -O0 -g -Wall -Wno-unused
PROD_CFLAGS   = $(COMMON_CFLAGS) -O3
DEBUG_DEFINES = -DDEBUG=1
PROD_DEFINES  = -DDEBUG=0
SRC           = $(shell find . -name "*.cpp")
OUT_DIR       = ./build
BIN_NAME      = main
# LIBS         = -lm
# HEADERS      = /usr/include/SDL2

.PHONY: help
help:
	@echo Supported targets:
	@cat $(MAKEFILE_LIST) | grep -e "^[\.a-zA-Z0-9_-]*: *.*## *" | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-35s\033[0m %s\n", $$1, $$2}'

.DEFAULT_GOAL := help

.PHONY: build
build: ## Build the project in the build folder. Creates ./build folder if it does not exist.
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $(DEBUG_DEFINES) assm_bootstrap.S -o $(OUT_DIR)/$(BIN_NAME) $(SRC)

.PHONY: run
run: build ## Builds and starts the binary.
	mkdir -p $(OUT_DIR)
	$(OUT_DIR)/$(BIN_NAME)

.PHONY: build_prod
build_prod: clean build ## Same as build, but optimizes aggresivly and generates no debug information.
	$(CC) $(PROD_CFLAGS) $(PROD_ENV) assm_bootstrap.S -o $(OUT_DIR)/$(BIN_NAME) $(SRC)

.PHONY: generate_asm
generate_asm: ## Uses objdump -S to generate asm from the binary. Expects the output dinaries to be generated first by other make targets.
	objdump -M intel -S $(OUT_DIR)/$(BIN_NAME) > $(OUT_DIR)/$(BIN_NAME).S

.PHONY: clean
clean: ## Deletes the build folder.
	rm -rf $(OUT_DIR)