/**
 * \file Dump.h
 *
 * \ingroup Sucker
 * 
 * \brief Class def header for a class Dump
 *
 * @author vgenty
 */

/** \addtogroup Sucker

    @{*/

#ifndef LARLITE_DUMP_H
#define LARLITE_DUMP_H

#include "Analysis/ana_base.h"
#include <fstream>
namespace larlite {
  /**
     \class Dump
     User custom analysis class made by SHELL_USER_NAME
   */
  class Dump : public ana_base{
  
  public:

    /// Default constructor
    Dump(){ _name="Dump"; _fout=0;}

    /// Default destructor
    virtual ~Dump(){}

    /** IMPLEMENT in Dump.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in Dump.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in Dump.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

  private:
    std::ofstream _ofile;    
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
