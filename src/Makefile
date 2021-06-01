cc = g++
prom = test
deps = Role.h Room.h Castle.h
src = Room.cpp Castle.cpp main.cpp
obj = Room.o Castle.o main.o

$(prom): $(obj)
	$(cc) $(obj) -o $(prom)

%.o: %.cpp $(deps)
	$(cc) -c $< -o $@

