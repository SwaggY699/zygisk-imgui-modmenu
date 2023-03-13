#include <pthread.h>
#include <jni.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include<list>
#include<vector>
#include<string.h>
#include<pthread.h>
#include<thread>
#include<cstring>
#include<jni.h>
#include<unistd.h>
#include<fstream>
#include<iostream>
#include<dlfcn.h>
#include <algorithm>
#include <string>
#include <map>

#include "Obfuscate.h"

#include "Utils.h"
#include "Logger.h"
#include "KittyMemory/MemoryPatch.h"
#include "json.hpp"
#include "autoaddr.h"

#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/system_properties.h>
#include <dlfcn.h>

#include "KittyMemory/MemoryPatch.h"

#include <dlfcn.h>
#include <cstdlib>
#include <cinttypes>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include "imgui.h"
#include "imgui_internal.h"

#include <pthread.h>

#include "zygisk.hpp"

#include <sys/system_properties.h>

#define targetLibName OBFUSCATE("libil2cpp.so")

JavaVM* publicVM;
JNIEnv* publicEnv;

#include <EGL/egl.h>
#include <GLES2/gl2.h>

uintptr_t address = 0;

int page = 1;

void cmdExecuteSystem(const char* input){
    printf("%s", input);
}

#include <stdlib.h>

typedef unsigned int uint;

char* data;
#define S(data)

static char buf[500];
static const char* buf1;

std::string f777 = OBFUSCATE("libil2cpp.so");
const char *libNames = f777.c_str();

#include <iostream>
#include <iomanip>
#include <sstream>

bool radarbool;

struct My_Patches {
    MemoryPatch RadarHack;
} hexPatches;

void offsets_load() {
 
  hexPatches.RadarHack = MemoryPatch::createWithHex(targetLibName, 0x140B390, OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
  hexPatches.RadarHack.Modify();
  
pthread_exit(nullptr);
}

