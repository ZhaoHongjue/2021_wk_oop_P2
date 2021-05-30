cc = g++
prom = test
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o)

$(prom): $(obj)
	$(cc) $(obj) -o $(prom)

%.o: %.cpp $(deps)
	$(cc) -c $< -o $@

clean:
	rm -rf $(obj) $(prom)
