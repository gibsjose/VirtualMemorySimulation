#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>
#include <string.h>
#include <errno.h>



class Exception : public std::runtime_error {
public:
    Exception() : std::runtime_error("Unknown Exception") {}

    virtual ~Exception() throw() {}

    virtual const char * what() const throw() {
        return "Exception: Unknown Exception";
    }

private:
    std::string message;
    std::string className;
    std::string methodName;
    std::string fileName;
    unsigned int lineNumber;
};

class GeneralException : public Exception {
public:
    GeneralException(const std::string & message) : Exception() {
        this->message = message;
    }

    ~GeneralException() throw() {}

    const char * what() const throw() {
        std::string tmp;

        tmp = "---> GeneralException: " + message;

        return tmp.c_str();
    }

private:
    std::string message;
};

class SocketException : public Exception {
public:
    SocketException(const std::string & message) : Exception() {
        this->message = message;
    }

    ~SocketException() throw() {}

    const char * what() const throw() {
        std::string tmp;

        tmp = "---> SocketException: " + message + ": errno: " + strerror(errno);

        return tmp.c_str();
    }

private:
    std::string message;
};


class FileIOException : public Exception {
public:
    FileIOException(const std::string & filename, const std::string & message) : Exception() {
        this->filename = filename;
        this->message = message;
    }

    FileIOException(const std::string & message) : Exception() {
        this->filename.clear();
        this->message = message;
    }

    ~FileIOException() throw() {}

    const char * what() const throw() {
        std::string tmp;
        if(!filename.empty()) {
            tmp = "---> FileIOException: Make sure file \"" + filename + "\" exists and has read permissions: " + message;
        } else {
            tmp = "---> FileIOException: Make sure file exists and has read permissions: " + message;
        }

        return tmp.c_str();
    }

private:
    std::string filename;
    std::string message;
};

class ParseException : public Exception {
public:
    ParseException(const std::string & message) : Exception() {
        this->filename.clear();
        this->message = message;
    }

    ParseException(const std::string & filename, const std::string & message) : Exception() {
        this->filename = filename;
        this->message = message;
    }

    ~ParseException() throw() {}

    const char * what() const throw() {
        std::string tmp;

        if(filename.empty()) {
            tmp = "---> ParseException: " + message;
        } else {
            tmp = "---> ParseException: File: " + filename + ": " + message;
        }

        return tmp.c_str();
    }

private:
    std::string filename;
    std::string message;
};

class OutOfRangeException : public Exception {
public:
    OutOfRangeException(int bottom, int top, int val, const std::string & message) : Exception() {
        this->bottom = bottom;
        this->top = top;
        this->val = val;
        this->message = message;
    }

    OutOfRangeException(int top, int val, const std::string & message) : Exception() {
        this->bottom = 0;
        this->top = top;
        this->val = val;
        this->message = message;
    }

    ~OutOfRangeException() throw() {}

    const char * what() const throw() {

        std::ostringstream s;
        s << "---> OutOfRangeException: Value: " << val << " outside of range: " << bottom << " <--> " << top << ": " << message;

        return s.str().c_str();
    }

private:
    int bottom;
    int top;
    int val;
    std::string message;
};

class TTLExpiredException : public Exception {
public:
    TTLExpiredException(const std::string & message) : Exception() {
        this->message = message;
    }

    ~TTLExpiredException() throw() {}

    const char * what() const throw() {
        std::string tmp;

        tmp = "---> TTLExpiredException: " + message;

        return tmp.c_str();
    }

private:
    std::string message;
};

#endif
