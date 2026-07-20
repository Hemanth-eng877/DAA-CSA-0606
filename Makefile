# ============================================================================
# Makefile for CO1 Assessment Tool 1 (Multi-Source Log Processing & Warehouse)
# ============================================================================

CC = gcc
CFLAGS = -Wall -Wextra -O2

# Target executables
Q1_TARGET = Question_1/Source_Code/q1_log_processing
Q2_TARGET = Question_2/Source_Code/q2_warehouse_scheduling

# Source files (main.c inside each folder as per submission requirements)
Q1_SRC = Question_1/Source_Code/main.c
Q2_SRC = Question_2/Source_Code/main.c

.PHONY: all clean run-q1 run-q2

all: $(Q1_TARGET) $(Q2_TARGET)
	@echo "All programs compiled successfully without warnings."

$(Q1_TARGET): $(Q1_SRC)
	$(CC) $(CFLAGS) $< -o $@ -lm

$(Q2_TARGET): $(Q2_SRC)
	$(CC) $(CFLAGS) $< -o $@ -lm

run-q1: $(Q1_TARGET)
	./$(Q1_TARGET)

run-q2: $(Q2_TARGET)
	./$(Q2_TARGET)

clean:
	rm -f $(Q1_TARGET) $(Q1_TARGET).exe $(Q2_TARGET) $(Q2_TARGET).exe
	@echo "Clean completed."
