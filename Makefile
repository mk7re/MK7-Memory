BUILD 		:= include
CMAKE_BUILD := build
SOURCES 	:= template
USE_MK7_NAMESPACE := OFF

TEMPLATEFILES 	:= $(shell find $(SOURCES) -type f -printf '%P\n')
OUTFILES 		:= $(foreach file,$(TEMPLATEFILES),$(BUILD)/$(file))

.PHONY: all clean verify

$(BUILD)/%: $(SOURCES)/%
	@mkdir -p $(@D)
	@python3 process.py $< $@

all: $(OUTFILES)

verify: all
	@rm -rf $(CMAKE_BUILD)
	@cmake -S . -B $(CMAKE_BUILD) -DUSE_MK7_NAMESPACE=$(USE_MK7_NAMESPACE)
	@cmake --build $(CMAKE_BUILD)

clean:
	@rm -rf $(BUILD)
	@rm -rf $(CMAKE_BUILD)
	@echo Cleaned.
