// Time-stamp: <2016-02-19 15:25:20 dmendyke>
#ifndef __NODE_HH__
#define __NODE_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <string>  // std::string
#include <memory>  // std::unique_ptr
#include <iostream>  // std::ostream


// Project NS
//-----------------------------------------------------------------------------
namespace sample {


  // Base command
  struct node {

    node( );  // normal constructor
    node( const node& );  // copy constructor
    virtual ~node();  // destructor
    virtual void parse( const std::string& ) = 0;  // pure virtual
    virtual std::string to_string() const = 0;  // another pure virtual

  };  // end node


  // Out put this node to the stream
  //---------------------------------------------------------------------------
  std::ostream& operator<<( std::ostream&, const node& );


  // Define a new type - short hand - to a smart pointer
  //---------------------------------------------------------------------------
  typedef std::unique_ptr< node > node_ptr;


  // This node store an in and an answer
  //---------------------------------------------------------------------------
  struct one : node {

    one( );
    void parse( const std::string& );
    std::string to_string() const;
    int value;
    std::string answer;

  };  // end one


  // This node stores a float and and answer
  //---------------------------------------------------------------------------
  struct two : node {

    two( );
    void parse( const std::string& );
    std::string to_string() const;
    float value;
    std::string color;

  };  // end two


};  // end project NS

#endif  // __NODE_HH__
