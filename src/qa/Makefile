##    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
##    All rights reserved.

include ../Makefile.common

MODULE_NAME := QA

SOURCES := test-init.cpp test-leds.cpp test-tasks.cpp test-log.cpp test-mini.cpp
SOURCES_C := test-micro.c
OBJECTS := $(patsubst %$(CPP_EXT),$(BUILD_DIR)/%$(OBJ_EXT),$(SOURCES))
OBJECTS += $(patsubst %$(C_EXT),$(BUILD_DIR)/%$(OBJ_EXT),$(SOURCES_C))
EXECUTABLES := $(patsubst %$(OBJ_EXT),%$(EXEC_EXT),$(OBJECTS))
HEXECUTABLES := $(patsubst %$(EXEC_EXT),%$(HEX_EXT),$(EXECUTABLES))

targets: $(PROJECT_STATIC_LIBS) $(EXECUTABLES) $(HEXECUTABLES)

#
# Executables
#
$(BUILD_DIR)/test-init$(EXEC_EXT): $(BUILD_DIR)/test-init$(OBJ_EXT)
	$(CXX) $(CXX_CFLAGS) $< -o $@ -Wl,-Map,$@.map $(PROJECT_STATIC_LIBS) $(CXX_LDFLAGS)

$(BUILD_DIR)/test-leds$(EXEC_EXT): $(BUILD_DIR)/test-leds$(OBJ_EXT)
	$(CXX) $(CXX_CFLAGS) $< -o $@ -Wl,-Map,$@.map $(PROJECT_STATIC_LIBS) $(CXX_LDFLAGS)

$(BUILD_DIR)/test-tasks$(EXEC_EXT): $(BUILD_DIR)/test-tasks$(OBJ_EXT)
	$(CXX) $(CXX_CFLAGS) $< -o $@ -Wl,-Map,$@.map $(PROJECT_STATIC_LIBS) $(CXX_LDFLAGS)

$(BUILD_DIR)/test-log$(EXEC_EXT): $(BUILD_DIR)/test-log$(OBJ_EXT)
	$(CXX) $(CXX_CFLAGS) $< -o $@ -Wl,-Map,$@.map $(PROJECT_STATIC_LIBS) $(CXX_LDFLAGS)

$(BUILD_DIR)/test-mini$(EXEC_EXT): $(BUILD_DIR)/test-mini$(OBJ_EXT)
	$(CXX) $(CXX_CFLAGS) $< -o $@ -Wl,-Map,$@.map $(CXX_LDFLAGS)

$(BUILD_DIR)/test-micro$(EXEC_EXT): $(BUILD_DIR)/test-micro$(OBJ_EXT)
	$(CC) $(C_CFLAGS) $< -o $@ -Wl,-Map,$@.map $(C_LDFLAGS)

#
# Hex
#
$(BUILD_DIR)/test-init$(HEX_EXT): $(BUILD_DIR)/test-init$(EXEC_EXT)

$(BUILD_DIR)/test-leds$(HEX_EXT): $(BUILD_DIR)/test-leds$(EXEC_EXT)

$(BUILD_DIR)/test-tasks$(HEX_EXT): $(BUILD_DIR)/test-tasks$(EXEC_EXT)

$(BUILD_DIR)/test-log$(HEX_EXT): $(BUILD_DIR)/test-log$(EXEC_EXT)

$(BUILD_DIR)/test-mini$(HEX_EXT): $(BUILD_DIR)/test-mini$(EXEC_EXT)

$(BUILD_DIR)/test-micro$(HEX_EXT): $(BUILD_DIR)/test-micro$(EXEC_EXT)

#
# More cleanup
#
CLEAN_MORE := $(EXECUTABLES)

include ../Makefile.targets

