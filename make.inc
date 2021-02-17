# This file is part of the binary_tree module.
#
# Anyone who wants to use the binary_tree module should include this file in their
# Makefile, so that compilation is configured properly
#
 
# Set compiler flags. -I... tells the compiler to look in our directory for
# include files, so that #include "binary_tree.h" works.
#
CFLAGS += -I$(MODULES)/binary_tree

# CONDITIONAL COMPILATION
#
# Use the BT_IMPL=[pointer|array] flag to select the desired implementation.

ifeq ($(BT_IMPL),array)
	# array implementation
	CFLAGS += -DBT_IMPL_ARRAY
	OBJS += $(MODULES)/binary_tree/binary_treeArray.o
else
	# pointer implementation (default)
    CFLAGS += -DBT_IMPL_POINTER
    OBJS += $(MODULES)/binary_tree/binary_treePointer.o
endif
