#https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents

SRCS = $(shell ls cpp/*.cpp)
SRCS += main.cpp
SRCS_H = $(shell ls hpp/*.hpp)
OBJS = $(SRCS:.cpp=.o)
#APP : main() here
APP = ./main.exe	
LDFLAGS += -lpthread

# LDFLAGS += -lfftw3 -lsqlite3 -lpthread

all: $(APP) 

$(APP): $(OBJS)
	$(CXX)  -o $(APP) $(OBJS) $(LDFLAGS)

# $(OBJS):
# 	$(CXX) -c  $(SRCS) $(LDFLAGS)

.PHONY: clean format run

clean:
	# $(MAKE) -C test clean
	rm -rf $(OBJS) $(APP)  *.o

format:
	clang-format -assume-filename=.clang-format -i $(SRCS)
	clang-format -assume-filename=.clang-format -i hpp/*.hpp

run:
	$(APP) 