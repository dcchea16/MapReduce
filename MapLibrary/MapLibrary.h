#pragma once

#ifdef MAPLIBRARY_EXPORTS
#define MAPLIBRARY_API __declspec(dllexport)
#else
#define MAPLIBRARY_API __declspec(dllimport)
#endif

#include <vector>
#include <string>
#include <unordered_map>

//// C-compatible API functions
//extern "C" MAPLIBRARY_API Map * Map_Create();
//extern "C" MAPLIBRARY_API void Map_Destroy(Map * map);
//extern "C" MAPLIBRARY_API void Map_Map(Map * map, const char* key, const char* value);
//extern "C" MAPLIBRARY_API void Map_FlushBuffer(Map * map);
//extern "C" MAPLIBRARY_API void Map_Test();

// Actual Map class is only used internally and is not exposed
extern "C" MAPLIBRARY_API class Map {
public:
    Map();
    void map(const std::string& key, const std::string& value);
    void flushBuffer();
    void map_test();
private:
    void exportToFile();
    std::unordered_map<std::string, int> wordCount;
    std::string fileName;
    int bufferCount = 0;
    const int bufferThreshold = 100;  // Example threshold
};