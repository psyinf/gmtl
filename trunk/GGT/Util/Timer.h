/*
 * VRJuggler
 *   Copyright (C) 1997,1998,1999,2000
 *   Iowa State University Research Foundation, Inc.
 *   All Rights Reserved
 *
 * Original Authors:
 *   Allen Bierbaum, Christopher Just,
 *   Patrick Hartling, Kevin Meinert,
 *   Carolina Cruz-Neira, Albert Baker
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: Timer.h,v $
 * Date modified: $Date: 2002-01-18 20:43:10 $
 * Version:       $Revision: 1.1.1.1 $
 * -----------------------------------------------------------------
 */

#ifndef _VJ_TIMER_H_
#define _VJ_TIMER_H_

#ifndef WIN32
#include <sys/time.h>
#endif

//: Simple class to take timings and give averages
// NOTE: All times are in seconds
// XXX: Should use vjTimeStamp for the time info in the future
class vjTimer
{
public:
	vjTimer()
	{
		totalTime = 0;
		timeCount = 0;
		startTime = 0;
		endTime = 0;
	}
	
	//: Start a timing
	void startTiming()
	{ startTime = wallclock(); }
	
	//: Stop current timing
	//! PRE: Timing has been started
	void stopTiming()
	{ 
		endTime = wallclock();
		if (startTime == 0)	// If we haven't called start then ignore
		{ totalTime = 0; }
		else
		{
		    lastTiming = (endTime - startTime);
		    totalTime += lastTiming;
		    timeCount++;
		}
	}

	// Get the average timing
	double getTiming()
	{ return (totalTime/(double)timeCount); }

	double getLastTiming()
	{ return lastTiming; }
	
	//: Returns the number of timings collected
	long getTimeCount()
	{ return timeCount; }
	
	void reset()
	{
	    totalTime = 0;
	    timeCount = 0;
	    startTime = 0;
	    endTime = 0;
	}   
    
#ifdef WIN32
   double wallclock()
   {
   	return ((double)GetTickCount())/1000.0f;
   }
#else
   double wallclock()
   {
       double v;
       struct timeval tv;
   
       gettimeofday(&tv, 0);
   
       v = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
       return v;
   }
#endif

private:		// Timing stuff
	double  startTime;	    // The times
	double  endTime;
	double  lastTiming;		 // The last timing recieved
	double  totalTime;	    // The total time
	long    timeCount;	    // The count on the number of times	
};

#endif 
