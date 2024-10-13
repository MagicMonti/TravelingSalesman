g++ -Wall -g -I/usr/include/SFML -o \
traveling_salesman \
src/route.cpp \
src/point.cpp \
src/consts.cpp \
src/main.cpp \
src/algo/algo.cpp \
src/algo/donothing.cpp  \
src/algo/permutation.cpp \
src/algo/shortest.cpp \
-lsfml-graphics \
-lsfml-window \
-lsfml-system \
-lboost_random \
-lboost_system 