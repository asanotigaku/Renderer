PROG = renderer
OBJS = main.o vector.o camera.o ray.o obj.o
DATA = 
CFLAGS = -g

all:
	make $(PROG)

run:$(RROG)
	./$(PROG) $(DATA)

$(PROG):$(OBJS)
	g++ $(CFLAGS) -o $(PROG) $(OBJS)

%.o:%.cpp
	g++ -c $<
