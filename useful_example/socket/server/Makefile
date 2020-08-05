all: build 

build:
	cmake -Bbuild -H. -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1
	cmake --build build/ -j

.PHONY: distclean

run:
	./build/main

distclean:
	rm -rf build