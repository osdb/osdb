/*************************************************************************
 * This file is part of OSDB.                                            *
 *                                                                       *
 * OSDB is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * OSDB is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with OSDB.  If not, see <http://www.gnu.org/licenses/>.         *
 *************************************************************************/

#include "Timer.h"

Timer::Timer() {
}

Timer::~Timer() {
}

void Timer::startTimer() {
#ifdef HAVE_GETTIMEOFDAY
	struct timeval tv;
	gettimeofday(&tv, NULL);
	startTime = tv.tv_sec;
	startTime += tv.tv_usec / 1000000.0;
#else
	startTime = time(NULL);
#endif
}

double Timer::stopTimer() {
	double stopTime;
#ifdef HAVE_GETTIMEOFDAY
	struct timeval tv;
	gettimeofday(&tv, NULL);
	stopTime = tv.tv_sec;
	stopTime += tv.tv_usec / 1000000.0;
#else
	stopTime = time(NULL);
#endif
	return (stopTime - startTime);
}

