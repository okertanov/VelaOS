/**
    @file       String.cpp
    @brief      String type wrapper implementation

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#include "Platform.h"
#include "String.h"

/*******************************************************************************
    Types
*******************************************************************************/
namespace Vela
{
    namespace Types
    {

        /**
            @fn Vela::Types::String::String()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String::String()
            : str_()
        {
        }

        /**
            @fn Vela::Types::String::String(const String& s)
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String::String(const String& s)
            : str_()
        {
            str_ = s.Str();
        }

        /**
            @fn Vela::Types::String::String(const StringType& s)
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String::String(const StringType& s)
            : str_()
        {
            str_ = s;
        }

        /**
            @fn Vela::Types::String::String(const char* s)
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String::String(const char* s)
            : str_()
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            str_ = s;
            #else
            str_ = const_cast<StringType>(s);
            #endif
        }

       /**
            @fn Vela::Types::String::~String()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String::~String()
        {
        }

        /**
            @fn Vela::Types::String::Str()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        const String::StringType& String::Str() const
        {
            return str_;
        }

        /**
            @fn Vela::Types::String::CStr()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        const char* String::CStr() const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return str_.c_str();
            #else
            return str_;
            #endif
        }

        /**
            @fn Vela::Types::String::Empty()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        bool String::Empty() const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return const_cast<String::StringType&>(Str()).empty();
            #else
            #warning "Not implemented for this toolchain."
            return true;
            #endif
        }

        /**
            @fn Vela::Types::String::Length()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        size_t String::Length() const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return const_cast<String::StringType&>(Str()).length();
            #else
            #warning "Not implemented for this toolchain."
            return 0;
            #endif
        }

        /**
            @fn Vela::Types::String::Clear()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void String::Clear()
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()).clear();
            #else
            #warning "Not implemented for this toolchain."
            #endif
        }

        /**
            @fn Vela::Types::String::Find()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        size_t String::Find(const String& s, size_t pos) const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return Str().find(s.Str(), pos);
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(s), UNUSED(pos);
            return 0;
            #endif
        }

        /**
            @fn Vela::Types::String::Replace()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String& String::Replace(size_t pos1, size_t n1, const String& s)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()).replace(pos1, n1, s);
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(pos1), UNUSED(n1), UNUSED(s);
            #endif

            return *this;
        }

        /**
            @fn Vela::Types::String::Swap()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void String::Swap(String& s)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()).swap(const_cast<String::StringType&>(s.Str()));
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(s);
            #endif
        }

        /**
            @fn Vela::Types::String::operator char*()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String::operator char*() const
        {
            return const_cast<char*>(CStr());
        }

        /**
            @fn Vela::Types::String::operator char*()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String::operator const char*() const
        {
            return CStr();
        }

        /**
            @fn Vela::Types::String::operator=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String& String::operator= (const String &s)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()).assign(s.Str());
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(s);
            #endif

            return *this;
        }

        /**
            @fn Vela::Types::String::operator=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String& String::operator= (const char* s)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()).assign(s);
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(s);
            #endif

            return *this;
        }

        /**
            @fn Vela::Types::String::operator=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String& String::operator= (char c)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()) = c;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(c);
            #endif

            return *this;
        }

        /**
            @fn Vela::Types::String::operator+=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String& String::operator+= (const String& s)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()) += s.Str();
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(s);
            #endif

            return *this;
        }

        /**
            @fn Vela::Types::String::operator+=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String& String::operator+= (const char* s)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()) += s;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(s);
            #endif

            return *this;
        }

        /**
            @fn Vela::Types::String::operator+=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String& String::operator+= (char c)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const_cast<String::StringType&>(Str()) += c;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(c);
            #endif

            return *this;
        }

        /**
            @fn Vela::Types::String::operator[]
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        const char& String::operator[] (size_t pos) const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return Str().at(pos);
            #else
            return CStr()[pos];
            #endif
        }

        /**
            @fn Vela::Types::String::operator[]
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        char& String::operator[] (size_t pos)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return const_cast<String::StringType&>(Str()).at(pos);
            #else
            return const_cast<String::StringType>(CStr())[pos];
            #endif
        }

        /**
            @fn Vela::Types::String::operator()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String String::operator() (size_t pos, size_t npos) const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return String(const_cast<String::StringType&>(Str()).substr(pos, npos));
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(pos), UNUSED(npos);
            return String();
            #endif
        }

        /**
            @fn operator<<
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        std::ostream& operator<< (std::ostream& os, const String & s)
        {
            os << s.Str();
            return os;
        }
        #endif

        /**
            @fn operator>>
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        std::istream& operator>> (std::istream& is, String& s)
        {
            is >> const_cast<String::StringType&>(s.Str());
            return is;
        }
        #endif

        /**
            @fn operator+
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String operator+ (const String& lhs, const String& rhs)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return String(lhs.Str() + rhs.Str());
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return String();
            #endif
        }

        /**
            @fn operator+
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String operator+ (const char* lhs, const String& rhs)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs + rhs.Str();
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return String();
            #endif
        }

        /**
            @fn operator+
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String operator+ (char lhs, const String& rhs)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs + rhs.Str();
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return String();
            #endif
        }

        /**
            @fn operator+
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String operator+ (const String& lhs, const char* rhs)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs.Str() + rhs;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return String();
            #endif
        }

        /**
            @fn operator+
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        String operator+ (const String& lhs, char rhs)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs.Str() + rhs;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return String();
            #endif
        }

        /**
            @fn operator==
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        bool operator== ( const String& lhs, const String& rhs )
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs.Str() == rhs.Str();
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return false;
            #endif
        }

        /**
            @fn operator==
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        bool operator== ( const char* lhs, const String& rhs )
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return rhs.Str() == lhs;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return false;
            #endif
        }

        /**
            @fn operator==
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        bool operator== ( const String& lhs, const char* rhs )
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs.Str() == rhs;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return false;
            #endif
        }

        /**
            @fn operator!=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        bool operator!= ( const String& lhs, const String& rhs )
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs.Str() != rhs.Str();
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return true;
            #endif
        }

        /**
            @fn operator!=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        bool operator!= ( const char* lhs, const String& rhs )
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return rhs.Str() != lhs;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return true;
            #endif
        }

        /**
            @fn operator!=
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        bool operator!= ( const String& lhs, const char* rhs )
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            return lhs.Str() != rhs;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(lhs), UNUSED(rhs);
            return true;
            #endif
        }

    }
}

