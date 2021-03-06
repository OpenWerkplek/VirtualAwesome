/*
* Copyright 2009 NOR_/D Labs <http://labs.nortd.com>
*
* This file is part of VirtualAwesome.
* VirtualAwesome is free software: you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License 
* as published by the Free Software Foundation, either version 3 of 
* the License, or (at your option) any later version. For details
* see <http://www.gnu.org/licenses/>.
*
* Ported from Damian Stewart's ofxOsc library
* Thanks Damian for open sourcing!
*
* * *
* 
*/

#ifndef VAOSC_ARG
#define VAOSC_ARG

#include <string>
#include <va/Constants.h>

namespace vaOsc {


enum ArgType {
	TYPE_NONE = 0,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_STRING,
	TYPE_BLOB,
	TYPE_BUNDLE,
	TYPE_INDEXOUTOFBOUNDS
};


#if defined TARGET_WIN32 && defined _MSC_VER
// required because MSVC isn't ANSI-C compliant
typedef long int32_t;
#endif


class Arg {
  public:
    Arg() {};
    virtual ~Arg() {};

    virtual ArgType getType() { return TYPE_NONE; }
    virtual std::string getTypeName() { return "none"; }
};


class ArgInt32 : public Arg {
  public:
	ArgInt32( int32_t _value ) {value = _value;}
	~ArgInt32() {};

	ArgType getType() {return TYPE_INT;}
	std::string getTypeName() {return "int";}

	int32_t get() const {return value;}
	void set( int32_t _value ) {value = _value;}

  protected:
	int32_t value;
};


class ArgFloat : public Arg {
  public:
	ArgFloat( float _value ) {value = _value;}
	~ArgFloat() {};

	ArgType getType() {return TYPE_FLOAT;}
	std::string getTypeName() {return "float";}

	float get() const {return value;}
	void set( float _value ) {value = _value;}

  protected:
    float value;
};


class ArgString : public Arg {
  public:
	ArgString( std::string _value ) {value = _value;}
	~ArgString() {};

	ArgType getType() {return TYPE_STRING;}
	std::string getTypeName() {return "string";}

	std::string get() const {return value;}
	void set( const char* _value ) {value = _value;}

  protected:
	std::string value;
};


}
#endif

