CC=g++
FILE?=default 
OFILE:=$(addsuffix .o,$(FILE))
CPPFILE=$(addsuffix .cpp,$(FILE))
EXEFILE=$(addsuffix .exe,$(FILE))
ALL:compile link exe clean

link: $(OFILE)
	@$(CC) -o $(EXEFILE) $(OFILE)

compile:
	@$(CC) $(CPPFILE)

exe:
	@$(EXEFILE)

clean:
	@del *.o 
	@del $(EXEFILE)


