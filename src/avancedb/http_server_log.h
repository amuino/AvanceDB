/*
 *  AvanceDB - an in-memory database similar to Apache CouchDB
 *  Copyright (C) 2015-2017 Ripcord Software
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RS_AVANCEDB_HTTP_SERVER_LOG_H
#define RS_AVANCEDB_HTTP_SERVER_LOG_H

#include "libhttpserver.h"

#include <ctime>

class HttpServerLog final {            
public:

    HttpServerLog() = delete;
    HttpServerLog(const HttpServerLog&) = delete;
    HttpServerLog& operator=(const HttpServerLog&) = delete;    
    
    static void Append(rs::httpserver::socket_ptr socket, rs::httpserver::request_ptr request, rs::httpserver::response_ptr response, const std::time_t& start, long duration);
    
    static void GetTimestamp(std::time_t time, int& year, int& month, int& day, int& hour, int& min, int& sec);
    
private:

    static void GetYear(std::time_t time, int startYear, std::time_t startOffset, int& year, std::time_t& offset, bool& isLeap);
    static unsigned GetMonth(long elapsedSeconds, bool isLeap);
    static unsigned GetDay(long elapsedSeconds, unsigned month, bool isLeap);    

};

#endif /* RS_AVANCEDB_HTTP_SERVER_LOG_H */

