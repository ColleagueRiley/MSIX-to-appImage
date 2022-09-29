#msix2appimage

Simple program that generates an appimage from a given msix

NOTE: this has not been tested (other than a very simple test in ./examples) and is very simplistic so it may not work in all cases

NOTE: This will only work if there is a .exe file in the .msix file that shares the same name as the ./msix file in it's root (which may or may not be the case for most msix files)

# building
to build, simply run `make`, then you can install just by moving msix2appimage (or msix2appimage.appimage) to /usr/bin

appimagetool is required for generating .appImages

wine is required for running the converted .appImages

# syntax

`msix <.msix file>`

(an example is included in ./examples if required)
