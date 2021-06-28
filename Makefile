fdebug:
	g++ -o a.out a.cpp -g -std=c++14 -fsanitize=address -fno-omit-frame-pointer -Wall  -DFDEBUG
debug:
	g++ -o a.out a.cpp -g -std=c++14 -fsanitize=address -fno-omit-frame-pointer -Wall  -DDEBUG 
run:
	g++ -o a.out a.cpp -g -std=c++14 -fsanitize=address -fno-omit-frame-pointer -Wall
cppcheck:
	cppcheck --enable=warning a.cpp