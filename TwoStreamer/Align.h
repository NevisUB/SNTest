/**
 * \file Align.h
 *
 * \ingroup TwoStreamer
 * 
 * \brief Class def header for a class Align
 *
 * @author vgenty
 */

/** \addtogroup TwoStreamer

    @{*/

#ifndef LARLITE_ALIGN_H
#define LARLITE_ALIGN_H

#include "Analysis/ana_base.h"

namespace larlite {
  /**
     \class Align
     User custom analysis class made by SHELL_USER_NAME
   */
  class Align : public ana_base{
  
  public:

    /// Default constructor
    Align(){ _name="Align"; _fout=0;}

    /// Default destructor
    virtual ~Align(){}

    /** IMPLEMENT in Align.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in Align.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in Align.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

  protected:
    
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
