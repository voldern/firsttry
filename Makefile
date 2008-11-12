# This file is part of FirstTry.
#
# FirstTry is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# FirstTry is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with FirstTry.  If not, see <http://www.gnu.org/licenses/>.


OBJS_FIRSTTRY=\
	main.o

#OBJS_ENGINE=\

OBJS_DEMO=\
	$(OBJS_FIRSTTRY) #\
	#$(OBJS_ENGINE)

CC=g++
CFLAGS= -Wall -m32 -g

INCLUDE_PATH=\
	-I/home/voldern/kode/c++/frontend2/frontend2/include\
	-I/home/voldern/kode/c++/frontend2/frontend2utils/include\
	-I/home/voldern/kode/c++/frontend2/openfrontend/include

LIB_PATH=\
	-L/home/voldern/kode/c++/frontend2/openfrontend/lib\
	-L/home/voldern/kode/c++/frontend2/frontend2utils/lib

LIBS= -lfrontend2utils_fwg -lopenfrontend2 -lopenfrontend2graphics_cg -lopenfrontend2input -lopenfrontend2io -lopenfrontend2math -lopenfrontend2sound_portaudio -lGL -lGLU -lXrandr -lXrender -lX11 -ljpeg -lpng -lfreetype -lCg -lCgGL -lpthread -lportaudio -logg -lvorbis -lvorbisfile

firsttry: $(OBJS_DEMO)
	$(CC) $(INCLUDE_PATH) $(LIB_PATH) $(CFLAGS) $(OBJS_DEMO) $(LIBS) -o bin/$@

%.o : %.cpp
	$(CC) $(INCLUDE_PATH) -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJS_DEMO) bin/firsttry
