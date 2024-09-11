#ifndef ZITA_EXPORT_H
#define ZITA_EXPORT_H

// Detect if we are building on Windows
#if defined(_WIN32) || defined(_WIN64)
  #if defined(ZITA_BUILD)
    // When building the DLL on Windows, use __declspec(dllexport)
    #define ZITA_EXPORT __declspec(dllexport)
  #else
    // When using the DLL on Windows, use __declspec(dllimport)
    #define ZITA_EXPORT __declspec(dllimport)
  #endif
#else
  #if defined(__GNUC__) || defined(__clang__)
    // For GCC/Clang, use __attribute__((visibility("default")))
    #define ZITA_EXPORT __attribute__((visibility("default")))
  #else
    // For other compilers, leave it empty (symbol visibility is default)
    #define ZITA_EXPORT
  #endif
#endif

#endif