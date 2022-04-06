CC = gcc

application : main.o emplog.o funcn.o setdisplay.o
	$(CC) main.o emplog.o funcn.o setdisplay.o -o application
  
main.o : main.c
  $(CC) -c main.c

emplog.o : emplog.c emplog.h
  $(CC) -c emplog.c
  
funcn.o : funcn.c funcn.h
  $(CC) -c funcn.c

setdisplay.o : setdisplay.c setdisplay.h
  $(CC) -c setdisplay.c
  
clean : 
	@echo "Cleaning..."
	rm *.o *a.out application
