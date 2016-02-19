// Time-stamp: <2016-02-19 11:50:25 dmendyke>
#ifndef __APPLICATION_HH__
#define __APPLICATION_HH__


// Required header files
//-----------------------------------------------------------------------------
#include "dispatch.hh"  // sample::dispatch_table


// Project NS
//-----------------------------------------------------------------------------
namespace sample {

  // Main object of app
  //---------------------------------------------------------------------------
  class application {

  public:

    application();
    virtual ~application();

    int run();  // start the show

  private:

    sample::dispatch_table table_;

  };  // end class application


};  // end project NS



#endif  // __APPLICATION_HH__
