OUTPUT = msix2appimage
GXX = g++
SOURCE = source/*.cpp
APPIMAGE = -appImage -b $(OUTPUT) -o $(OUTPUT)
LIBS = 

build:
	$(GXX) $(SOURCE) $(LIBS) -o $(OUTPUT)
	make buildAppImage

buildAppImage:
	RSGL-static $(APPIMAGE)

install:
	sudo cp $(OUTPUT).appImage /usr/bin