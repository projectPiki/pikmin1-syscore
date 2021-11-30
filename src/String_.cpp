#include <String_.h>

// TODO
String::String() { }

String::String(int len) { }

String::String(char* str, int len) { }

int String::toInt() { return 0; }

void String::init(int len) { }

void String::init(char* str, int len) { }

void String::init(char* str) { }

u32 String::calcHash() { return u32(); }

u32 String::calcHash(char* str) { return u32(); }

u32 String::getLength() { return u32(); }

u32 String::getLength(char* str) { return u32(); }

char* String::dup() { return nullptr; }

char* String::dup(char* str) { return nullptr; }

bool String::isSame(char* str) { return false; }

bool String::isSame(String* str) { return false; }

bool String::contains(char* str) { return false; }

void String::concat(char* a1, char* a2) { }

char* String::copy(char* a1, char* a2) { return nullptr; }

bool String::isSame(char* a1, char* a2) { return false; }

bool String::isWhiteSpace(char letter) { return false; }

bool String::copyUntil(char*, char*, char, char**) { return false; }

bool String::equals(char*, char*) { return false; }

bool String::contains(char*, char*) { return false; }

bool String::contains(char*, char) { return false; }
