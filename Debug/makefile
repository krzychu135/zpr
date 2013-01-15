

RM := rm -rf

# All of the sources participating in the build are defined here
-include inpath.mk
-include sources.mk
-include subdir.mk
-include objects.mk


# All Target
all: zpr

# Tool invocations
zpr: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ $(LIB_DIR) -o "zpr" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) zpr
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

