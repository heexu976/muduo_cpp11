#pragma once
#include <stdio.h>
#include <string>


class FileUtil{
public:
    explicit FileUtil(std::string& fileName);
    ~FileUtil();

    void append(const char* daya, size_t len);

    void flush();

    off_t writtenBytes()const {return writtenBytes_;}

private:
    size_t write(const char* data, size_t len);
    FILE* fp_;
    char buffer[64 * 1024]; // fp的缓冲区
    off_t writtenBytes_; // off_t偏移量
};