#ifndef _GFX_BARRIER_H_
#define _GFX_BARRIER_H_

//#include <vjConfig.h>
#include <Threads/CondVar.h>
#include <Threads/Mutex.h>
#include <Threads/Guard.h>


//---------------------------------------------------------------------
//: Helper class for Barrier
//---------------------------------------------------------------------
class SubBarrier
{
public:
    // ------------------------------------------------------------------------
    //: Initialization.
    // ------------------------------------------------------------------------
    SubBarrier (int count, Mutex* lock) : barrierFinished(lock),
                                              runningThreads(count)
    {}

    CondVar barrierFinished;   // True if this generation of the barrier is done.

    int runningThreads;  //: Number of threads that are still running.

    // ------------------------------------------------------------------------
    //: Dump the state of an object.
    // ------------------------------------------------------------------------
    void dump (void)
    {
        std::cerr << "SubBarrier::dump" << std::endl;
        this->barrierFinished.dump();
    }
};

//---------------------------------------------------------------------
//: Implements "barrier synchronization".
//
//     This class allows <count> number of threads to synchronize
//     their completion (so-called "barrier synchronization").  The
//     implementation uses a "sub-barrier generation numbering"
//     scheme to avoid overhead and to ensure that all threads exit
//     the barrier correct.  This code is based on an article from
//     SunOpsis Vol. 4, No. 1 by Richard Marejka
//     (Richard.Marejka@canada.sun.com).
//!PUBLIC_API:
//---------------------------------------------------------------------
class Barrier
{
public:
    // ------------------------------------------------------------------------
    //: Initialize the barrier to synchronize <count> threads.
    // ------------------------------------------------------------------------
    Barrier (int count) : currentGeneration(0),
        count(count),
        subBarrier1(count, &mutex),
        subBarrier2(count, &mutex)
    {
        //std::cerr << "Barrier::Barrier: Entering." << std::endl;
        subBarrier[0] = &subBarrier1;
        subBarrier[1] = &subBarrier2;
    }

    // -----------------------------------------------------------------------
    //: Block the caller until all <count> threads have called <wait> and
    //+ then allow all the caller threads to continue in parallel.
    // -----------------------------------------------------------------------
    int wait(void);

    // -----------------------------------------------------------------------
    //: Tell the barrier to increase the count of the number of threads to
    //+ syncronize.
    // -----------------------------------------------------------------------
    void addProcess()
    {
        std::cerr << "Barrier::addProcess: Not implemented yet."
                  << std::endl;
    }

    // -----------------------------------------------------------------------
    //: Tell the barrier to decrease the count of the number of threads to
    //+ syncronize.
    // -----------------------------------------------------------------------
    void removeProcess()
    {
        std::cerr << "Barrier::removeProcess: Not implemented yet."
                  << std::endl;
    }

    // -----------------------------------------------------------------------
    //: Dump the state of an object.
    // -----------------------------------------------------------------------
    void dump (void) const {}

private:
    Mutex mutex;   // Serialize access to the barrier state.

    // Either 0 or 1, depending on whether we are the first generation
    // of waiters or the next generation of waiters.
    int currentGeneration;


    int count; // Total number of threads that can be waiting at any one time.

    SubBarrier subBarrier1;
    SubBarrier subBarrier2;
    SubBarrier* subBarrier[2];
    // We keep two <sub_barriers>, one for the first "generation" of
    // waiters, and one for the next "generation" of waiters.  This
    // efficiently solves the problem of what to do if all the first
    // generation waiters don't leave the barrier before one of the
    // threads calls wait() again (i.e., starts up the next generation
    // barrier).

    // = Prevent assignment and initialization.
    void operator= (const Barrier &) {}
    Barrier (const Barrier &) : subBarrier1(0, &mutex), subBarrier2(0, &mutex)  {}
};

#endif

