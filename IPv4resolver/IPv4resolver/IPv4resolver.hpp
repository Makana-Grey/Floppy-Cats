#include <string>

#pragma once

#ifdef IPV4RESOLVER_EXPORTS
#define IPV4RESOLVER_API __declspec(dllexport)
#else
#define IPV4RESOLVER_API __declspec(dllimport)
#endif

extern IPV4RESOLVER_API const std::string resolveIPv4(const std::string hostname, const std::string port);