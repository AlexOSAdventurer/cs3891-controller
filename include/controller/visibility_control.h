#ifndef CONTROLLER__VISIBILITY_CONTROL_H_
#define CONTROLLER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CONTROLLER_EXPORT __attribute__ ((dllexport))
    #define CONTROLLER_IMPORT __attribute__ ((dllimport))
  #else
    #define CONTROLLER_EXPORT __declspec(dllexport)
    #define CONTROLLER_IMPORT __declspec(dllimport)
  #endif
  #ifdef CONTROLLER_BUILDING_LIBRARY
    #define CONTROLLER_PUBLIC CONTROLLER_EXPORT
  #else
    #define CONTROLLER_PUBLIC CONTROLLER_IMPORT
  #endif
  #define CONTROLLER_PUBLIC_TYPE CONTROLLER_PUBLIC
  #define CONTROLLER_LOCAL
#else
  #define CONTROLLER_EXPORT __attribute__ ((visibility("default")))
  #define CONTROLLER_IMPORT
  #if __GNUC__ >= 4
    #define CONTROLLER_PUBLIC __attribute__ ((visibility("default")))
    #define CONTROLLER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CONTROLLER_PUBLIC
    #define CONTROLLER_LOCAL
  #endif
  #define CONTROLLER_PUBLIC_TYPE
#endif
#endif  // CONTROLLER__VISIBILITY_CONTROL_H_
// Generated 30-Nov-2023 13:09:18
// Copyright 2019-2020 The MathWorks, Inc.
