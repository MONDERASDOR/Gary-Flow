#ifndef LOG_H
#define LOG_H
#include <stdio.h>

#define LOG_INFO(msg, ...) printf("[INFO] " msg "\n", ##__VA_ARGS__)
#define LOG_WARN(msg, ...) printf("[WARN] " msg "\n", ##__VA_ARGS__)
#define LOG_ERROR(msg, ...) fprintf(stderr, "[ERROR] " msg "\n", ##__VA_ARGS__)

#endif // LOG_H
