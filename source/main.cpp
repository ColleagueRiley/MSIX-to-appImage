#include "../include/desktop.hpp"

int main(int args, char** argv){
    if (args < 2) 
        return 0;
    
    // make the appImage

    std::string name = std::string(argv[1]);

    name.replace(name.end()-5, name.end(), "");
    
    std::string file, dir = name;

    // make the usr folders
    std::string cmd = "mkdir " + dir + " "
                    + dir + "/usr "
                    + dir + "/usr/bin ";

    system(cmd.c_str());

    FILE* f;
    // make empty svg file for desktop
    file = dir+"/mt.svg"; // full file name
    
    f = fopen(file.c_str(), "w+");
    fclose(f);

    // make the desktop (or xml) file
    file = dir+"/"+name+".desktop"; // full file name

    f = fopen(file.c_str(), "w+");

    fputs(desktopFile(name + ".exe").c_str(), f); // write the desktop data into the file

    fclose(f);			

    // make the AppRun file
    file = dir+"/"+"AppRun"; // full file name
    f = fopen(file.c_str(), "w+");
    
    fputs(appRun.c_str(),f); // write the desktop data into the file
    
    fclose(f);	

    // give AppRun rw perms
    cmd = "chmod +x " + file;
    system(cmd.c_str());
    
    // copy the files into bin
    cmd = "unzip \"" + std::string(argv[1]) + "\" -d" + dir;

    system(cmd.c_str());

    // generate the appImage
    cmd = "ARCH=x86_64 appimagetool " + dir + "/ " + name + ".appImage"; 

    system(cmd.c_str());

    // clean up
    cmd = "rm -r " + dir;

    system(cmd.c_str());
}