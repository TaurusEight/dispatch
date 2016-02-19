// Time-stamp: <2016-02-19 14:51:49 dmendyke>
#ifndef __DISPATCH_HH__
#define __DISPATCH_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <map>  // std::map
#include <string>  // std::string
#include <functional>  // std::function
#include "node.hh"  // sample::node


// Project namespace
//-----------------------------------------------------------------------------
namespace sample {


  // Wrapper around a map object used as a dispatch table
  //---------------------------------------------------------------------------
  class dispatch_table {

  public:

    dispatch_table();
    virtual ~dispatch_table();

    void find( const std::string& );

  private:

    //    std::map< std::string, node_ptr > map_;
    std::map< std::string, std::function< node_ptr() > > map_;

  };  // end class dispatch_table


};  // end project NS



#endif  // __DISPATCH_HH__
