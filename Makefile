% : src/%.cpp include/%.hpp
	g++ src/$@.cpp -Iinclude -o target/$@ -std=c++20
