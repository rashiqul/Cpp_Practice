configure:
	rm -rf build
	mkdir build
	cd build && cmake ..

build: configure
	cd build && cmake --build .

clean:
	rm -rf build

run:
	./build/main/Executable