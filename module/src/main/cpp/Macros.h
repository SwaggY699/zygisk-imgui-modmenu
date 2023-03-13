#ifndef HOOK_MACROS
#define HOOK_MACROS

//const char *unitylibName = OBFUSCATE("libunity.so");

#define HOOK(offset, ptr, orig) DobbyHook((void *)getAbsoluteAddress(libName, string2Offset(OBFUSCATE(offset))), (void *)ptr, (void **)&orig)
#define HOOK_LIB(lib, offset, ptr, orig) DobbyHook((void *)getAbsoluteAddress(OBFUSCATE(lib), string2Offset(OBFUSCATE(offset))), (void *)ptr, (void **)&orig)

//Obfuscate offset
#define OBFUSCATEOFFSET(str) string2Offset(OBFUSCATE(str)) //Encrypt offset

#endif //Macros For Hook
