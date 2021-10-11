CC           = gcc
LD           = $(CC)
CFLAGS       = -O0 -g -Wall -nostdlib
SRC          = $(shell find . -name "*.c")
BIN_NAME     = main
# LIBS         = -lm
# HEADERS      = /usr/include/SDL2

.PHONY: help
help:
	@echo Supported targets:
	@cat $(MAKEFILE_LIST) | grep -e "^[\.a-zA-Z0-9_-]*: *.*## *" | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-35s\033[0m %s\n", $$1, $$2}'

.DEFAULT_GOAL := help

.PHONY: build
build: ## Build the project in the build folder. Creates ./build if it does not exist.
	mkdir -p ./build
	$(CC) $(CFLAGS) assm_bootstrap.S -o build/$(BIN_NAME) $(SRC)

.PHONY: clean
clean: ## Deletes the build folder.
	rm -rf ./build