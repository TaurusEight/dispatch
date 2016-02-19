// Time-stamp: <2016-02-19 15:50:56 dmendyke>


//
// application.cc:  main object of app
//


// required header files
//-----------------------------------------------------------------------------
#include <stdexcept>  // std::exception
#include <iostream>  // std::cerr
#include "application.hh"  // sample::application
#include "dispatch.hh"  // sample::dispatch_table


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace sample;  // project NS


// Constructor
//-----------------------------------------------------------------------------
application::application() : table_() {

};  // end application constructor



// Destructor
//-----------------------------------------------------------------------------
application::~application() {

};  // end destructor



// Run the app object
//-----------------------------------------------------------------------------
int application::run() {

  int result = 0x0;  // default to A-OK

  try {

    cerr << *table_.find( "one 1 no" ) << endl;
    cerr << *table_.find( "two 4.04 blue" ) << endl;
    cerr << *table_.find( "two 9.12 yellow" ) << endl;
    cerr << *table_.find( "one 88 yes" ) << endl;

  } catch( exception& except ) {

    cerr << "Error: " << except.what() << endl;
    result = -1;

  };  // end try / catch

  return result;

};  // end run
