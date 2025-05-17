
CXX=x86_64-w64-mingw32-g++-win32

MODULE=Morelia

install: $(MODULE).usr-win64 loadlib.exe
	cp $< "/mnt/c/Users/redaf/Usine Win 6.0.250506/Resources/Modules/Audio/$(MODULE)/"$<
	cp $(MODULE).usr-win64 /mnt/c/debian
	cp loadlib.exe /mnt/c/debian

# $(MODULE).usr-win64: $(MODULE).o $(MODULE).def
$(MODULE).usr-win64: $(MODULE).o
	$(CXX) -shared -static -static-libgcc -static-libstdc++ -o $@ $^
	x86_64-w64-mingw32-objdump -p $@ | grep 'DLL Name'
	x86_64-w64-mingw32-objdump -p $@ | grep Create

$(MODULE).o: $(MODULE).cpp
	$(CXX) -c -O3 -pie -o $@ $^

loadlib.exe: loadlib.cpp
	$(CXX) $< -o $@

.PHONY:
clean:
	rm -f *.exe *.dll *.usr-win64 *.o
