TESTER = test_someclass

# GoogleTest source dir on Ubuntu , change it when necessary
GTEST_DIR = /home/ycj/googletest/googletest
GTEST_HDRS = $(GTEST_DIR)/*.h $(GTEST_DIR)/internal/*.h

SRCS = $(shell ls *.cpp)
SRCS += $(shell ls ../cpp/*.cpp)
OBJS = $(SRCS:.cpp=.o)
# OBJS += $(shell ls ../cpp/*.o)

CFLAGS += -Igtest/include -I$(GTEST_DIR)/include
CXXFLAGS += $(CFLAGS)
LDFLAGS += -lpthread -lfftw3 -lsqlite3 

all: $(TESTER) gtest_main.a

$(TESTER): $(OBJS) gtest_main.a
	$(CXX) -o $(TESTER) $(OBJS) gtest_main.a $(LDFLAGS) $(CXXFLAGS)

.PHONY: clean

clean:
	rm -rf $(TESTER) $(OBJS) 
	# !(gtest_main.a|gtest_main.o|gtest-all.o)
	# rm -rf *.o !(gtest_main.a|gtest_main.o|gtest-all.o)
	rm -rf *.db

test: 
	./$(TESTER) 

# Example targets from /usr/src/googletest/googletest/make/Makefile
# for including Google Test

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^