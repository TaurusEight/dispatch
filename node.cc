// Time-stamp: <2016-02-19 15:41:34 dmendyke>


//
// node.cc:  Defines each type of command
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cerr
#include <sstream>  // std::stringstream
#include "node.hh"  // sample::node


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace sample;  // project namespace


// constructor
//-----------------------------------------------------------------------------
node::node( ) {
};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
node::~node() {
};  // end destructor


// Output this node to the stream
//-----------------------------------------------------------------------------
ostream& sample::operator<<( ostream& out, const node& obj ) {

  out << obj.to_string();
  return out;

};  // end operator<< node


// Constructor
//-----------------------------------------------------------------------------
one::one( ) : node( ), value(), answer() {
};  // end one


// Parse values from command 'one'
//-----------------------------------------------------------------------------
void one::parse( const string& line ) {

  stringstream stream( line );

  stream >> value >> answer;

};  // end one::parse


// Output this node to the stream
//-----------------------------------------------------------------------------
string one::to_string( ) const {

  stringstream stream;

  stream << "This node is of type 'one'.  It has an int value ("
      << value << ") and an answer (" << answer << ").";

  return stream.str();

};  // end operator<< one


// Constructor
//-----------------------------------------------------------------------------
two::two( ) : node( ), value(), color() {
};  // end two


// Parse values from command 'two'
//-----------------------------------------------------------------------------
void two::parse( const string& line ) {

  stringstream stream( line );

  stream >> value >> color;

};  // end two::parse


// Convert this node into a string
//-----------------------------------------------------------------------------
string two::to_string( ) const {

  stringstream stream;

  stream << "This node is of type 'two'.  It has a float value ("
      << value << ") and a color (" << color << ").";

  return stream.str();

};  // end two::to_string
