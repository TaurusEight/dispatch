// Time-stamp:  <2016-02-19 15:48:54 dmendyke>


//
// dispatch_table.cc:  wrapper around a map
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cerr
#include <memory>  // std::unique_ptr
#include "dispatch.hh"  // sample::dispatch_table


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace sample;  // project NS


// Constructor
//-----------------------------------------------------------------------------
dispatch_table::dispatch_table() : map_( ) {

  map_[ "one" ] = [](){ return node_ptr( new sample::one ); };
  map_[ "two" ] = [](){ return node_ptr( new sample::two ); };

};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
dispatch_table::~dispatch_table() {
};  // end destructor


// Find the command in the table
//-----------------------------------------------------------------------------
node_ptr dispatch_table::find( const string& line ) {

  string command( line.substr( 0x0, 0x3 ) );
  node_ptr ptr( map_[ command ]() );

  ptr->parse( line.substr( command.size() ) );
  return ptr;

};  // end find
