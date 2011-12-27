/**
    @file       String.h
    @brief      String type wrapper

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

/*******************************************************************************
    Types Includes
*******************************************************************************/
#include "String.h"

/*******************************************************************************
    Types
*******************************************************************************/
namespace Vela
{
    namespace Types
    {
        /**
            @class Vela::Types::String
            @brief String class
        */
        class String :
            public ABI::Runtime
        {
            public:
                /**
                    @typedef Vela::Types::StringType
                    @brief
                */
                #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
                    typedef std::string StringType;
                #elif defined(TARGET_EMBEDDED) || defined(TARGET_STM32)
                    typedef char*       StringType;
                #endif

                /**
                    @fn Vela::Types::String::String()
                */
                String();

                /**
                    @fn Vela::Types::String::String()
                */
                String(const String& s);

                /**
                    @fn Vela::Types::String::String()
                */
                String(const StringType& s);

                /**
                    @fn Vela::Types::String::String()
                */
                String(const char* s);

                /**
                    @fn Vela::Types::String::String()
                */
                template <typename T>
                String(T const& t)
                    : str_()
                {
                    #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
                    std::stringstream stream;
                    stream << t;
                    str_ = stream.str();
                    #else
                    #warning "Not implemented for this toolchain."
                    UNUSED(t);
                    #endif
                }

                /**
                    @fn Vela::Types::String::~String()
                */
                virtual ~String();

                /**
                    @fn Vela::Types::String::Str()
                */
                const StringType& Str() const;

                /**
                    @fn Vela::Types::String::CStr()
                */
                const char* CStr() const;

                /**
                    @fn Vela::Types::String::Empty()
                */
                bool Empty() const;

                /**
                    @fn Vela::Types::String::Length()
                */
                size_t Length() const;

                /**
                    @fn Vela::Types::String::Clear()
                */
                void Clear();

                /**
                    @fn Vela::Types::String::Find()
                */
                size_t Find(const String& s, size_t pos = 0) const;

                /**
                    @fn Vela::Types::String::Replace()
                */
                String& Replace(size_t pos1, size_t n1, const String& s);

                /**
                    @fn Vela::Types::String::Swap()
                */
                void Swap(String& s);

                /**
                    @fn Vela::Types::String::operator char*()
                */
                operator char*() const;

                /**
                    @fn Vela::Types::String::operator const char*()
                */
                operator const char*() const;

                /**
                    @fn Vela::Types::String::operator=
                */
                String& operator= (const String &s);

                /**
                    @fn Vela::Types::String::operator=
                */
                String& operator= (const char* s);

                /**
                    @fn Vela::Types::String::operator=
                */
                String& operator= (char c);

                /**
                    @fn Vela::Types::String::operator+=
                */
                String& operator+= (const String& s);

                /**
                    @fn Vela::Types::String::operator+=
                */
                String& operator+= (const char* s);

                /**
                    @fn Vela::Types::String::operator+=
                */
                String& operator+= (char c);

                /**
                    @fn Vela::Types::String::operator[]
                */
                const char& operator[] (size_t pos) const;

                /**
                    @fn Vela::Types::String::operator[]
                */
                char& operator[] (size_t pos);

                /**
                    @fn Vela::Types::String::operator()
                */
                String operator() (size_t pos, size_t npos) const;

            private:
                /**
                    @property Vela::Types::String::str_
                */
                mutable StringType str_;
        };

        /**
            @fn operator<<
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        std::ostream& operator<< (std::ostream& os, const String& s);
        #else
        #warning "Not implemented for this toolchain."
        #endif

        /**
            @fn operator>>
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        std::istream& operator>> (std::istream& is, String& s);
        #else
        #warning "Not implemented for this toolchain."
        #endif

        /**
            @fn operator+
        */
        String operator+ (const String& lhs, const String& rhs);

        /**
            @fn operator+
        */
        String operator+ (const char* lhs, const String& rhs);

        /**
            @fn operator+
        */
        String operator+ (char lhs, const String& rhs);

        /**
            @fn operator+
        */
        String operator+ (const String& lhs, const char* rhs);

        /**
            @fn operator+
        */
        String operator+ (const String& lhs, char rhs);

        /**
            @fn operator==
        */
        bool operator== ( const String& lhs, const String& rhs );

        /**
            @fn operator==
        */
        bool operator== ( const char* lhs, const String& rhs );

        /**
            @fn operator==
        */
        bool operator== ( const String& lhs, const char* rhs );

        /**
            @fn operator!=
        */
        bool operator!= ( const String& lhs, const String& rhs );

        /**
            @fn operator!=
        */
        bool operator!= ( const char* lhs, const String& rhs );

        /**
            @fn operator!=
        */
        bool operator!= ( const String& lhs, const char* rhs );

    }

    /**
        @typedef Vela::String
        @brief
    */
    typedef Vela::Types::String     String;
}

#endif /*STRING_H_INCLUDED*/

